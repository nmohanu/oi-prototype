cmake_minimum_required(VERSION 3.0)

project(prototype-oi)

add_executable(prototype-oi main.cpp)

install(TARGETS prototype-oi RUNTIME DESTINATION bin)
