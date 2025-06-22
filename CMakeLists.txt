cmake_minimum_required(VERSION 3.16.0)
project(glfx)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules")
set(CMAKE_DEBUG_POSTFIX "d")

set(GLFX_VERSION 0.7.5)

add_subdirectory(src)
