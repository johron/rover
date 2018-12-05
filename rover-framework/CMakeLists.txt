set(name "rover-framework")

set(src_include
	"include/rover/framework"
	"include/rover/framework.h")

set(src_precompiled
	"src/precompiled/precompiled.h")

set(src_display
	"src/display/display.h")

set(src_runner
	"src/runner/runner.cpp"
	"src/runner/runner.h"
	"src/runner/dummy.h")

set(src_game_lost_cities
	"src/games/lost_cities/actions.h"
	"src/games/lost_cities/actions.cpp"
	"src/games/lost_cities/containers.h"
	"src/games/lost_cities/cards.h"
	"src/games/lost_cities/deck.h"
	"src/games/lost_cities/discard.h"
	"src/games/lost_cities/expedition.h"
	"src/games/lost_cities/game_state.h"
	"src/games/lost_cities/game_session.h"
	"src/games/lost_cities/hand.h"
	"src/games/lost_cities/player_controller.h"
	"src/games/lost_cities/player_state.h"
	"src/games/lost_cities/lost_cities.h"
	"src/games/lost_cities/utils.h")

set(src_task
	"src/task/task_descriptor.h")

set(src_solver
	"src/solver/solver.h")

set(src_files 
	${src_include}
	${src_precompiled}
	${src_display}
	${src_runner}
	${src_solver}
	${src_game_lost_cities})

add_library(${name} ${src_files})

source_group("include" FILES ${src_include})
source_group("src\\precompiled" FILES ${src_precompiled})
source_group("src\\runner" FILES ${src_runner})
source_group("src\\display" FILES ${src_display})
source_group("src\\solver" FILES ${src_solver})
source_group("src\\games\\lost_cities" FILES ${src_game_lost_cities})

target_link_libraries(${name} PRIVATE "rover-coverage")
target_link_libraries(${name} PRIVATE "rover-warnings")

target_compile_features(${name} INTERFACE cxx_std_17)

set_target_properties(${name} PROPERTIES FOLDER "rover")
set_target_properties(${name} PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(${name} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT ${src_precompiled})

cotire(${name})

option(ADD_ROVER_TESTS "Adds rover tests to project" ON)

if (ADD_ROVER_TESTS)
	add_subdirectory(test)
endif()