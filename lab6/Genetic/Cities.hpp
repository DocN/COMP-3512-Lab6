#pragma once
#include <vector>
#include <iostream>
#include "City.hpp"

class Cities {
private:
	std::vector<City> cityList;

public:
	Cities();
	void insertCity(City);
	void printCities();
};