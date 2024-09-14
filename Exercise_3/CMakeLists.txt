
set(EXECUTABLE "Exercise_3_2")
add_executable(${EXECUTABLE} Exercise_3_2.cpp Exercise_3_1.cpp)
target_include_directories(${EXECUTABLE} PUBLIC .)
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)

set(EXECUTABLE "Exercise_3_3")
add_executable(${EXECUTABLE} Exercise_3_3.cpp commodity.cpp)
target_include_directories(${EXECUTABLE} PUBLIC .)
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)

set(EXECUTABLE "Exercise_3_4")
add_executable(${EXECUTABLE} Exercise_3_4.cpp)
target_include_directories(${EXECUTABLE} PUBLIC .)
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)