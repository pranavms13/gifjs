cmake_minimum_required(VERSION 2.6)
project(gifjs)

set (VERSION 1.1)
set (AUTHOR Pranav M S)
set (HOMEPAGE https://github.com/pranavms13/gifjs)

configure_file (
    "${PROJECT_SOURCE_DIR}/meta.h.in"
    "${PROJECT_BINARY_DIR}/meta.h"
)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(gifjs main.c gif.c)
