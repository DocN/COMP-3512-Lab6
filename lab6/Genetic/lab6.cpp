#include <iostream>
#include "City.hpp"
#include "Cities.hpp"

using namespace std;

int main() {
	Cities * newList = new Cities();

	City * test = new City();
	City * test2 = new City();
	newList->insertCity(*test);
	newList->insertCity(*test2);
	newList->printCities();
	system("PAUSE");
	return 0;
}