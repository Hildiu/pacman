﻿cmake_minimum_required(VERSION 3.13)
project(pacman)

# Archivos del Projecto
set(PROJECT_SOURCE
        main.cpp
        Udefiniciones.h CRectangulo.cpp CRectangulo.h CFigura.cpp CFigura.h CGame.cpp CGame.h )

# C++ Standard se sugiere 11 o 14
set(CMAKE_CXX_STANDARD 14)

set(SFML_ROOT "~/DevLibraries/SFML-2.5.1-macOS-clang")

set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
set(SFML_LIBRARY_DIR "${SFML_ROOT}/lib")

if (APPLE)
    set(SFML_DIR "${SFML_ROOT}/Frameworks/SFML.framework/Resources/CMake")
else()
    set(SFML_DIR "${SFML_ROOT}/lib/CMake/SFML")
endif()

link_directories(${SFML_LIBRARY_DIR})
include_directories(${SFML_INCLUDE_DIR})

# Instrucciones para generar el ejecutable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})

find_package(SFML 2.5.1
        COMPONENTS
            system
            window
            graphics
        REQUIRED)

target_link_libraries (${PROJECT_NAME}
        sfml-system
        sfml-window
        sfml-graphics
        )
