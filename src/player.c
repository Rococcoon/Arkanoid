#include "player.h"
#include "raylib.h"
#include "window.h"
#include "colors.h"

// initialize the player
void InitPlayer(Player* player) {
  if (player == NULL) return;

  player->position = (Vector2) { 
    Window_screenWidth / 2, 
    Window_screenHeight * 7 / 8 
  };
  player->size = (Vector2) { 
    Window_screenWidth / 10, 
    20 
  };
  player->maxLife = 5;
  player->life = player->maxLife;
}

// Player movement logic
void UpdatePlayer(Player* player) {
  if (IsKeyDown(KEY_LEFT)) {
    player->position.x -= 10;
  }
  if ((player->position.x - player->size.x / 2) <= 0) {
    player->position.x = player->size.x / 2;
  }
  if (IsKeyDown(KEY_RIGHT)) {
    player->position.x += 10;
  }
  if ((player->position.x + player->size.x / 2) >= Window_screenWidth) {
    player->position.x = Window_screenWidth - player->size.x / 2;
  }
}

// draw player logic
void DrawPlayer(Player *player, ColorPallet* RosePine) {
  if (player == NULL) return;

  // Draw player bar
  DrawRectangle(
    player->position.x - player->size.x / 2, 
    player->position.y - player->size.y / 2, 
    player->size.x, player->size.y, 
    RosePine->Pine
  );

  // Draw player lives
  for (int i = 0; i < player->life; i++) {
    DrawRectangle(
      20 + 40 * i, 
      Window_screenHeight - 30, 
      35, 
      10, 
      RosePine->Love
    );
  }
}
