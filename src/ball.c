#include "ball.h"
#include "raylib.h"
#include "player.h"
#include "collisions.h"

// Draw the ball on the screen
void DrawBall(Ball* ball, ColorPallet* RosePine) {
    DrawCircleV(ball->position, ball->radius, RosePine->Gold);
}

// Handle the collision logic for the ball with player
void HandleBallPlayerCollision(Ball* ball, Player* player) 
{
  Rectangle playerRectangle = 
    {
      player->position.x - player->size.x/2,
      player->position.y - player->size.y/2, 
      player->size.x, player->size.y
    };

  // Collision logic: ball vs player
  if (CheckCollisionCircleRec(ball->position, ball->radius, playerRectangle))
  {
    if (ball->speed.y > 0)
    {
      ball->speed.y *= -1;
      ball->speed.x = 
        (ball->position.x - 
        player->position.x) / 
        (player->size.x / 2) * 
        5;
    }
  }
}

// Handle the collision logic for the ball with walls
void HandleBallWallCollision(Ball* ball, Player* player) 
{
  BallWallCollision collision = CheckBallWallCollision(ball);

  // Top wall collision
  if (collision.top) 
  {
    ball->speed.y *= -1;
  }

  // Left or right wall collision
  if (collision.left || collision.right) 
  {
    ball->speed.x *= -1;
  }

  // Bottom wall collision (game over)
  if (collision.bottom) 
  {
    ball->speed = (Vector2){ 0, 0 }; // Stop the ball
    ball->active = false; // Deactivate the ball
    player->life--; // Deduct a life from the player

    // return ball to center of player paddle
    InitBall(player, ball);
  }
}

// initialize ball
void InitBall(Player* player, Ball* ball) 
{
  ball->position = (Vector2)
  { 
    player->position.x, 
    player->position.y - player->size.y / 2 - ball->radius 
  };
  ball->speed = (Vector2) { 0, 0 };
  ball->radius = 7;
  ball->active = false;
}

// Launch the ball when space is pressed
void LaunchBall(Ball* ball) 
{
  if (!ball->active && IsKeyPressed(KEY_SPACE)) 
  {
    ball->active = true;
    ball->speed = (Vector2){ 0, -5 };
  }
}

// Update the ball's position based on its speed
void MoveBall(Ball* ball, Player* player) 
{
  if (!ball->active) 
  {
    InitBall(player, ball);
  }

  if (ball->active) 
  {
    ball->position.x += ball->speed.x;
    ball->position.y += ball->speed.y;
  } 
  else 
  {
    // Position ball above player when inactive
    ball->position = (Vector2) {
      ball->position.x, // Align with the player horizontally
      ball->position.y  // Adjust for vertical positioning
    };
  }
}

// Update the ball position and handle its state
void UpdateBall(Player* player, Ball* ball) 
{
  LaunchBall(ball);        // Handle ball launch logic
  MoveBall(ball, player);          // Update ball position
  HandleBallPlayerCollision(ball, player); // Check for collisions and update
  HandleBallWallCollision(ball, player); // Check for collisions and update
}
