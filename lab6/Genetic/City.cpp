/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "City.hpp"
#include <iostream>

using namespace std;

City::City() {
	name = generateName();
	setX(randomCoordinate());
	setY(randomCoordinate());
}
int City::getX() {
	return x;
}
int City::getY() {
	return y;
}

char City::getName() {
	return name;
}
void City::setX(int _x) {
	x = _x;
}
void City::setY(int _y) {
	y = _y;
}


char City::generateName() {
	char c;
	int r;
	r = rand() % 26;   // generate a random number
	c = 'A' + r;            // Convert to a character from a-z
	return c;
}

int City::randomCoordinate() {
	return rand() % (MAP_BOUNDARY +1);
}

void City::printCity() {
	cout << "Name: " << name << endl;
	cout << "X: " << getX() << endl;
	cout << "Y: " << getY() << endl;
}