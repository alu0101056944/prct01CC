cmake_minimum_required(VERSION 3.0.0)
project(Assignment1 VERSION 0.1.0)

add_library(Assignment1Sources
    src/loadingbelt.cc)

add_executable(Assignment1 src/main.cc)

target_link_libraries(Assignment1 Assignment1Sources)
