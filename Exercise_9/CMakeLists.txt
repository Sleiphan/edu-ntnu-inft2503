set(EXECUTABLE "Exercise_9")
add_executable(${EXECUTABLE} Exercise_9.cpp)
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)