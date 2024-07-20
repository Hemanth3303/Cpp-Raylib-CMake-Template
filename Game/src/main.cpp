#include "raylib.h"

#include <iostream>

int main(int argc, char** argv) {

#if defined(GAME_DEBUG)
	std::cout << "Debug Build\n";
#elif defined(GAME_RELEASE)
	std::cout << "Release Build\n";
#elif defined(GAME_DIST)
	std::cout << "Distribution Build\n";
#else
	std::cout << "Unknown Build Configuration\n";
#endif

	InitWindow(960, 540, "Cpp-Raylib-CMake-Template");

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawFPS(10, 10);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}