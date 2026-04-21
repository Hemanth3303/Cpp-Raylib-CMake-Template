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
	OUTPUT_NAME Game
)

target_include_directories(Game
	PUBLIC

	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(Game
	PUBLIC

	PRIVATE
		raylib
)

target_compile_definitions(Game
	PUBLIC

	PRIVATE
		GAME
)

# PLATFORM AND COMPILER SPECIFIC

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")

	target_compile_definitions(Game
		PUBLIC

		PRIVATE
			NOMINMAX
			_CRT_SECURE_NO_WARNINGS
			WIN32_LEAN_AND_MEAN
			GAME_PLATFORM_WINDOWS
	)

	if(MSVC)
		target_compile_options(Game
			PUBLIC

			PRIVATE
				/Zc:__cplusplus
		)
	elseif(MINGW)
		target_link_libraries(Game
			PUBLIC
				m
			PRIVATE

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
				-static-libstdc++
		)
	endif()

endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")

	target_compile_definitions(Game
		PUBLIC

		PRIVATE
			GAME_PLATFORM_LINUX
	)

	if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		target_link_libraries(Game
			PUBLIC
				dl
				m
				pthread
			PRIVATE

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
			GAME_PLATFORM_OSX
	)

endif()

# CONFIGURATION SPECIFIC

target_compile_definitions(Game
	PUBLIC

	PRIVATE
		$<$<CONFIG:Debug>:GAME_DEBUG_BUILD>
		$<$<CONFIG:Debug>:DEBUG>

		$<$<CONFIG:Profile>:GAME_PROFILE_BUILD>
		$<$<CONFIG:Profile>:NDEBUG>

		$<$<CONFIG:Release>:GAME_RELEASE_BUILD>
		$<$<CONFIG:Release>:NDEBUG>
)

# POST-BUILD RESOURCE COPY

add_custom_command(
	TARGET Game POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		"${CMAKE_CURRENT_SOURCE_DIR}/res"
		"$<TARGET_FILE_DIR:Game>/res"
	COMMENT "Copying resource folder to binary directory"
)
