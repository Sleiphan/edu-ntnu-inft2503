
set(EXECUTABLE "Exercise_5_1")
add_executable(${EXECUTABLE} Exercise_5_1.cpp chessboard.cpp)
target_include_directories(${EXECUTABLE} PUBLIC .)
target_link_libraries(${EXECUTABLE} ${GTKMM_LIBRARIES})
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)

set(EXECUTABLE "Exercise_5_2")
add_executable(${EXECUTABLE} Exercise_5_2.cpp chessboard.cpp)
target_include_directories(${EXECUTABLE} PUBLIC .)
target_link_libraries(${EXECUTABLE} ${GTKMM_LIBRARIES})
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)
