
cmake_minimum_required(VERSION 3.13)
project(FlightSimulator)
set(CMAKE_CXX_STANDARD 17)

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()



set(GTEST_LIBS gtest gtest_main gmock gmock_main)

add_subdirectory(lib/gtest)
add_subdirectory(src)
add_subdirectory(tests)
include_directories(lib/gtest/googletest/include)
include_directories(lib/gtest/googlemock/include)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/glfw)
add_subdirectory(lib/glad)