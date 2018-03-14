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
	double FITNESS_SCALER = 10000.0;
	std::vector<Cities> popList;
	double shortestTourInPopulation;
	int shortTourIndex;

public:
	Population();
	void generatePop();
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
	Population * select_parents();
};