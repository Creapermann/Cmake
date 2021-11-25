cmake_minimum_required(VERSION 3.8)

project(calculator VERSION 0.0.1)

# Language
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



add_subdirectory(src/selfMath)



add_executable(app 
                src/app/main.cpp
    )

target_include_directories(app
            PRIVATE
                src/app/view
                src/app/viewModel
                src/app/model
    )
            
target_link_libraries(app
                PRIVATE
                    selfMath
    )