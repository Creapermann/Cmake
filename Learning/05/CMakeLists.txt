cmake_minimum_required(VERSION 3.9)

project(mytest VERSION 1.0)

# language standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_subdirectory(libs/FTXUI)


add_executable(app src/main.cpp)

target_link_libraries(app PRIVATE
                          screen
                          dom
                          component)
                      
target_include_directories(app PRIVATE 
                               inc/ftxui/component
                               inc/ftxui/dom
                               inc/ftxui/screen
                               inc/ftxui/util)