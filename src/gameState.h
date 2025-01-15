#ifndef GAMESTATE_H
#define GAMESTATE_H

#define NULL ((void*)0) 

#include "player.h"
#include "brick.h"
#include "ball.h"

#include <stdbool.h>

typedef struct GameState
{
  bool      Active;
  bool      Pause;
  bool      Win;
  int       BrickCount;
} GameState;

void CheckAndDrawPauseState(GameState* gameState, ColorPallet* RosePine);
void CheckAndDrawStartState(GameState* gameState, 
                            Player* player, 
                            Ball* ball,
                            ColorPallet* RosePine,
                            Brick bricks[LINES_OF_BRICKS][BRICKS_PER_LINE]);       // Update game (one frame)
void CheckLoseEvent(GameState* gameState, Player* player);
void CheckPauseEvent(GameState* gameState);
void CheckWinEvent(GameState* gameState, 
                   Player* player, 
                   ColorPallet* RosePine);
void InitGameState(GameState* gameState); // initialize game statk
void UpdateGameState(GameState* gameState, 
                     Player* player, 
                     Brick bricks[LINES_OF_BRICKS][BRICKS_PER_LINE],
                     ColorPallet* RosePine);       // Update game (one frame)

#endif // !GAMESTATE_H
