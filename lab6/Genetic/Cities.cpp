#include "Cities.hpp"

using namespace std;
Cities::Cities() {

}
void Cities::insertCity(City currentCity) {
	cityList.push_back(currentCity);
}

void Cities::printCities() {
	for (int i = 0; i < cityList.size(); i++) {
		cityList.at(i).printCity();
	}
}
