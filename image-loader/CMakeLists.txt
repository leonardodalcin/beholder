cmake_minimum_required(VERSION 2.8.12)

project(image_loager)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)
find_package(Qt5PrintSupport REQUIRED)


add_executable(${PROJECT_NAME} "main.cpp" "imageloader.cpp")
qt5_use_modules(${PROJECT_NAME} Widgets)

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::PrintSupport)


