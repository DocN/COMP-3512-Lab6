#include "Cities.hpp"
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */

using namespace std;
Cities::Cities() {
	fitness = 0;
}

void Cities::setFitness(double _fitness) {
	fitness = _fitness;
}

double Cities::getFitness() {
	return fitness;
}
void Cities::insertCity(City currentCity) {
	cityList.push_back(currentCity);
}

void Cities::generateCities() {
	for (int i = 0; i < CITIES_IN_TOUR; i++) {
		City * currentCity = new City();
		while (checkCityExists(currentCity) == false) {
			delete(currentCity);
			currentCity = new City();
		}
		insertCity(*currentCity); 
	}
}

bool Cities::checkCityExists(City * checkCity) {
	for (int i = 0; i < cityList.size(); i++) {
		City currentCity = cityList.at(i);
		int curX = currentCity.getX();
		int curY = currentCity.getY();
		char curName = currentCity.getName();
		if (checkCity->getName() == curName) {
			return false;
		}
		else if (checkCity->getY() == curY && checkCity->getX() == curX) {
			return false;
		}
	}
	return true;
}
void Cities::printCities() {
	for (int i = 0; i < cityList.size(); i++) {
		cityList.at(i).printCity();
	}
}

std::vector<City> Cities::getCityList() {
	return cityList;
}

void::Cities::shuffleCities() {
	for (int i = 0; i < SHUFFLES; i++) {
		int index_one = rand() % CITIES_IN_TOUR;
		int index_two = rand() % CITIES_IN_TOUR;
		City firstCity = cityList.at(index_one);
		cityList.at(index_one) = cityList.at(index_two);
		cityList.at(index_two) = firstCity;
	}
}
double Cities::distance_between_cities(City a, City b) {
	return sqrt(pow((double)(a.getX() - b.getX()), 2.0) +
		pow((double)(a.getY() - b.getY()), 2.0));
}

double Cities::get_tour_distance() {
	int i = 0;
	double distance = 0.0;
	
	for (i = 0; i < CITIES_IN_TOUR; ++i) {
		distance +=
			distance_between_cities(getCityList().at(i), getCityList().at((i + 1) % CITIES_IN_TOUR));

	}

	return distance;
}



