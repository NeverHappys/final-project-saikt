#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <BearLibTerminal.h>
#include <vector>

#include "keyReader.h"
#include "perling.h"
#include "Player.h"
#include "ReadMap.h"
#include "controller.h"
#include "camera.h"
#include "drawer.h"
#include "chestGen.h"
#include "Chest.h"
#include "Menu.h"

int main() {
    int enemyCount;
    Player pl(100, 0, 180, 180, 20, 103, 10);
    KeyReader kr;
    
    Camera camera(78, 24);
    ReadMap rm;
    Perling pr(200, 200);
    Drawer drawer(camera);
    Chest cs;
    Controller cntrlr(&pl, kr);
    Menu mn;

    //pr.generate_map();
    //pr.writeMapToFile("map2");

    char** map = new char* [200];
    for (int i = 0; i < 200; i++) {
        map[i] = new char[200];
    }

    char** mapobr = new char* [20];
    for (int i = 0; i < 20; i++) {
        mapobr[i] = new char[20];
    }

    terminal_open();
    terminal_set("1: 1.png");
    terminal_set("2: 2.png");
    terminal_set("3: 3.png");
    terminal_set("4: 4.png");

    rm.readFile(map, "map3");
    bool start = true;
    ChestGenerator cg(map, 200, 200);
    map = cg.getMap('3', 0.999, enemyCount);
    map = cg.getMap('4', 0.997, enemyCount);
    
    terminal_print(1, 1, "1. Play");
    terminal_print(1, 2, "2. New Game");
    terminal_print(1, 3, "3. Exit");
    terminal_refresh();
    

    int key = terminal_read();
        switch (key)
        {
        case 30:
            break;
        case 31:
            pr.generate_map();
            pr.writeMapToFile("map3");
            rm.readFile(map, "map3");
            break;
        case 32:
            start = false;
        }

    while (start) {
        cntrlr.moveToFreePos(map, 200, 200);
        mapobr = camera.map_cut(map, pl, pr);
        drawer.drow(mapobr, pl);
        cntrlr.playerMove(map, enemyCount, start);
        if (pl.gethp() <= 0 || enemyCount == 0) {
            start = false;
        }
    }
    if (pl.gethp() <= 0) {
        terminal_clear();
        terminal_print(10, 10, "Game over");
        terminal_refresh();
        terminal_read();
    }
    else if (enemyCount == 0) {
        terminal_clear();
        terminal_print(10, 10, "Game end.");
        terminal_refresh();
        terminal_read();
    }
}