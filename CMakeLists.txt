cmake_minimum_required(VERSION 2.8)

project(snakefan)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(COMMON_SRC
    "game.cpp"
    "main.cpp"
    "vector2.cpp"
    "timer.cpp"
    "ui/elements.cpp"
    "ui/ui.cpp"
    "ui/uiSdl.cpp"
    "ui/renderer.cpp"
    "ui/event.cpp"
    )

include_directories(
    "."
    )
set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
add_executable(${CMAKE_PROJECT_NAME} ${COMMON_SRC})

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIBRARY_DIRS} ${LIBRARY_DIRS})
add_definitions(${SDL2_DEFINITIONS})

target_link_libraries(${CMAKE_PROJECT_NAME}
    ${SDL2_LIBRARIES}
    )
