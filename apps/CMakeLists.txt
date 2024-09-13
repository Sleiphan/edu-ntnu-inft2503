set(EXECUTABLE "Exercise_1_a")
add_executable(${EXECUTABLE} Exercise_1_a.cpp)
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)

set(EXECUTABLE "Exercise_1_b")
add_executable(${EXECUTABLE} Exercise_1_b.cpp)
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)

set(EXECUTABLE "Exercise_2_1_a")
add_executable(${EXECUTABLE} Exercise_2_1_a.cpp)
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)

set(EXECUTABLE "Exercise_2_1_b")
add_executable(${EXECUTABLE} Exercise_2_1_b.cpp)
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)

set(EXECUTABLE "Exercise_2_4")
add_executable(${EXECUTABLE} Exercise_2_4.cpp)
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)

set(EXECUTABLE "Exercise_2_5")
add_executable(${EXECUTABLE} Exercise_2_5.cpp)
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)

set(EXECUTABLE "Exercise_2_6")
add_executable(${EXECUTABLE} Exercise_2_6.cpp)
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)
