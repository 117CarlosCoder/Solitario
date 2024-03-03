//
// Created by carlosl on 27/02/24.
//

#ifndef SOLITARIOENCONSOLA_NODO_H
#define SOLITARIOENCONSOLA_NODO_H


#include "../Carta/Carta.h"

class Nodo {
public:
    Carta info;
    Nodo *sig;
    Nodo *ant;
};


#endif //SOLITARIOENCONSOLA_NODO_H
