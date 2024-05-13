cmake_minimum_required(VERSION 3.0)

project(BluVEngine)

SET(
    SOURCES

    Source.cpp
    Engine.cpp
    GUI.cpp
    Input.cpp
    Object.cpp
    ResManager.cpp
    TextObject.cpp
    Utility.cpp
    BluVEditor.cpp
)

add_executable(BluVEngine ${SOURCES})

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(BluVEngine sfml-graphics sfml-window sfml-system)