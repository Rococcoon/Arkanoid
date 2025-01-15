# Compiler and flags
CC = gcc
# CFLAGS = -Wall -Wextra -std=c99 -I.
CFLAGS = -I/home/lulu/raylib/src -Wall
# LDFLAGS = -lraylib -lm -lpthread -ldl -lGL -lrt -lX11
LDFLAGS = -L/home/lulu/raylib/build/raylib -lraylib -lm -ldl -lpthread -lGL

# Project files
SRC = src/main.c src/window.c src/player.c src/ball.c src/collisions.c src/brick.c src/gameState.c src/colors.c

OBJ = $(SRC:.c=.o)
TARGET = arkanoid

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

# Rebuild the project
rebuild: clean all
