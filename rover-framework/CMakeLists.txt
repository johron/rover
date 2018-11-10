set(name "rover-framework")

set(src_include
	"include/rover/framework"
	"include/rover/framework.h")

set(src_runner
	"src/runner/runner.h"
	"src/runner/dummy.h")

set(src_files 
	${src_include}
	${src_runner})

add_library(${name} ${src_files})

source_group("include" FILES ${src_include})
source_group("src\\runner" FILES ${src_runner})

set_target_properties(${name} PROPERTIES FOLDER "rover")
set_target_properties(${name} PROPERTIES LINKER_LANGUAGE CXX)