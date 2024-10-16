set(EXECUTABLE "Exercise_8_1")
add_executable(${EXECUTABLE} Exercise_8_1.cpp)
target_include_directories(${EXECUTABLE} PUBLIC . ${Boost_INCLUDE_DIRS})
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)

set(EXECUTABLE "Exercise_8_2")
add_executable(${EXECUTABLE} Exercise_8_2.cpp)
target_include_directories(${EXECUTABLE} PUBLIC .)
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)