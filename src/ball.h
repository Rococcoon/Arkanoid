#ifndef BALL_H
#define BALL_H

#include "raylib.h"
#include "player.h"

typedef struct Ball 
{
    Vector2 position;
    Vector2 speed;
    int     radius;
    bool    active;
} Ball;

void DrawBall(Ball* ball, ColorPallet* RosePine);
void HandleBallPlayerCollision(Ball* ball, Player* player);
void HandleBallWallCollision(Ball* ball, Player* player);
void InitBall(Player* player, Ball* ball);
void LaunchBall(Ball* ball);
void MoveBall(Ball* ball, Player* player);
void UpdateBall(Player* player, Ball* ball);

#endif // !BALL_H
