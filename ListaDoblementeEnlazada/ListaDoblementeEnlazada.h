//
// Created by carlosl on 27/02/24.
//

#ifndef SOLITARIOENCONSOLA_LISTADOBLEMENTEENLAZADA_H
#define SOLITARIOENCONSOLA_LISTADOBLEMENTEENLAZADA_H


#include "../Carta/Carta.h"
#include "../Nodo/Nodo.h"
#include "../Pila/Pila.h"

class ListaDoblementeEnlazada {
private:
    Nodo *raiz;
public:
    int numLista = 0;
    ListaDoblementeEnlazada();
    ~ListaDoblementeEnlazada();
    int cantidad();
    void insertar(int pos, Carta x);
    void ingresar( Carta x);
    Carta extraer(int pos);
    void borrar(int pos);
    void borrarTodo();
    void intercambiar(int pos1, int pos2);
    bool vacia();
    void imprimir();
    bool existe(string x);
    Nodo * devolverRaiz();
    Carta mostrarValor();
    void mostrarPosValor( Pila *pilacopia);
    Carta consultar(int pos);
    int cartasSeleccionables();
};


#endif //SOLITARIOENCONSOLA_LISTADOBLEMENTEENLAZADA_H
