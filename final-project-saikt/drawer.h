#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <BearLibTerminal.h>

#include "Player.h"
#include "camera.h"

class Drawer
{
private:
	Camera cm;
public:
	Drawer(Camera cm) {
		this->cm = cm;
	}
	void drow(char **arrr, Player pl);
};

