set(name "rover-runner")

set(src_files
    "src/main.cpp")

add_executable(${name} ${src_files})

source_group("src\\main" FILES ${src_files})

target_link_libraries(${name} "rover-framework")

target_include_directories(${name} PUBLIC "../rover-framework/include")

set_target_properties(${name} PROPERTIES FOLDER "rover")