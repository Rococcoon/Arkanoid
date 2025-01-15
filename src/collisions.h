#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "ball.h"
#include "player.h"
#include "brick.h"
#include "gameState.h"

// Define the BallPlayerCollision struct
typedef struct BallPlayerCollision {
  bool collision;
  bool top;
  bool bottom;
  bool left;
  bool right;
} BallPlayerCollision;

// Define the BallWallCollision struct
typedef struct BallWallCollision {
  bool top;
  bool bottom;
  bool left;
  bool right;
} BallWallCollision;

// Function prototypes
BallWallCollision CheckBallWallCollision(Ball* ball);
BallPlayerCollision CheckBallPlayerCollision(Ball* ball, Player* player);
void CheckBallBrickCollision(
  Ball* ball, 
  Brick bricks[LINES_OF_BRICKS][BRICKS_PER_LINE],
  GameState* gameState
);

#endif // !COLLISIONS_H
