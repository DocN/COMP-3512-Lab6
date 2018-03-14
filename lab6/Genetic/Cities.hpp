#pragma once
#include <vector>
#include <iostream>
#include "City.hpp"

class Cities {
private:
	std::vector<City> cityList;
	
	static const int SHUFFLES = 32;
	double fitness;

public:
	static const int CITIES_IN_TOUR = 20;

	Cities();
	void setFitness(double);
	double getFitness();
	void generateCities();
	void insertCity(City);
	void printCities();
	bool checkCityExists(City *);
	std::vector<City> getCityList();
	void shuffleCities();
	double distance_between_cities(City, City);
	double get_tour_distance();
};