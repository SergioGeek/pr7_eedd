cmake_minimum_required(VERSION 3.8)
project(pr7_eedd)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp Diccionario.cpp Diccionario.h TextoPredictivo.cpp TextoPredictivo.h Palabra.cpp Palabra.h Sucesor.cpp Sucesor.h
        Usuario.cpp Usuario.h)
add_executable(pr7_eedd ${SOURCE_FILES})