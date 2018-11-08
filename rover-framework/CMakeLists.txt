set(name "rover-framework")

set(src_files 
    "src/empty.cpp"
    "src/empty.h")

add_library(${name} ${src_files})

set_target_properties(${name} PROPERTIES FOLDER "rover")