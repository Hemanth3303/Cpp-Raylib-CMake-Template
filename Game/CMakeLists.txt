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

cmake_base_configure_target(Game)
cmake_base_apply_target_definitions(Game GAME)
cmake_base_apply_os_definitions_to_target(Game GAME)
cmake_base_apply_architecture_definitions_to_target(Game GAME)
cmake_base_apply_compiler_definitions_to_target(Game GAME)
cmake_base_apply_sanitizers(Game SANITIZERS ASAN UBSAN CONFIGS Debug)

# POST-BUILD RESOURCE COPY
add_custom_command(
	TARGET Game POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		"${CMAKE_CURRENT_SOURCE_DIR}/res"
		"$<TARGET_FILE_DIR:Game>/res"
	COMMENT "Copying resource folder to binary directory"
)
