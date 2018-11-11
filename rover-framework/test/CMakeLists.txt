set(name "rover-framework-tests")

set(src_precompiled
	"../src/precompiled/precompiled.h")

set(src_sample
	"src/sample/test.cpp")

set(src_files
	${src_precompiled}
	${src_sample})

add_executable(${name} ${src_files})

source_group("src\\precompiled" FILES ${src_precompiled})
source_group("src\\sample" FILES ${src_sample})

target_link_libraries(${name} "rover-framework")
target_link_libraries(${name} "gtest_main")

set_target_properties(${name} PROPERTIES FOLDER "rover")
set_target_properties(${name} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT ${src_precompiled})

cotire(${name})