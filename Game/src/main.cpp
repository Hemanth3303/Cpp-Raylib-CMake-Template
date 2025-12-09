#include "raylib.h"

#include <iostream>

int main(int argc, char** argv) {

#if defined(GAME_DEBUG_BUILD)
	std::cout << "Debug Build\n";
#elif defined(GAME_PROFILE_BUILD)
	std::cout << "Profile Build\n";
#elif defined(GAME_RELEASE_BUILD)
	std::cout << "Release Build\n";
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