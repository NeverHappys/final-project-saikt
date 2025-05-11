#include "camera.h"

Camera::Camera(int x_FOV, int y_FOV){
	this->camera_FOV_X = x_FOV;
	this->camera_FOV_Y = y_FOV;
}

char** Camera::map_cut(char** map_arr, Player player, Perling perl) {

	char **cut_map = new char*[camera_FOV_X];
	for (int i = 0; i < camera_FOV_X; i++) {
		cut_map[i] = new char[camera_FOV_Y];
	}

	int x_min = player.getx()-(camera_FOV_X/2), y_min = player.gety()-(camera_FOV_Y/2), iDouble = 0, jDouble = 0;
	//playerAltX = 10;
	//playerAltY = 10;
	//if (x_min < 0) { x_min = 0; playerAltX = player.getx();}
	//else if (x_min > perl.getWIDTH() - (camera_FOV_X / 2)) { x_min = perl.getWIDTH() - (camera_FOV_X / 2);}

	//if (y_min < 0) { y_min = 0; playerAltX = player.gety();}
	//else if (y_min > perl.getHEIGHT() - (camera_FOV_Y / 2)) { y_min = perl.getHEIGHT() - (camera_FOV_Y / 2);}

	for (int i = x_min; i < x_min + camera_FOV_X; i++) {
		for (int j = y_min; j < y_min + camera_FOV_Y; j++) {
			if (i <0 || j<0 || j > perl.getWIDTH() || i+1 > perl.getWIDTH()) {
				cut_map[iDouble][jDouble] = ' ';
			}
			else {
				cut_map[iDouble][jDouble] = map_arr[i][j];
			}
			//std::cout << cut_map[jDouble][iDouble];
			jDouble++;
		}
		//std::cout << "\n";
		iDouble++;
		jDouble = 0;
	}
	//cut_map[playerAltY][playerAltX] = '1';
	return cut_map;
}

int Camera::getcamera_FOV_X()
{
	return camera_FOV_X;
}

int Camera::getcamera_FOV_Y()
{
	return camera_FOV_Y;
}

int Camera::getplayerAltX()
{
	return playerAltX;
}

int Camera::getplayerAltY()
{
	return playerAltY;
}
