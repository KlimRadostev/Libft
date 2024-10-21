set(LIBFT_ROOT ${CMAKE_SOURCE_DIR})
set(LIBFT_BUILD_ROOT ${LIBFT_ROOT}/build)
set(LIBFT_SOURCES_PATH ${LIBFT_ROOT}/src)
set(LIBFT_SOURCES)
set(LIBFT_INCLUDES)

project(libft)

add_compile_options(
    -Wall
    -Wextra
    -Wcast-align
    -Wmissing-field-initializers
    -Wnull-dereference
    -Wredundant-decls
    -Wshadow
    -Wswitch
    -Wswitch-default
    -Wunused
    -Wno-redundant-decls
    -Wno-psabi
    -Wl,nostdlib
    -Wl,nodefaultlibs
    -Werror
)

list(APPEND LIBFT_SOURCES
    ${LIBFT_SOURCES_PATH}/adjlist.c
)

list(APPEND LIBFT_INCLUDES ${LIBFT_ROOT}/include)

add_library()