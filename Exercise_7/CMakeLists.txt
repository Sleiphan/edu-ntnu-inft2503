set(EXECUTABLE "Exercise_7_1_a")
add_executable(${EXECUTABLE} Exercise_7_1_a.cpp Fraction.cpp)
target_include_directories(${EXECUTABLE} PUBLIC .)
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)