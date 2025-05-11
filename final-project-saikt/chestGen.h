#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "file_worker.h"

using namespace std;

class ChestGenerator {
private:
	int WIDTH, HEIGHT;
	float** map;
	char** fullMap;
public:
	ChestGenerator(char**, int, int);
	float lerp(float,float,float);
	float smooth(float, float);
	void fill_map();
	int getChunkWIDTH();
	int getChunkHEIGHT();
	char** getMap(char symbol, float coef, int &);
};