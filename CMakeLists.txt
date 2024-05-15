# Declare minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Declare your project
project(SDLGame)

# Find the SDL2 package
find_package(SDL2 REQUIRED)

# Include SDL2 to the project
include_directories(${SDL2_INCLUDE_DIRS})

# Add your source file, for example, main.cpp
add_executable(SDLGame main.cpp)

# Link SDL2 to your project
target_link_libraries(SDLGame ${SDL2_LIBRARIES})

