set(name "rover-framework-tests")

set(src_precompiled
	"../src/precompiled/precompiled.h")

set(src_lost_cities
	"src/lost_cities/actions.cpp"
	"src/lost_cities/cards.cpp"
	"src/lost_cities/card_storage.cpp"
	"src/lost_cities/deck.cpp"
	"src/lost_cities/discard.cpp"
	"src/lost_cities/game.cpp"
	"src/lost_cities/game_session.cpp"
	"src/lost_cities/player_hand.cpp"
	"src/lost_cities/expedition.cpp")

set(src_server
	"src/server/server.cpp")

set(src_files
	${src_precompiled}
	${src_server}
	${src_lost_cities})

add_executable(${name} ${src_files})

source_group("src\\precompiled" FILES ${src_precompiled})
source_group("src\\lost-cities" FILES ${src_lost_cities})
source_group("src\\server" FILES ${src_server})

target_compile_features(${name} PUBLIC cxx_std_17)

target_link_libraries(${name} PRIVATE "rover-coverage")
target_link_libraries(${name} PRIVATE "rover-warnings")
target_link_libraries(${name} PRIVATE "rover-framework")
target_link_libraries(${name} PRIVATE "gtest_main")

target_include_directories(${name} PUBLIC "../include/")

set_target_properties(${name} PROPERTIES FOLDER "rover")
set_target_properties(${name} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT ${src_precompiled})

gtest_discover_tests(${name})
cotire(${name})