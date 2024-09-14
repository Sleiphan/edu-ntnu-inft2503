
set(EXECUTABLE "Exercise_4_1")
add_executable(${EXECUTABLE} Exercise_4_1.cpp)
target_include_directories(${EXECUTABLE} PUBLIC .)
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)
