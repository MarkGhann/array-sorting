cmake_minimum_required(VERSION 3.10)

project(MyArray)

# library
add_library(libsort ${CMAKE_CURRENT_SOURCE_DIR}/bubble-sort/bubble.cpp)

# exe
add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(main libsort)


add_custom_target( build_clean
        COMMAND echo "removing related files from build directory"
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/CMakeCache.txt
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/CTestTestfile.cmake
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/Makefile
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/cmake_install.cmake
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/liblibsort.a
        COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/main
        COMMAND echo "build directory cleaned"
)