#define _CRT_SECURE_NO_WARNINGS

#include "drawer.h"
#include <BearLibTerminal.h>
#include <string>
#include <iostream>

void Drawer::drow(char** arrr, Player pl)
{
	int smname;
	for (int i = 0; i < cm.getcamera_FOV_X(); i++)
	{
		for (int j = 0; j < cm.getcamera_FOV_Y(); j++)
		{
			if (j == cm.getcamera_FOV_Y()/2 && i == cm.getcamera_FOV_X()/2) {
				smname = 1;
				terminal_put(i, j, smname);
			}
			else if (arrr[i][j] == '2') {
				smname = 2;
				terminal_put(i, j, smname);
			}
			else if (arrr[i][j] == '3') {
				smname = 3;
				terminal_put(i, j, smname);
			}
			else if (arrr[i][j] == '4') {
				smname = 4;
				terminal_put(i, j, smname);
			}
			else if(arrr[i][j] == ' ') {
				terminal_print(i, j, " ");
			}
		}
	}
	terminal_refresh();
}
