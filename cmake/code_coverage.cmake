add_library(rover-coverage INTERFACE)

if (ENABLE_COVERAGE)
    if (MSVC)
        message(WARNING "Code coverage not supported for MSVC")
    else()
        target_compile_options(rover-coverage INTERFACE --coverage -O0 -g)
        target_link_libraries(rover-coverage INTERFACE --coverage)
    endif()
endif()