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

std::vector<std::vector<Grid>> grids(numOfCellX, std::vector<Grid>(numOfCellY, Grid(0, 0)));

Vector2 normalise(Vector2 s, Vector2 e)
{
int x = s.x - e.x;
int y = s.y - e.y;
float mag = std::sqrt(x * x + y * y);
return { x / mag,y / mag };


}



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



for (int i = 0; i < screenWidth; i+=cellSize) {
for (int j = 0; j < screenHeight; j+=cellSize) {
int mouse_x = GetMousePosition().x;
int mouse_y = GetMousePosition().y;


if ((mouse_x >= i && mouse_x <= i + 10) && (mouse_y >= j && mouse_y <= j + 10))
{
if (IsKeyDown(KEY_S)&& !setStart)
{
grids[i / cellSize][j / cellSize].type = 2;
grids[i / cellSize][j / cellSize].Color = GREEN;
startX = i ;
startY= j ;
setStart = 1;
}

if (IsKeyDown(KEY_E) && !setEnd)
{
grids[i / cellSize][j / cellSize].type = 3;
grids[i / cellSize][j / cellSize].Color = RED;
endX = i;
endY = j;
setEnd = 1;
}
if (IsMouseButtonDown(0)) {
if (grids[i / cellSize][j / cellSize].type == 2) { setStart = 0; }
if (grids[i / cellSize][j / cellSize].type == 3) { setEnd = 0; }

grids[i / cellSize][j / cellSize].type = 1;
grids[i / cellSize][j / cellSize].Color = DARKPURPLE;


}
if (IsMouseButtonDown(1)) {
if (grids[i / cellSize][j / cellSize].type == 2) { setStart = 0; }
if (grids[i / cellSize][j / cellSize].type == 3) { setEnd = 0; }
grids[i / cellSize][j / cellSize].type = 0;
grids[i / cellSize][j / cellSize].Color = GRAY;
}
}







DrawRectangle(i, j, cellSize - 1, cellSize - 1,grids[i/cellSize][j/cellSize].Color);
if(setStart && setEnd){ DrawLine(startX, startY, endX, endY, BLACK);
}
}
}




EndDrawing();
//----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow(); // Close window and OpenGL context
//--------------------------------------------------------------------------------------

return 0;
}
