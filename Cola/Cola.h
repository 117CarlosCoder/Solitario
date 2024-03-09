//
// Created by carlosl on 27/02/24.
//

#ifndef SOLITARIOENCONSOLA_COLA_H
#define SOLITARIOENCONSOLA_COLA_H
#include "string"
#include "../Nodo/Nodo.h"
#include "../Pila/Pila.h"

using namespace std;


class Cola {
private:
    Nodo *raiz;
    int contadorNum;
public:
    int numCola = 0;
    Cola();
    ~Cola();
    void insertar(Carta x);
    Carta extraer();
    void imprimir();
    void borrar();
    int contador();
    Nodo * devolverRaiz();
    Carta mostrarValor();
    void mostrarPosValor(Pila *pilacopia);
};


#endif //SOLITARIOENCONSOLA_COLA_H
