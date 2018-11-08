cmake_minimum_required(VERSION 3.1)
project("rover" VERSION 0.1.0)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "predefined")

include("cmake/googletest.cmake")

add_subdirectory("rover-framework")
add_subdirectory("rover-runner")