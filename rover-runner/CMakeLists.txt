set(name "rover-runner")

set(src_files
    "src/main.cpp")

add_executable(${name} ${src_files})

target_link_libraries(${name} "rover-framework")

set_target_properties(${name} PROPERTIES FOLDER "rover")