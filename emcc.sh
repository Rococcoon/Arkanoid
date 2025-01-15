#!/bin/bash

# Define source files
SOURCE_FILES="src/main.c src/gameState.c src/player.c src/ball.c src/brick.c src/collisions.c src/colors.c src/window.c"

# Define output file
OUTPUT="index.html"

# Define raylib paths
RAYLIB_INCLUDE_PATH="$HOME/raylib/src"   # Path to raylib.h
RAYLIB_LIBRARY_PATH="$HOME/raylib/build-web/raylib"  # Path to libraylib.a

# Compiler flags
EMCC_FLAGS=(
    -o "$OUTPUT"
    -s USE_GLFW=3
    -s FULL_ES2=1
    -s ASYNCIFY=1
    -s "EXPORTED_FUNCTIONS=['_main']"
    -s "EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']"
    -I"$RAYLIB_INCLUDE_PATH"
    -L"$RAYLIB_LIBRARY_PATH"
    -lraylib
)

# Compile the project
emcc $SOURCE_FILES "${EMCC_FLAGS[@]}"

# Print completion message
if [ $? -eq 0 ]; then
    echo "Compilation successful! Open $OUTPUT in a browser to run the game."
else
    echo "Compilation failed!"
fi
