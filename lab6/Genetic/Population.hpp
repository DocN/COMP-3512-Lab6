#pragma once
#include <vector>
#include <iostream>
#include "Cities.hpp"
#include "City.hpp"

class Population {
private:
	static const int POPULATION_SIZE = 30;
	std::vector<Cities> popList;
	double shortestTourInPopulation;
	int shortTourIndex;
	double FITNESS_SCALER = 10000.0;
public:
	Population();
	void generatePop();
	void printPopulation();
	void shufflePop();
	void setShortTourIndex(int);
	int getShortTourIndex();
	void determine_fitness();
	void setShortestTourInPopulation(double);
	double getShortestTourInPopulation();
	Cities copyCities(Cities *);
	void moveFittest();
};