//
// Created by carlosl on 27/02/24.
//

#include "Cola.h"
#include<iostream>
#include <utility>

Cola::Cola()
{
    raiz = nullptr;
}

void Cola::insertar(Carta x) {
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->info = std::move(x);

    if (raiz == nullptr) {
        raiz = nuevo;
        nuevo->sig = nullptr;
    } else {
        raiz->info.ocultar= true;
        nuevo->sig = raiz;
        raiz = nuevo;
    }
}

void Cola::imprimir()
{
    std::cout << '\n';
    Nodo* reco = (raiz!= nullptr)? raiz: new Nodo();
    int contador = 0;
    cout << "Cola " <<endl;
    while (reco != nullptr) {
        contador ++;
        if (contador == 1){
            reco->info.ocultar = false;
        }
        if (reco->info.ocultar){
            cout << reco->info.cartaOculta << "-";
        } else {
            cout << reco->info.carta << "-";
        }
        reco = reco->sig;
        if (contador == 14){
            std::cout << '\n';
        }
    }
    std::cout << '\n';
    std::cout << '\n';
}

Carta Cola::extraer()
{
    if (raiz != nullptr)
    {
        Carta informacion = raiz->info;
        raiz = raiz->sig;
        return informacion;
    }
    else
    {
        return {};
    }
}

Cola::~Cola()
{
    Nodo *reco = raiz;
    Nodo *bor;
    while (reco != nullptr)
    {
        bor = reco;
        reco = reco->sig;
        delete bor;
    }
}
int Cola::contador() {
    contadorNum = 0;
    Nodo *reco = raiz;
    while (reco != nullptr)
    {
        reco = reco->sig;
        contadorNum++;
    }
    return contadorNum;
}

Nodo * Cola::devolverRaiz() {
    return raiz;
}

Carta Cola::mostrarValor()
{
    if (raiz != nullptr)
    {
        Carta informacion = raiz->info;
        return informacion;
    }
    else
    {
        return {};
    }
}