cmake_minimum_required(VERSION 3.0.0)
project(vstest VERSION 0.1.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

SET(CMAKE_INCLUDE_PATH "/usr/include/postgresql")

include_directories( ${CMAKE_INCLUDE_PATH} "./timer" )

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -lm -lpq -lodbc -lstdc++ -fpermissive -Wall -pthread")

SET(CMAKE_C_FLAGS "-O0 -lm")

link_libraries(odbc pq)

##add_executable(vstest itemmain.cpp Inven.cpp)

#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_DIR}/src/)
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_DIR}/aa/)
#SET(CMAKE_CACHEFILE_DIR ${PROJECT_DIR}/aa/})


add_subdirectory(src)
#add_executable(100 bj.cpp)
