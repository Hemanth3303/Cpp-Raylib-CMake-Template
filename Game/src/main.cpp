#include "raylib.h"

#include <iostream>

int main(int argc, char** argv) {

#if defined(GAME_DEBUG_BUILD)
	std::cout << "GAME: Debug Build\n";
#elif defined(GAME_PROFILE_BUILD)
	std::cout << "GAME: Profile Build\n";
#elif defined(GAME_RELEASE_BUILD)
	std::cout << "GAME: Release Build\n";
#else
	std::cout << "GAME: Unknown Build\n";
#endif

	std::cout << "PLATFORM: ";
#if defined(GAME_PLATFORM_WINDOWS)
	std::cout << "Windows";
#elif defined(GAME_PLATFORM_LINUX)
	std::cout << "Linux";
#elif defined(GAME_PLATFORM_DARWIN)
	std::cout << "Darwin";
#elif defined(GAME_PLATFORM_UNKNOWN)
	std::cout << "Unknown";
#else
	std::cout << "Unknown";
#endif
	std::cout << "\n";

	std::cout << "ARCHITECTURE: ";
#if defined(GAME_ARCHITECTURE_X86_64)
	std::cout << "x86-64";
#elif defined(GAME_ARCHITECTURE_X86_32)
	std::cout << "x86-32";
#elif defined(GAME_ARCHITECTURE_AARCH64)
	std::cout << "aarch64";
#elif defined(GAME_ARCHITECTURE_AARCH32)
	std::cout << "aarch32";
#elif defined(GAME_ARCHITECTURE_RISCV64)
	std::cout << "riscv64";
#elif defined(GAME_ARCHITECTURE_RISCV32)
	std::cout << "riscv32";
#elif defined(GAME_ARCHITECTURE_UNKNOWN)
	std::cout << "unknown";
#else
	std::cout << "unknown";
#endif
	std::cout << "\n------------------------------\n";

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
