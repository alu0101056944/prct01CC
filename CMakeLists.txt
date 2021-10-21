cmake_minimum_required(VERSION 3.0.0)
project(Assignment1 VERSION 0.1.0)

add_library(Assignment1Sources
    src/loadingbelt.cc)

add_executable(Assignment1 src/main.cc
                    src/filereader.cc
                    src/statefactory.cc
                    src/statetransition.cc
                    src/state.cc
                    src/stack.cc
                    src/loadingbelt.cc
                    src/automata.cc
              )

target_link_libraries(Assignment1 Assignment1Sources)
