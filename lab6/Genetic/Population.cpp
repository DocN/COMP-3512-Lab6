#include "Population.hpp"
#include "Cities.hpp"

using namespace std;

Population::Population() {
	generatePop();
	shortestTourInPopulation = 0;
}
void Population::generatePop() {
	Cities * newCityList = new Cities();
	newCityList->generateCities();
	for (int i = 0; i < POPULATION_SIZE; i++) {
		popList.push_back(copyCities(newCityList));
	}
}

void Population::insertPop(Cities city) {
	popList.push_back(city);
}

void Population::printPopulation() {
	for (int i = 0; i < popList.size(); i++) {
		cout << "--------------------------------------------------" << endl;
		popList.at(i).printCities();
	}
}

void Population::shufflePop() {
	for (int i = 0; i < popList.size(); i++) {
		popList.at(i).shuffleCities();
	}
}

Cities Population::copyCities(Cities * masterList) {
	Cities * cityCopy = new Cities();
	std::vector<City> cityList = masterList->getCityList();
	for (int i = 0; i < cityList.size(); i++) {
		cityCopy->insertCity(cityList.at(i));
	}
	return *cityCopy;
}

void Population::setShortTourIndex(int _shortTourIndex) {
	shortTourIndex = _shortTourIndex;
}

int Population::getShortTourIndex() {
	return shortTourIndex;
}

void Population::setShortestTourInPopulation(double _shortestTourInPopulation) {
	shortestTourInPopulation = _shortestTourInPopulation;
}

double Population::getShortestTourInPopulation() {
	return shortestTourInPopulation;
}

std::vector<Cities> Population::getPopList() {
	return popList;
}

void Population::determine_fitness() {
	setShortTourIndex(0);
	shortestTourInPopulation = (double)RAND_MAX; // Begin by assuming distance is enormous
	double candidate_distance = 0;
	for (int i = 0; i < POPULATION_SIZE; i++) {
		candidate_distance = popList.at(i).get_tour_distance();
		popList.at(i).setFitness(FITNESS_SCALER / candidate_distance);
		if (candidate_distance <= shortestTourInPopulation) {
			shortTourIndex = i;
			shortestTourInPopulation = candidate_distance;
		}
	}
}

void Population::moveFittest() {
	Cities bestRoute = popList.at(shortTourIndex);
	popList.at(shortTourIndex) = popList.at(0);
	popList.at(0) = bestRoute;
}

Population * Population::select_parents() {
	Population * parents = new Population();
	Population * parentPool = new Population();
	int parent_index = 0;

	for (int i = 0; i < NUMBER_OF_PARENTS; i++) {
		for (int j = 0; j < PARENT_POOL_SIZE; j++) {
			int k = rand() % POPULATION_SIZE;
			parentPool->insertPop(popList.at(k));
		}
		parentPool->determine_fitness();
		parent_index = parentPool->getShortTourIndex();
		parents->insertPop(getPopList().at(parent_index));
	}
	return parents;
}

Cities * Population::crossover(Population * parents) {
	Cities * child = new Cities();
	int boundary_index = rand() % popList.at(0).CITIES_IN_TOUR;
	child->setFitness(0);

	for (int i = 0; i < boundary_index; i++) {
		child->insertCity(parents->getPopList().at(0).getCityList().at(i));
	}

	while (boundary_index < popList.at(0).CITIES_IN_TOUR) {
		for (int i = 0; i < popList.at(0).CITIES_IN_TOUR; i++) {
			if (!contains_city(child, boundary_index, parents->getPopList().at(1).getCityList().at(i))) {
				child->insertCity(parents->getPopList().at(1).getCityList().at(i));
				boundary_index++;
			}
		}
	}
	return child;
}

bool Population::contains_city(Cities * candidateTour, int length, City candidateCity) {
	for (int i = 0; i < length; i++) {
		City currentCity = candidateTour->getCityList().at(i);
		if (currentCity.getName() == candidateCity.getName() && currentCity.getX() == candidateCity.getX() && currentCity.getY() == candidateCity.getY()) {
			return true;
		}
	}
	return false;
}

void Population::iteration() {
	Population * crosses = new Population();
	for (int i = 0; i < ITERATIONS; i++) {
		moveFittest();
		for (int j = 0; j < (POPULATION_SIZE - NUMBER_OF_ELITES); j++) {
			Population * parents = select_parents();
			Cities * child = crossover(parents);
			crosses->insertPop(*child);
			delete(parents);
		}
		for (int i = NUMBER_OF_ELITES; i < POPULATION_SIZE; i++) {
			popList.at(i) = crosses->getPopList().at(i - NUMBER_OF_ELITES);
			popList.at(i).setFitness(0.00);
		}
		determine_fitness();
		double best_iteration_distance = getPopList().at(shortTourIndex).get_tour_distance();
		if (best_iteration_distance < shortestTourInPopulation) {
			shortestTourInPopulation = best_iteration_distance;
			cout << "New distance: " << best_iteration_distance << endl;
		}
	}

}

void Population::mutate() {
	double mutates = 0.0;
	for (int i = 0 + NUMBER_OF_ELITES; i < POPULATION_SIZE; i++) {
		for (int j = 0; j < getPopList().at(0).CITIES_IN_TOUR; j++) {
			mutates = (double)rand() / (double)RAND_MAX;
			if (mutates <= MUTATION_RATE) {
				int k = rand() % (getPopList().at(0).CITIES_IN_TOUR);
				getPopList().at(i).swapCities(j, k);
			}
		}
	}
}








