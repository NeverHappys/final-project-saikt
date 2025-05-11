#include "chestGen.h"

ChestGenerator::ChestGenerator(char** maps, int WIDTH, int HEIGHT){
	this->HEIGHT = HEIGHT;
	this->WIDTH = WIDTH;
	this->fullMap = maps;
	map = new float* [WIDTH];
	for (int i = 0; i < WIDTH; i++) {
		map[i] = new float[HEIGHT];
	}
}

float ChestGenerator::lerp(float a, float b, float x){
	return a + x * (b - a);
}

float ChestGenerator::smooth(float x, float y){
	float corners = (map[(int)x - 1][(int)y - 1] + map[(int)x + 1][(int)y - 1] + map[(int)x - 1][(int)y + 1] + map[(int)x + 1][(int)y + 1]) / 16;
	float sides = (map[(int)x][(int)y - 1] + map[(int)x][(int)y + 1] + map[(int)x - 1][(int)y] + map[(int)x + 1][(int)y]) / 8;
	float center = map[(int)x][(int)y] / 4;
	return corners + sides + center;
}

void ChestGenerator::fill_map(){
	srand(time(NULL));
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			map[x][y] = (float)rand() / (float)RAND_MAX;
		}
	}
	for (int i = 0; i < 0; i++) {
		for (int x = 1; x < WIDTH - 1; x++) {
			for (int y = 1; y < HEIGHT - 1; y++) {
				map[x][y] = smooth(x, y);
			}
		}
	}
}

int ChestGenerator::getChunkWIDTH(){
	return this->WIDTH/4;
}

int ChestGenerator::getChunkHEIGHT(){
	return this->HEIGHT/4;
}
char** ChestGenerator::getMap(char symbol, float coef, int &size){
	fill_map();
	size = 0;
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++) {
			if (fullMap[i][j] == ' ' && map[i][j] > coef) {
				fullMap[i][j] = symbol;
				size++;
			}
		}
	}
	return fullMap;
}
