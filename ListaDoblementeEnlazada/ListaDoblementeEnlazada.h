//
// Created by carlosl on 27/02/24.
//

#ifndef SOLITARIOENCONSOLA_LISTADOBLEMENTEENLAZADA_H
#define SOLITARIOENCONSOLA_LISTADOBLEMENTEENLAZADA_H


#include "../Carta/Carta.h"
#include "../Nodo/Nodo.h"

class ListaDoblementeEnlazada {
private:
    Nodo *raiz;
public:
    ListaDoblementeEnlazada();
    ~ListaDoblementeEnlazada();
    int cantidad();
    void insertar(int pos, Carta x);
    void ingresar( Carta x);
    Carta extraer(int pos);
    void borrar(int pos);
    void intercambiar(int pos1, int pos2);
    bool vacia();
    void imprimir();
    bool existe(string x);
    Nodo * devolverRaiz();
    Carta mostrarValor();
    Carta consultar(int pos);
    int cartasSeleccionables();
};


#endif //SOLITARIOENCONSOLA_LISTADOBLEMENTEENLAZADA_H
