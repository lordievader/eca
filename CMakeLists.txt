cmake_minimum_required(VERSION 2.6)
project(eca)

add_executable(eca main.cpp)

install(TARGETS eca RUNTIME DESTINATION bin)
