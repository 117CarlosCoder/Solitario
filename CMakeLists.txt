cmake_minimum_required(VERSION 3.27)
project(SolitarioEnConsola)

set(CMAKE_CXX_STANDARD 17)

add_executable(main.cpp
        ListaDoblementeEnlazada/ListaDoblementeEnlazada.h
        ListaDoblementeEnlazada/ListaDoblementeEnlazada.cpp
        Nodo/Nodo.h
        Nodo/Nodo.cpp
        Carta/Carta.h
        Carta/Carta.cpp
        Cola/Cola.h
        Cola/Cola.cpp
        Pila/Pila.h
        Pila/Pila.cpp)
