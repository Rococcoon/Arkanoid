#include "collisions.h"
#include "window.h"
#include "ball.h"
#include "gameState.h"
#include <math.h>

// Check if the ball collides with the player (top, bottom, left, right)
BallPlayerCollision CheckBallPlayerCollision(Ball* ball, Player* player) 
{
  BallPlayerCollision collision = {0};

  // Check for collision with the player's top
  collision.top = (ball->position.y - ball->radius) <= 
    (player->position.y - player->size.y / 2);

  // Check for collision with the player's bottom
  collision.bottom = (ball->position.y + ball->radius) >= 
    (player->position.y + player->size.y / 2);

  // Check for collision with the player's left side
  collision.left = (ball->position.x - ball->radius) <= 
    (player->position.x - player->size.x / 2);

  // Check for collision with the player's right side
  collision.right = (ball->position.x + ball->radius) >= 
    (player->position.x + player->size.x / 2);

  return collision;
}

// Check if the ball collides with any walls
BallWallCollision CheckBallWallCollision(Ball* ball) 
{
  BallWallCollision collision = {0};

  collision.top = (ball->position.y - ball->radius) <= 0;
  collision.bottom = (ball->position.y + ball->radius) >= Window_screenHeight;
  collision.left = (ball->position.x - ball->radius) <= 0;
  collision.right = (ball->position.x + ball->radius) >= Window_screenWidth;

  return collision;
}

// Collision logic: ball vs bricks
void CheckBallBrickCollision(
  Ball* ball, 
  Brick bricks[LINES_OF_BRICKS][BRICKS_PER_LINE],
  GameState* gameState) 
{
  for (int i = 0; i < LINES_OF_BRICKS; i++) {
    for (int j = 0; j < BRICKS_PER_LINE; j++) {
      if (bricks[i][j].active) {
        Vector2 brickSize = bricks[i][j].brickSize;
        float brickTop = bricks[i][j].position.y - brickSize.y / 2;
        float brickBottom = bricks[i][j].position.y + brickSize.y / 2;
        float brickLeft = bricks[i][j].position.x - brickSize.x / 2;
        float brickRight = bricks[i][j].position.x + brickSize.x / 2;

        // Hit below
        bool hitBelow = 
          (ball->position.y - ball->radius <= brickBottom) &&
          (ball->position.y - ball->radius > brickBottom + ball->speed.y) &&
          (fabs(ball->position.x - bricks[i][j].position.x) < 
           brickSize.x / 2 + ball->radius * 2 / 3) &&
          (ball->speed.y < 0);

        // Hit above
        bool hitAbove = 
          (ball->position.y + ball->radius >= brickTop) &&
          (ball->position.y + ball->radius < brickTop + ball->speed.y) &&
          (fabs(ball->position.x - bricks[i][j].position.x) < 
           brickSize.x / 2 + ball->radius * 2 / 3) &&
          (ball->speed.y > 0);

        // Hit left
        bool hitLeft = 
          (ball->position.x + ball->radius >= brickLeft) &&
          (ball->position.x + ball->radius < brickLeft + ball->speed.x) &&
          (fabs(ball->position.y - bricks[i][j].position.y) < 
           brickSize.y / 2 + ball->radius * 2 / 3) &&
          (ball->speed.x > 0);

        // Hit right
        bool hitRight = 
          (ball->position.x - ball->radius <= brickRight) &&
          (ball->position.x - ball->radius > brickRight + ball->speed.x) &&
          (fabs(ball->position.y - bricks[i][j].position.y) < 
           brickSize.y / 2 + ball->radius * 2 / 3) &&
          (ball->speed.x < 0);

        // Handle collisions
        if (hitBelow || hitAbove) {
          bricks[i][j].active = false;
          ball->speed.y *= -1;
          gameState->BrickCount++;
        } else if (hitLeft || hitRight) {
          bricks[i][j].active = false;
          ball->speed.x *= -1;
          gameState->BrickCount++;
        }
      }
    }
  }
}
