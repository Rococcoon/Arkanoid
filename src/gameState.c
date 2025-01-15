#include "gameState.h"
#include "ball.h"
#include "brick.h"
#include "raylib.h"
#include "window.h"
#include "player.h"

void CheckAndDrawPauseState(GameState* gameState, ColorPallet* RosePine)
{

  if (IsKeyPressed('P')) gameState->Pause = !gameState->Pause;

  DrawText
  (
    "GAME PAUSED", 
    Window_screenWidth/2 - MeasureText("GAME PAUSED", 40) / 2, 
    Window_screenHeight / 2 - 40, 
    40, 
    RosePine->Text
  );
}

void CheckAndDrawStartState(
  GameState* gameState, 
  Player* player, 
  Ball* ball,
  ColorPallet* RosePine,
  Brick bricks[LINES_OF_BRICKS][BRICKS_PER_LINE])
{
  DrawText
  (
    "PRESS [ENTER] TO PLAY", 
    GetScreenWidth()/2 - MeasureText("PRESS [ENTER] TO PLAY", 20) / 2, 
    GetScreenHeight()/2 - 50, 
    20, 
    RosePine->Text
  );

  if (IsKeyPressed(KEY_ENTER))
  {
    gameState->Active = true;
    gameState->BrickCount = 0;
    player->life = player->maxLife;
    InitBall(player, ball);
    InitBricks(bricks);
  }
}

void CheckLoseEvent(GameState* gameState, Player* player) 
{
  if (player->life <= 0)
  {
    gameState->Active = false;
  }
}

void CheckWinEvent(GameState* gameState, 
                   Player* player, 
                   ColorPallet* RosePine) 
{
  if (gameState->BrickCount == 80)
  {
    gameState->Active = false;
  }
}

void CheckPauseEvent(GameState* gameState)
{
  if (IsKeyPressed('P')) gameState->Pause = !gameState->Pause;
}

void InitGameState(GameState* gameState)
{
  if (gameState == NULL) return;

  gameState->Active = false;
  gameState->Pause = false;
  gameState->Win = false;
  gameState->BrickCount = 0;
}

void UpdateGameState
(
  GameState* gameState, 
  Player* player, 
  Brick bricks[LINES_OF_BRICKS][BRICKS_PER_LINE],
  ColorPallet* RosePine
) 
{
  CheckLoseEvent(gameState, player);
  CheckPauseEvent(gameState);
  CheckWinEvent(gameState, player, RosePine);
}
