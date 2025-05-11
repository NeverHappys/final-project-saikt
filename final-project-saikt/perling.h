#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "file_worker.h"

using namespace std;

class Perling {
private:
	int WIDTH, HEIGHT;
	float **map;
public:
	Perling(int, int);
	float lerp(float,float,float);
	float smooth(float, float);
	void generate_map();
	int getWIDTH();
	int getHEIGHT();
	void writeMapToFile(std::string);
	float** getMap();
};