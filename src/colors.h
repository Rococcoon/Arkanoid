#ifndef COLORS_H
#define COLORS_H

#include "raylib.h"

typedef struct ColorPallet
{
  Color Base;
  Color Surface;
  Color Overlay;
  Color Muted;
  Color Subtle;
  Color Text;
  Color Love;
  Color Gold;
  Color Pine;
  Color Foam;
  Color Iris;
} ColorPallet;

void InitColorPallet(ColorPallet* RosePine);

#endif // !COLORS_H
