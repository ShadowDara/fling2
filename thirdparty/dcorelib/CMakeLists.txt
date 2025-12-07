# dcorelib CMake configuration file
# by Shadowdara MIT 2025
# https://github.com/shadowdara/dcorelib

# Version 0.0.0

cmake_minimum_required(VERSION 3.16)
project(dcorelib)

add_library(dcorelib)
target_sources(dcorelib PRIVATE "src/dcorelib.cpp")
target_include_directories(dcorelib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
