#include "brick.h"
#include "colors.h"

#define NULL ((void*)0) 

void InitBricks(Brick bricks[LINES_OF_BRICKS][BRICKS_PER_LINE]) 
{
    int initialDownPosition = 50;
    Vector2 defaultBrickSize = { 50.0f, 20.0f }; // Define a default size

    for (int i = 0; i < LINES_OF_BRICKS; i++) 
    {
        for (int j = 0; j < BRICKS_PER_LINE; j++) 
        {
            bricks[i][j].position = (Vector2){
                j * defaultBrickSize.x + defaultBrickSize.x / 2,
                i * defaultBrickSize.y + initialDownPosition
            };
            bricks[i][j].brickSize = defaultBrickSize; // Assign size to each brick
            bricks[i][j].active = true; // Mark each brick as active
        }
    }
}

// update brick
void UpdateBrick() 
{

}

void DrawBricks(Brick bricks[LINES_OF_BRICKS][BRICKS_PER_LINE], ColorPallet* RosePine) 
{
  for (int i = 0; i < LINES_OF_BRICKS; i++) {
    for (int j = 0; j < BRICKS_PER_LINE; j++) {
      if (bricks[i][j].active) {
        Color color = ((i + j) % 2 == 0) ? RosePine->Muted : RosePine->Subtle;
        DrawRectangle(
          bricks[i][j].position.x - bricks[i][j].brickSize.x / 2,
          bricks[i][j].position.y - bricks[i][j].brickSize.y / 2,
          bricks[i][j].brickSize.x,
          bricks[i][j].brickSize.y,
          color
        );
      }
    }
  }
}
