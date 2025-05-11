#include "perling.h"

Perling::Perling(int WIDTH, int HEIGHT){
	this->HEIGHT = HEIGHT;
	this->WIDTH = WIDTH;
	map = new float*[WIDTH];
	for (int i = 0; i < WIDTH; i++) {
		map[i] = new float[HEIGHT];
	}
}

float Perling::lerp(float a, float b, float x){
	return a + x * (b - a);
}

float Perling::smooth(float x, float y){
	float corners = (map[(int)x - 1][(int)y - 1] + map[(int)x + 1][(int)y - 1] + map[(int)x - 1][(int)y + 1] + map[(int)x + 1][(int)y + 1]) / 16;
	float sides = (map[(int)x][(int)y - 1] + map[(int)x][(int)y + 1] + map[(int)x - 1][(int)y] + map[(int)x + 1][(int)y]) / 8;
	float center = map[(int)x][(int)y] / 4;
	return corners + sides + center;
}

void Perling::generate_map(){
	srand(time(NULL));
	// создаем случайные значения в каждом узле карты
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			map[x][y] = (float)rand() / (float)RAND_MAX;
		}
	}
	// сглаживаем карту с помощью 10 прогонов
	for (int i = 0; i < 20; i++) {
		for (int x = 1; x < WIDTH - 1; x++) {
			for (int y = 1; y < HEIGHT - 1; y++) {
				map[x][y] = smooth(x, y);
			}
		}
	}
}

int Perling::getWIDTH(){
	return this->WIDTH;
}

int Perling::getHEIGHT(){
	return this->HEIGHT;
}

void Perling::writeMapToFile(std::string mapName){
	FileWorker fw;
	if (fw.findTheFile(mapName)) {
		fw.writeToFile(mapName, "", true);
	}
	for (int y = 0; y < this->HEIGHT; y++) {
		for (int x = 0; x < this->WIDTH; x++) {
			if (x == 0 || y == 0 || x == WIDTH-1 || y == HEIGHT-1) {
				map[x][y] = 0.9;
			}
			if (map[x][y] < 0.51) {
				fw.writeToFile(mapName, " ", false);
			}
			else {
				//fw.writeToFile(mapName, " ", false);
				fw.writeToFile(mapName, "2", false);
			}
		}
		fw.writeToFile(mapName, "\n", false);
	}
}

float** Perling::getMap(){
	return this->map;
}
