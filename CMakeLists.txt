cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 20)
project(color)

# Set source files
set ( SRC_FILES
    "src/ColorRGB.cpp"
    "src/ColorOkLab.cpp"
    "src/main.cpp"
)

# Set executable
add_executable(color ${SRC_FILES})

# Set include directories
target_include_directories(color PUBLIC "src/")