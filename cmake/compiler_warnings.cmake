function (set_compiler_warnings _target)
if (MSVC)
    target_compile_options(${_target} PRIVATE /W4)
else()
    target_compile_options(${_target} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
endfunction()