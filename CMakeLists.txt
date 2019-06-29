cmake_minimum_required(VERSION 3.4)
project(audio_streamer)

set(Boost_INCLUDE_DIR /usr/local/include)
set(Boost_LIBRARY_DIR /usr/local/lib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build")

FIND_PACKAGE( Boost 1.65 COMPONENTS system thread REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )


add_executable(server src/utils.cpp src/network_manager.cpp src/thread_handler.cpp src/test_filetransfer.cpp src/client_handler.cpp)
add_executable(client src/client.cpp src/network_manager.cpp)
TARGET_LINK_LIBRARIES( server ${Boost_LIBRARIES} )
TARGET_LINK_LIBRARIES( client ${Boost_LIBRARIES} )
