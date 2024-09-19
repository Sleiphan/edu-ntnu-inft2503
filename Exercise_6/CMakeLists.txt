find_package(Boost REQUIRED COMPONENTS filesystem system) # Specify the Boost components you need

set(EXECUTABLE "Exercise_6_1")
add_executable(${EXECUTABLE} Exercise_6_1.cpp chessboard.cpp chessboard_print.cpp)
target_include_directories(${EXECUTABLE} PUBLIC .)
target_link_libraries(${EXECUTABLE})
set_target_properties(${EXECUTABLE}
    PROPERTIES
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)

set(EXECUTABLE "Exercise_6_2")
add_executable(${EXECUTABLE} Exercise_6_2.cpp chessboard.cpp)
target_include_directories(${EXECUTABLE} PUBLIC .)
target_link_libraries(${EXECUTABLE} Boost::filesystem Boost::system)
set_target_properties(${EXECUTABLE}
    PROPERTIES
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)
