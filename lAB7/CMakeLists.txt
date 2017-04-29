cmake_minimum_required(VERSION 3.7)
project(lAB7)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/Node.cpp )
set(HEADER_FILES inc/iTabAso.hh inc/Node.hhinc/zalaczniki.hh)
add_executable(lAB7 ${SOURCE_FILES} src/main.cpp src/Node.cpp src/TabAso.cpp)
link_libraries(lAB7 ${HEADER_FILES} inc/iTabAso.hh  inc/Node.hh inc/zalaczniki.hh inc/exceptions.hh)
