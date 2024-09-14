find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

set(EXECUTABLE "Exercise_4_1")
add_executable(${EXECUTABLE} Exercise_4_1.cpp)
target_include_directories(${EXECUTABLE} PUBLIC .)
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)

set(EXECUTABLE "Exercise_4_2")
add_executable(${EXECUTABLE} Exercise_4_2.cpp)
target_include_directories(${EXECUTABLE} PUBLIC .)
target_link_libraries(${EXECUTABLE} ${GTKMM_LIBRARIES})
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)
