#include "raylib.h"
#include "gameState.h"
#include "player.h"
#include "ball.h"
#include "brick.h"
#include "collisions.h"
#include "colors.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

int main(void) 
{
  // Initialize the window
  InitWindow(800, 600, "Arkanoid");

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else

  // Set target FPS
  SetTargetFPS(60);

  // Create and initialize the gamestate
  ColorPallet RosePine;
  InitColorPallet(&RosePine);
  // Create and initialize the gamestate
  GameState gameState;
  InitGameState(&gameState);
  // Create and initialize the player
  Player player;
  InitPlayer(&player);
  // Create and initialize the ball
  Ball ball;
  InitBall(&player, &ball);
  // Create and initialize the bricks
  Brick bricks[LINES_OF_BRICKS][BRICKS_PER_LINE];
  InitBricks(bricks);

  // Main game loop
  while (!WindowShouldClose()) 
  {
    if (gameState.Active)
    {
      if (gameState.Pause == false)
      {
        // Update
        UpdateGameState(&gameState, &player, bricks, &RosePine);
        UpdatePlayer(&player);
        UpdateBall(&player, &ball);

        // Draw
        BeginDrawing();

          ClearBackground(RosePine.Base);
          // Draw player
          DrawPlayer(&player, &RosePine);
          // Draw ball
          DrawBall(&ball, &RosePine);
          // Draw bricks
          DrawBricks(bricks, &RosePine);

          // check ball wall collision
          CheckBallWallCollision(&ball);
          // check ball player collision
          CheckBallPlayerCollision(&ball, &player);
          // check ball brick collision
          CheckBallBrickCollision(&ball, bricks, &gameState);

        EndDrawing();
      } else {
        // Draw
        BeginDrawing();
          // Draw pause screen
          ClearBackground(RosePine.Base);
          CheckAndDrawPauseState(&gameState, &RosePine);
        EndDrawing();
      }
    } else {
      // Draw
      BeginDrawing();
        // Draw pause screen
        ClearBackground(RosePine.Base);
        CheckAndDrawStartState(&gameState, &player, &ball, &RosePine, bricks);
      EndDrawing();
    }
  }

#endif
  // Close the window
  CloseWindow();

  return 0;
}
