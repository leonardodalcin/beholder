# CMake last version
cmake_minimum_required(VERSION 3.12)

# Sets project name
project(beholder)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# Packages
find_package(Qt5Core)
find_package(Qt5PrintSupport REQUIRED)

# CPP 17 newest CPP
set(CMAKE_CXX_STANDARD 17)

# Include project files
add_executable(beholder main.cpp sources/roi/roi.cpp headers/roi/roi.hpp sources/image_loader/image_loader.cpp headers/image_loader/image_loader.hpp)

#
qt5_use_modules(${PROJECT_NAME} Widgets)

#
target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::PrintSupport)


