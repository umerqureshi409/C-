cmake_minimum_required(VERSION 3.10)

project(CalculatorApp)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt5Widgets REQUIRED)

add_executable(CalculatorApp main.cpp Calculator.cpp)

target_link_libraries(CalculatorApp Qt5::Widgets)
