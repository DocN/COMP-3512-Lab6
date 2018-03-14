#pragma once
#include <vector>
#include <iostream>
#include "Cities.hpp"
#include "City.hpp"

class Population {
private:
	static const int POPULATION_SIZE = 30;
	static const int NUMBER_OF_ELITES = 1;
	static const int NUMBER_OF_PARENTS = 2;
	static const int PARENT_POOL_SIZE = 5;
	static const int ITERATIONS = 1000;
	double FITNESS_SCALER = 10000.0;
	std::vector<Cities> popList;
	double shortestTourInPopulation;
	int shortTourIndex;

public:
	Population();
	void generatePop();
	void insertPop(Cities);
	void printPopulation();
	void shufflePop();
	void setShortTourIndex(int);
	int getShortTourIndex();
	std::vector<Cities> getPopList();
	void determine_fitness();
	void setShortestTourInPopulation(double);
	double getShortestTourInPopulation();
	Cities copyCities(Cities *);
	void moveFittest();
	Population * iteration();
	Population * select_parents();
	Population * crossover(Population *);
};