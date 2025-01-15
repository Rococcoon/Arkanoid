#include "colors.h"
#include "raylib.h"

void InitColorPallet(ColorPallet* RosePine) 
{
  RosePine->Base = (Color){28, 27, 34, 255};       // Base background
  RosePine->Surface = (Color){40, 39, 48, 255};    // Surface
  RosePine->Overlay = (Color){50, 49, 59, 255};    // Overlay
  RosePine->Muted = (Color){108, 100, 116, 255};   // Muted
  RosePine->Subtle = (Color){138, 131, 148, 255};  // Subtle
  RosePine->Text = (Color){221, 217, 231, 255};    // Text
  RosePine->Love = (Color){235, 111, 97, 255};     // Love
  RosePine->Gold = (Color){235, 160, 96, 255};     // Gold
  RosePine->Pine = (Color){143, 188, 187, 255};    // Pine
  RosePine->Foam = (Color){130, 200, 190, 255};    // Foam
  RosePine->Iris = (Color){140, 170, 238, 255};     // Iris
}
