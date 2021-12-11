cmake_minimum_required(VERSION 3.20)

project(Learning VERSION 0.0.1
                 LANGUAGES CXX
    )


# Languages
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS FALSE)


############################### google test ######################################
include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        054a986a8513149e8374fc669a5fe40117ca6b41
    )

FetchContent_MakeAvailable(googletest)
##################################################################################


add_executable(app
                    src/main.cpp
    )

target_include_directories(app
                    PRIVATE
                            src/
)

target_link_libraries(app
                    PRIVATE
                        gtest
    )