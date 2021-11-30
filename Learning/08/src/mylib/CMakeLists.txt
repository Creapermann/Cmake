cmake_minimum_required(VERSION 3.22)

project(mylib VERSION 0.0.1)

# Language
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

# Visiblity
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN TRUE)



# Create library
add_library(mylib SHARED
                    src/MyLib.cpp
                    src/MyLib.hpp
    )
                
target_include_directories(mylib 
                    PUBLIC
                        src/
                        ${CMAKE_CURRENT_BINARY_DIR}/
    )


# Export-Header
include(GenerateExportHeader)
generate_export_header(mylib)