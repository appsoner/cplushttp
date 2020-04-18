cmake_minimum_required(VERSION 3.10)
project(cplus2)

set(CMAKE_CXX_STANDARD 17)
#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
MESSAGE(STATUS PROJECT_BINARY_DIR:${PROJECT_BINARY_DIR})
MESSAGE(STATUS PROJECT_BINARY_DIR:${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_executable(hello main.cpp)

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "current platform: Linux ")
    TARGET_LINK_LIBRARIES(hello pthread boost_system stdc++fs uuid)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "current platform: Windows")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
    MESSAGE(STATUS "current platform: FreeBSD")
ELSE ()
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

MESSAGE(STSTUS "###################################")
