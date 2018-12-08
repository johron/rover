set(name "rover-framework-tests")

set(src_precompiled
	"../src/precompiled/precompiled.h")

set(src_sample
	"src/sample/actions.cpp"
	"src/sample/cards.cpp"
	"src/sample/card_storage.cpp"
	"src/sample/deck.cpp"
	"src/sample/discard.cpp"
	"src/sample/game.cpp"
	"src/sample/game_session.cpp"
	"src/sample/player_hand.cpp"
	"src/sample/expedition.cpp")

set(src_files
	${src_precompiled}
	${src_sample})

add_executable(${name} ${src_files})

source_group("src\\precompiled" FILES ${src_precompiled})
source_group("src\\sample" FILES ${src_sample})

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