#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "colors.h"

#define NULL ((void*)0) // Define NULL if no standard library is included

typedef struct Player {
    Vector2 position;
    Vector2 size;
    int     life;
    int     maxLife;
} Player;

void InitPlayer(Player* player);
void UpdatePlayer(Player* player);
void DrawPlayer(Player* player, ColorPallet* RosePine);

#endif // !PLAYER_H
