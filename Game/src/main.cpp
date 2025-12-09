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

	Vector2 mousePosition;
	Rectangle rect = { .width = 50, .height = 50 };

	while (!WindowShouldClose()) {
		mousePosition = GetMousePosition();
		rect.x = mousePosition.x - (rect.width / 2);
		rect.y = mousePosition.y - (rect.height / 2);

		BeginDrawing();
		ClearBackground(BLACK);
		DrawFPS(10, 10);
		DrawRectangleRec(rect, RED);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}