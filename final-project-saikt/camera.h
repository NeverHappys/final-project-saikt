#pragma once
#include "Player.h"
#include "perling.h"

class Camera {
private:
	int camera_FOV_X = 20, camera_FOV_Y = 20, playerAltX = 10, playerAltY = 10;
public:
	Camera() {};
	Camera(int, int); //Первый int - x, второй int y
	char** map_cut(char**, Player, Perling);
	int getcamera_FOV_X();
	int getcamera_FOV_Y();
	int getplayerAltX();
	int getplayerAltY();
};