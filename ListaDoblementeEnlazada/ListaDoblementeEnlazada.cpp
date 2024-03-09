//
// Created by carlosl on 27/02/24.
//

#include "ListaDoblementeEnlazada.h"

//
// Created by carlosl on 26/02/24.
//

#include "ListaDoblementeEnlazada.h"
#include "string"
#include "iostream"
#include "../Pila/Pila.h"

using namespace std;

ListaDoblementeEnlazada::ListaDoblementeEnlazada()
{
    raiz = nullptr;
}

ListaDoblementeEnlazada::~ListaDoblementeEnlazada()
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

void ListaDoblementeEnlazada::borrarTodo()
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

int ListaDoblementeEnlazada::cantidad()
{
    Nodo *reco = raiz;
    int cant = 0;
    while (reco != nullptr)
    {
        cant++;
        reco = reco->sig;
    }
    return cant;
}

int ListaDoblementeEnlazada::cartasSeleccionables()
{
    Nodo *reco = raiz;
    int cant = 0;
    while (reco != nullptr)
    {
        if (!reco->info.ocultar){
            cant++;
        }
        reco = reco->sig;
    }
    return cant;
}

void ListaDoblementeEnlazada::insertar(int pos, Carta x)
{
    if (pos <= cantidad() + 1)
    {
        Nodo *nuevo = new Nodo();
        nuevo->info = x;
        if (pos == 1)
        {
            nuevo->sig = raiz;
            if (raiz != nullptr)
                raiz->ant = nuevo;
            raiz = nuevo;
        }
        else
        if (pos == cantidad() + 1)
        {
            Nodo *reco = raiz;
            while (reco->sig != nullptr)
            {
                reco = reco->sig;
            }
            reco->sig = nuevo;
            nuevo->ant = reco;
            nuevo->sig = nullptr;
        }
        else
        {
            Nodo *reco = raiz;
            for (int f = 1; f <= pos - 2; f++)
                reco = reco->sig;
            Nodo *siguiente = reco->sig;
            reco->sig = nuevo;
            nuevo->ant = reco;
            nuevo->sig = siguiente;
            siguiente->ant = nuevo;
        }
    }
}

void ListaDoblementeEnlazada::ingresar(Carta x) {
    Nodo* nuevo = new Nodo();
    nuevo->info = std::move(x);
    if (raiz == nullptr) {
        raiz = nuevo;
    } else {
            nuevo->sig = raiz;
            raiz->ant = nuevo;
            raiz = nuevo;
    }
}


Carta ListaDoblementeEnlazada::extraer(int pos)
{
    if (pos <= cantidad())
    {
        Carta informacion;
        Nodo *bor;
        if (pos == 1)
        {
            informacion = raiz->info;
            bor = raiz;
            raiz = raiz->sig;
            if ((raiz != nullptr))
                raiz->ant = nullptr;
        }
        else
        {
            Nodo *reco;
            reco = raiz;
            for (int f = 1; f <= pos - 2; f++)
                reco = reco->sig;
            Nodo *prox = reco->sig;
            bor = prox;
            reco->sig = prox->sig;
            Nodo *siguiente = prox->sig;
            if (siguiente != nullptr)
                siguiente->ant = reco;
            informacion = prox->info;
        }
        return informacion;
    }
    else
        return {};
}

void ListaDoblementeEnlazada::borrar(int pos)
{
    if (pos <= cantidad())
    {
        Nodo *bor;
        if (pos == 1)
        {
            bor = raiz;
            raiz = raiz->sig;
            if (raiz != nullptr)
                raiz->ant = nullptr;
        }
        else
        {
            Nodo *reco;
            reco = raiz;
            for (int f = 1; f <= pos - 2; f++)
                reco = reco->sig;
            Nodo *prox = reco->sig;
            bor = prox;
            reco->sig = prox->sig;
            Nodo *siguiente = prox->sig;
            if (siguiente != nullptr)
                siguiente->ant = reco;
        }
        delete bor;
    }
}


void ListaDoblementeEnlazada::intercambiar(int pos1, int pos2)
{
    if (pos1 <= cantidad() && pos2 <= cantidad())
    {
        Nodo *reco1 = raiz;
        for (int f = 1; f < pos1; f++)
        {
            reco1 = reco1->sig;
        }
        Nodo *reco2 = raiz;
        for (int f = 1; f < pos2; f++)
        {
            reco2 = reco2->sig;
        }
        Carta aux = reco1->info;
        reco1->info = reco2->info;
        reco2->info = aux;
    }
}

bool ListaDoblementeEnlazada::vacia()
{
    if (raiz == nullptr)
        return true;
    else
        return false;
}

Nodo * ListaDoblementeEnlazada::devolverRaiz() {
    return raiz;
}


void ListaDoblementeEnlazada::imprimir()
{
    int contar = 0;
    Nodo *reco = raiz;
    cout << "Baraja  "<< numLista<<endl;
    while (reco != nullptr)
    {
        contar++;
        if (contar == 1){
            reco->info.ocultar = false;
        }
        if (reco->info.ocultar){
            cout << reco->info.cartaOculta << "-";
        } else {
            cout << reco->info.carta << "-";
        }
        reco = reco->sig;
    }
    cout << "\n";
}



bool ListaDoblementeEnlazada::existe(string x)
{
    Nodo *reco = raiz;
    while (reco != nullptr)
    {
        if (reco->info.carta == x)
            return true;
        reco = reco->sig;
    }
    return false;
}

Carta ListaDoblementeEnlazada::mostrarValor()
{
        Carta informacion;
        informacion = raiz->info;
        return informacion;
}

Carta ListaDoblementeEnlazada::consultar(int pos)
{

        if(pos != 0) {
            Nodo *reco = raiz;
            for (int f = 1; f < pos; f++) {
                if (pos == 1) {
                    return reco->info;
                } else {
                    reco = reco->sig;
                }
            }
            cout << "Carta de consulta " << reco->info.carta;
            return reco->info;
        }
    return {};
   }

void ListaDoblementeEnlazada::mostrarPosValor(Pila *pilacopia)
{
    Carta informacion;
        Nodo *reco = raiz;
        while (reco != nullptr) {
            informacion = reco->info;
            pilacopia->ingresar(informacion);
            reco = reco->sig;


    }
}

