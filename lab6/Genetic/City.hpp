#pragma once

class City {
private:
	static const int MAP_BOUNDARY = 1000;
	char name;
	int x;
	int y;
public:
	City();
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	char generateName();
	int randomCoordinate();
	void printCity();
};