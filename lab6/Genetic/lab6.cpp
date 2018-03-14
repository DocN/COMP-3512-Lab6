#include <iostream>
#include "City.hpp"
#include "Cities.hpp"
#include "Population.hpp"
/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int main() {
	/* initialize random seed: */
	srand((int) time(NULL));

	Population * popu = new Population();
	popu->printPopulation();
	popu->shufflePop();
	popu->printPopulation();
	popu->determine_fitness(popu->getPopList());
	cout << popu->getShortTourIndex() << endl;
	cout << popu->getShortestTourInPopulation() << endl;
	popu->moveFittest();
	system("PAUSE");
	return 0;
}