//
// Created by carlosl on 27/02/24.
//

#ifndef SOLITARIOENCONSOLA_PILA_H
#define SOLITARIOENCONSOLA_PILA_H


#include "../Carta/Carta.h"
#include "../Nodo/Nodo.h"

class Pila {

    Nodo *raiz;
    int ordenamiento = 0;
public:
    int numPila = 0;
    Pila();
    ~Pila();
    void insertar(Carta x);
    void ingresar(Carta x);
    Carta extraer();
    bool revisar(string dato);
    void imprimir();
    void borrar();
    int contador();
    Carta mostrarValor();
    void mostrarPosValor(Pila *pila);
    Nodo * devolverRaiz();
};


#endif //SOLITARIOENCONSOLA_PILA_H
