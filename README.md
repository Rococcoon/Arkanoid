# Arkanoid

This project is a C implementation of the classic game **Arkanoid**, based on the [Raylib tutorial](https://www.raylib.com/examples.html). It includes a `Makefile` to compile the project for both native Linux and WebAssembly using `emcc`.

## Features

- **Native Build**: Compile and run on Linux.
- **WebAssembly Build**: Compile to WebAssembly for running in the browser.
- Powered by [Raylib](https://www.raylib.com), a simple and easy-to-use library for game development.

## Prerequisites

### Native Linux Build
- GCC or Clang
- Raylib installed on your system (`sudo apt install libraylib-dev` on Debian-based systems)

### WebAssembly Build
- [Emscripten SDK](https://emscripten.org/)

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Rococcoon/Arkanoid.git
   cd Arkanoid

## Install dependencies for your build target:
- **Linux**: Install Raylib as described above.
- **WebAssembly**: Install and activate the Emscripten SDK.

## Build

### Linux
- Compile the project:
  ```bash
  make
