set(name "rover-framework-tests")

set(src_precompiled
	"../src/precompiled/precompiled.h")

set(src_sample
	"src/sample/cards.cpp"
	"src/sample/deck.cpp"
	"src/sample/discard.cpp"
	"src/sample/expedition.cpp")

set(src_files
	${src_precompiled}
	${src_sample})

add_executable(${name} ${src_files})
gtest_discover_tests(${name})

source_group("src\\precompiled" FILES ${src_precompiled})
source_group("src\\sample" FILES ${src_sample})

target_link_libraries(${name} "rover-framework")
target_link_libraries(${name} "gtest_main")

target_include_directories(${name} PUBLIC "../include/")

set_target_properties(${name} PROPERTIES FOLDER "rover")
set_target_properties(${name} PROPERTIES COTIRE_ADD_UNITY_BUILD FALSE)
set_target_properties(${name} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT ${src_precompiled})

cotire(${name})