file(GLOB_RECURSE GAME_SRC CONFIGURE_DEPENDS "*.h" "*.c" "*.hpp" "*.cpp")

add_executable(Game
	${GAME_SRC}
)

set_target_properties(Game PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
	C_STANDARD 17
	C_STANDARD_REQUIRED ON
	C_EXTENSIONS OFF
	POSITION_INDEPENDENT_CODE ON
	OUTPUT_NAME Game
)

target_include_directories(Game
	PUBLIC
		
	PRIVATE
		${PROJECT_SOURCE_DIR}/Game/src
		${PROJECT_SOURCE_DIR}/vendor/raylib/src
)

target_link_libraries(Game
	PUBLIC
		
	PRIVATE
		raylib_static
)

target_compile_definitions(Game
	PUBLIC
		
	PRIVATE
		GAME
)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	target_compile_definitions(Game
		PUBLIC
			
		PRIVATE
			NOMINMAX
			_CRT_SECURE_NO_WARNINGS
			WIN32_LEAN_AND_MEAN
			GAME_WINDOWS
	)
	if (MSVC)
		target_compile_options(Game
			PUBLIC
				
			PRIVATE
				/Zc:__cplusplus
		)
		if(CMAKE_BUILD_TYPE STREQUAL Dist)
			target_link_options(Game
				PUBLIC
					
				PRIVATE
					"/SUBSYSTEM:WINDOWS"
					"/ENTRY:mainCRTStartup"
			)
		endif()
	elseif (MINGW)
		target_link_libraries(Game
			PUBLIC
				
			PRIVATE
				m
		)
		target_link_options(Game
			PUBLIC
				
			PRIVATE
				-static
				-static-libgcc
				-static-libstdc++
		)
	elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		target_link_libraries(Game
			PUBLIC
				
			PRIVATE
		)
		target_link_options(Game
			PUBLIC
				
			PRIVATE
				-static
		)
	endif()
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	target_compile_definitions(Game
		PUBLIC
				
		PRIVATE
			GAME_LINUX
	)
	if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		target_link_libraries(Game
			PUBLIC
				
			PRIVATE
				dl
				m
		)
		target_link_options(Game
			PUBLIC
				
			PRIVATE
		)
	elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		target_link_libraries(Game
			PUBLIC
				
			PRIVATE
		)
		target_link_options(Game
			PUBLIC
				
			PRIVATE
		)
	endif()
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
	target_compile_definitions(Game
		PUBLIC
				
		PRIVATE
			GAME_OSX
	)
	target_link_libraries(Game "-framework IOKit")
	target_link_libraries(Game "-framework Cocoa")
	target_link_libraries(Game "-framework OpenGL")
endif()

if(CMAKE_BUILD_TYPE STREQUAL Debug)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}" CACHE STRING "CXX flags" FORCE)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_DEBUG}" CACHE STRING "C flags" FORCE)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS_DEBUG}" CACHE STRING "Linker flags" FORCE)
	target_compile_definitions(Game
		PUBLIC
				
		PRIVATE
			GAME_DEBUG
			DEBUG
	)
endif()

if(CMAKE_BUILD_TYPE STREQUAL Release)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}" CACHE STRING "CXX flags" FORCE)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_RELEASE}" CACHE STRING "C flags" FORCE)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS_RELEASE}" CACHE STRING "Linker flags" FORCE)
	target_compile_definitions(Game
		PUBLIC
				
		PRIVATE
			GAME_RELEASE
			NDEBUG
	)
endif()

if(CMAKE_BUILD_TYPE STREQUAL Dist)
	remove_definitions(-DGAME_RELEASE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}" CACHE STRING "CXX flags" FORCE)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_RELEASE}" CACHE STRING "C flags" FORCE)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS_RELEASE}" CACHE STRING "Linker flags" FORCE)

	target_compile_definitions(Game
		PUBLIC
				
		PRIVATE
			GAME_DIST
			NDEBUG
	)

endif()