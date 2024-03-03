//
// Created by carlosl on 27/02/24.
//

#ifndef SOLITARIOENCONSOLA_COLA_H
#define SOLITARIOENCONSOLA_COLA_H
#include "string"
#include "../Nodo/Nodo.h"

using namespace std;


class Cola {
private:
    Nodo *raiz;
    int contadorNum;
public:
    Cola();
    ~Cola();
    void insertar(Carta x);
    Carta extraer();
    void imprimir();
    int contador();
    Nodo * devolverRaiz();
    Carta mostrarValor();
};


#endif //SOLITARIOENCONSOLA_COLA_H
