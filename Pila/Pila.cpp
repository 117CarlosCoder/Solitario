//
// Created by carlosl on 27/02/24.
//

#include "Pila.h"
#include <iostream>
#include <utility>

using namespace std;

Pila::Pila()
{
    raiz = nullptr;
}

void Pila::insertar(Carta x)
{
    ordenamiento++;
    if (ordenamiento == x.valor) {
        Nodo *nuevo;
        nuevo = new Nodo();
        nuevo->info = std::move(x);
        if (raiz == nullptr) {
            raiz = nuevo;
            nuevo->sig = nullptr;
        } else {
            nuevo->sig = raiz;
            raiz = nuevo;
        }
    }
}

void Pila::ingresar(Carta x)
{
        Nodo *nuevo;
        nuevo = new Nodo();
    if (x.valor) {
        nuevo->info = std::move(x);
        if (raiz == nullptr) {
            raiz = nuevo;
            nuevo->sig = nullptr;
        } else {
            nuevo->sig = raiz;
            raiz = nuevo;
        }
    }
}

bool Pila::revisar(string dato){
    Nodo *reco = raiz;
    while (reco != nullptr){
        if(reco->info.carta == dato){
            return false;
        }
        reco = reco->sig;
    }
    return true;
}

void Pila::imprimir()
{
    cout<<'\n';
    Nodo *reco = raiz;
    cout<<"Pila " << numPila <<endl;
    while (reco != nullptr)
    {
        cout << reco->info.carta << " - ";
        reco = reco->sig;
    }
    cout<<'\n';
    cout<<'\n';
}

Carta Pila::extraer()
{
    if (raiz != nullptr)
    {
        Carta informacion = raiz->info;
        //Nodo *bor = raiz;
        raiz = raiz->sig;
        return informacion;
    }
    else
    {
        return {};
    }
}

Pila::~Pila()
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

Nodo * Pila::devolverRaiz() {
    return raiz;
}

int Pila::contador() {
    int contadorNum = 0;
    Nodo *reco = raiz;
    while (reco != nullptr)
    {
        reco = reco->sig;
        contadorNum++;
    }
    return contadorNum;
}

Carta Pila::mostrarValor()
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

void Pila::mostrarPosValor(Pila *pilacopia)
{
    Carta informacion;
    Nodo *reco = raiz;
    while (reco!= nullptr){
        informacion = reco->info;
        pilacopia->ingresar(informacion);
        reco = reco->sig;

    }
}

void Pila::borrar()
{
    Nodo *reco;
    while(raiz != nullptr)
    {
        reco = raiz;
        raiz = raiz->sig;
        delete reco;
    }

}