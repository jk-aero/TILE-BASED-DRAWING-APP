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
int main(){

// Initialization
//--------------------------------------------------------------------------------------

InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

SetTargetFPS(60); // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

for (int i = 0; i < numOfCellX; i ++) {
for (int j = 0; j < numOfCellY; j ++)
{
grids[i][j] = Grid{ i * cellSize,j * cellSize };
//std::cout << grids[i][j].posX << " :x "<<grids[i][j].posY<<" :y \n";

}
};

bool setStart = 0;
bool setEnd = 0;
float startX = 0; float startY = 0;
float endX = 0; float endY = 0;




// Main game loop
while (!WindowShouldClose()) // Detect window close button or ESC key
{



// Draw
//----------------------------------------------------------------------------------
BeginDrawing();

ClearBackground(BLACK);

