cmake_minimum_required(VERSION 3.0)

project(prototype-oi)

# Set C++ standard to 17
set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS system audio REQUIRED)

add_executable(prototype-oi main.cpp)

target_link_libraries(prototype-oi PRIVATE sfml-system sfml-audio)

install(TARGETS prototype-oi RUNTIME DESTINATION bin)
