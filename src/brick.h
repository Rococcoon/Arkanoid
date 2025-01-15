#ifndef BRICK_H
#define BRICK_H

#include "raylib.h"
#include "colors.h"

#define LINES_OF_BRICKS 5
#define BRICKS_PER_LINE 20

typedef struct Brick {
  Vector2 position;
  Vector2 brickSize;   
  bool    active;
} Brick;

void InitBricks(Brick bricks[LINES_OF_BRICKS][BRICKS_PER_LINE]);
void UpdateBricks(void);
void DrawBricks(
  Brick bricks[LINES_OF_BRICKS][BRICKS_PER_LINE], 
  ColorPallet* RosePine
);

#endif // !BRICK_H
