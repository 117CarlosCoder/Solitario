//
// Created by carlosl on 27/02/24.
//

#ifndef SOLITARIOENCONSOLA_PILA_H
#define SOLITARIOENCONSOLA_PILA_H


#include "../Carta/Carta.h"

class Pila {
    class Nodo {
    public:
        Carta info;
        Nodo *sig;
    };

    Nodo *raiz;
    int contadorNum = 0;
    int ordenamiento = 0;
public:
    Pila();
    ~Pila();
    void insertar(Carta x);
    Carta extraer();
    bool revisar(string dato);
    void imprimir();
    int contador();
    Carta mostrarValor();
    Nodo * devolverRaiz();
};


#endif //SOLITARIOENCONSOLA_PILA_H
