cmake_minimum_required(VERSION 3.7...3.26)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(edu_ntnu_inft2503
    VERSION 0.1
    DESCRIPTION "An example project."
    LANGUAGES C CXX)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Setting compiler flags for Windows")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Setting compiler flags for Linux")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pedantic -Wall -Wextra")
endif()

set(CMAKE_PDB_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/pdb)

add_subdirectory(Exercise_1)
add_subdirectory(Exercise_2)
add_subdirectory(Exercise_3)
add_subdirectory(Exercise_4)
add_subdirectory(Exercise_5)
add_subdirectory(Exercise_6)
add_subdirectory(Exercise_7)
add_subdirectory(Exercise_8)
