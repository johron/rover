message("-- External Project: networking-ts")

set(NETWORKING_TS_PROJECT_FILE "cmake/networking-ts.cmake.in")

set(NETWORKING_TS_DIR ${PROJECT_BINARY_DIR}/third_party/networking-ts/download)
configure_file(${NETWORKING_TS_PROJECT_FILE} ${NETWORKING_TS_DIR}/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${NETWORKING_TS_DIR}
        OUTPUT_FILE ${NETWORKING_TS_DIR}/download-log.txt)
if(result)
    message(FATAL_ERROR "networking-ts download failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${NETWORKING_TS_DIR}
    OUTPUT_FILE ${NETWORKING_TS_DIR}/build-log.txt)
if(result)
    message(FATAL_ERROR "Build step for networking-ts failed: ${result}")
endif()

add_library(networking-ts INTERFACE)

target_include_directories(networking-ts INTERFACE "${PROJECT_BINARY_DIR}/third_party/networking-ts/src/include/")
