cmake_minimum_required(VERSION 2.6)
project(eca_test)

add_executable(eca_test main.cpp ecamatrix.cpp)

install(TARGETS eca_test RUNTIME DESTINATION bin)
