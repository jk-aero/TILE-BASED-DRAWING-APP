#include "raylib.h"
#include<iostream>
#include<cmath>
#include<vector>




const int screenWidth = 600;
const int screenHeight = 600;
const int cellSize = 10;
const int numOfCellX = screenWidth / cellSize;
const int numOfCellY = screenHeight / cellSize;


class Grid {
public:
int posX, posY; int type; Color GRAY;
Grid(int x, int y) :posX(x), posY(y) {}
//type 1 means obstruction
//type 0 means no obstruction
//type 2 means its start
//type 3 means its end
};
