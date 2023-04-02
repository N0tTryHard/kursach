cmake_minimum_required(VERSION 3.23)
project(kursach)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_MODULE_PATH /usr/local/cellar)

INCLUDE_DIRECTORIES(/usr/local/Cellar/jsoncpp/1.9.5/include)
LINK_DIRECTORIES(/usr/local/Cellar/jsoncpp/1.9.5/lib)

file(GLOB LIBRARIES "/usr/local/Cellar/jsoncpp/1.9.5/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

add_executable(kursach main.cpp Json_class.cpp Json_class.h)
TARGET_LINK_LIBRARIES(kursach ${LIBRARIES})