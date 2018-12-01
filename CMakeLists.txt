cmake_minimum_required(VERSION 3.10.0)
project("rover" VERSION 0.1.0)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "predefined")
set_property(GLOBAL PROPERTY CMAKE_EXPORT_COMPILE_COMMANDS ON)

include("cmake/code_coverage.cmake")
include("cmake/compiler_features.cmake")
include("cmake/compiler_warnings.cmake")
include("cmake/googletest.cmake")
include("cmake/cotire.cmake")

add_subdirectory("rover-framework")
add_subdirectory("rover-client")
add_subdirectory("rover-server")
