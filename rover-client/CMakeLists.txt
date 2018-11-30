set(name "rover-client")

set(src_files
    "src/main.cpp")

add_executable(${name} ${src_files})

source_group("src" FILES ${src_files})

target_compile_features(${name} INTERFACE cxx_std_17)

target_link_libraries(${name} PRIVATE "rover-framework")
target_link_libraries(${name} PRIVATE "rover-warnings")

target_include_directories(${name} PUBLIC "../rover-framework/include")

set_target_properties(${name} PROPERTIES FOLDER "rover")
cotire(${name})