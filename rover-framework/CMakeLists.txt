set(name "rover-framework")

set(src_include
	"include/rover/framework"
	"include/rover/framework.h")

set(src_precompiled
	"src/precompiled/precompiled.h")

set(src_third_party
	"src/third_party/asio.h")

set(src_lost_cities
	"src/games/lost_cities/action_detail.h"
	"src/games/lost_cities/action_detail.cpp"
	"src/games/lost_cities/containers.h"
	"src/games/lost_cities/cards.h"
	"src/games/lost_cities/deck.h"
	"src/games/lost_cities/discard.h"
	"src/games/lost_cities/expedition.h"
	"src/games/lost_cities/game_state.h"
	"src/games/lost_cities/game_session.h"
	"src/games/lost_cities/default_controller.h"
	"src/games/lost_cities/player_actions.h"
	"src/games/lost_cities/player_hand.h"
	"src/games/lost_cities/player_controller.h"
	"src/games/lost_cities/player_state.h"
	"src/games/lost_cities/lost_cities.h"
	"src/games/lost_cities/utils.h")

set(src_server
	"src/server/server.h")

set(src_files 
	${src_include}
	${src_precompiled}
	${src_server}
	${src_lost_cities})

add_library(${name} ${src_files})

source_group("include" FILES ${src_include})
source_group("src\\precompiled" FILES ${src_precompiled})
source_group("src\\server" FILES ${src_server})
source_group("src\\games\\lost_cities" FILES ${src_lost_cities})

find_package(Threads REQUIRED)
find_package(Boost 1.68 REQUIRED)

target_link_libraries(${name} PRIVATE Threads::Threads)
target_link_libraries(${name} PUBLIC "rover-coverage")
target_link_libraries(${name} PUBLIC "rover-warnings")

target_compile_features(${name} INTERFACE cxx_std_17)

set_target_properties(${name} PROPERTIES FOLDER "rover")
set_target_properties(${name} PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(${name} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT ${src_precompiled})

cotire(${name})

option(ADD_ROVER_TESTS "Adds rover tests to project" ON)

if (ADD_ROVER_TESTS)
	add_subdirectory(test)
endif()