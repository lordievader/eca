# Path to your arduino-cmake directory
set(CMAKE_ARDUINO_PATH ./arduino-cmake)
#set(CMAKE_MODULE_PATH ${CMAKE_ARDUINO_PATH}/cmake/Platform) # CMake module search path
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_ARDUINO_PATH}/cmake/ArduinoToolchain.cmake) # Arduino Toolchain

# Set the minimum required version of cmake for your project
cmake_minimum_required(VERSION 2.8)

# Set a variable for commands below
set(PROJECT_NAME arduino_eca)

# Define your project and language
project(${PROJECT_NAME} C CXX)

# Load settings for external arduino-cmake project
#find_package(Arduino 1.0 REQUIRED)

# Define your Arduino board (below is for Arduino Duemilanova)
set(${PROJECT_NAME}_BOARD uno)

# Define the source code
set(${PROJECT_NAME}_SRCS main.cpp)

# Define the port for uploading code to the Arduino
set(${PROJECT_NAME}_PORT /dev/ttyACM0)

# Command to generate code arduino firmware (.hex file)
generate_arduino_firmware(${PROJECT_NAME})

add_definitions(-DARDUINO_TARGET)

set(CMAKE_BUILD_TYPE Release)

## Compiler flags
if(CMAKE_COMPILER_IS_GNUCXX)
#     set(CMAKE_CXX_FLAGS "-Ofast -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -mmcu=atmega328p -save-temps -MD -MP -MF")
    set(CMAKE_CXX_FLAGS "-save-temps")
    set(CMAKE_EXE_LINKER_FLAGS "-s")  ## Strip binary
endif()
