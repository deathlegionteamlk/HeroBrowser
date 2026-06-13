cmake_minimum_required(VERSION 3.10)
project(HeroBrowser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets WebEngineWidgets REQUIRED)

add_executable(HeroBrowser
    main.cpp
    browser_window.cpp
    browser_window.h
)

target_link_libraries(HeroBrowser
    Qt5::Widgets
    Qt5::WebEngineWidgets
)
