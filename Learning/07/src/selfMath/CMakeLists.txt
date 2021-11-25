cmake_minimum_required(VERSION 3.8)

project(MathLibrary VERSION 0.0.1)

# Language
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Symbol visibility
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN TRUE)




add_library(selfMath SHARED
                        src/selfMath.cpp
                        src/selfMath.hpp
    )



include(GenerateExportHeader)
generate_export_header(selfMath)
                    
target_include_directories(selfMath
                    PUBLIC
                        src/
                        ${CMAKE_CURRENT_BINARY_DIR}/
    )