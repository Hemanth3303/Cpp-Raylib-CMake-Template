#include "raylib.h"

#include <iostream>

#if defined(GAME_COMPILER_MSVC)
#pragma warning(disable : 5105)
#endif // _MSC_VER

void printConfigInfo();
void printArchitectureInfo();
void printOSInfo();
void printCompilerInfo();

int main(int argc, char** argv) {
	printConfigInfo();
	printArchitectureInfo();
	printOSInfo();
	printCompilerInfo();

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


void printConfigInfo() {
#if defined(GAME_DEBUG_BUILD)
    std::cout << "GAME: Debug Build\n";
#elif defined(GAME_PROFILE_BUILD)
    std::cout << "GAME: Profile Build\n";
#elif defined(GAME_RELEASE_BUILD)
    std::cout << "GAME: Release Build\n";
#else
    std::cout << "GAME: Unknown Build\n";
#endif
}

void printArchitectureInfo() {
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
    std::cout << "\n";
}

void printOSInfo() {
    std::cout << "OS: ";
#if defined(GAME_OS_WINDOWS)
    std::cout << "Windows";
#elif defined(GAME_OS_LINUX)
    std::cout << "Linux";
#elif defined(GAME_OS_DARWIN)
    std::cout << "Darwin";
#elif defined(GAME_OS_FREEBSD)
    std::cout << "FreeBSD";
#elif defined(GAME_OS_OPENBSD)
    std::cout << "OpenBSD";
#elif defined(GAME_OS_NETBSD)
    std::cout << "NetBSD";
#elif defined(GAME_OS_ANDROID)
    std::cout << "Android";
#elif defined(GAME_OS_EMSCRIPTEN)
    std::cout << "Emscripten WebAssembly";
#elif defined(GAME_OS_IOS)
    std::cout << "iOS";
#elif defined(GAME_OS_UNKNOWN)
    std::cout << "Unknown";
#else
    std::cout << "Unknown";
#endif
    std::cout << "\n";
}

void printCompilerInfo() {
    std::cout << "COMPILER: ";
#if defined(GAME_COMPILER_GNU_GCC)
    std::cout << "GNU GCC";
#elif defined(GAME_COMPILER_MINGW_W64_GCC)
    std::cout << "MinGW-w64 GCC";
#elif defined(GAME_COMPILER_MINGW32_GCC)
    std::cout << "MinGW32";
#elif defined(GAME_COMPILER_LLVM_CLANG)
    std::cout << "LLVM Clang";
#elif defined(GAME_COMPILER_CLANG_CL)
    std::cout << "Clang-cl";
#elif defined(GAME_COMPILER_MSVC)
    std::cout << "MSVC";
#elif defined(GAME_COMPILER_APPLE_CLANG)
    std::cout << "AppleClang";
#elif defined(GAME_COMPILER_MINGW_W64_GCC)
    std::cout << "unknown";
#else
    std::cout << "unknown";
#endif
    std::cout << "\n";
}
