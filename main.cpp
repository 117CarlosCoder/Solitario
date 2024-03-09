#include <iostream>
#include <random>
#include <algorithm>
#include <utility>
#include "Carta/Carta.h"
#include "Nodo/Nodo.h"
#include "ListaDoblementeEnlazada/ListaDoblementeEnlazada.h"
#include "Cola/Cola.h"
#include "Pila/Pila.h"

using namespace std;

void ingresarCartas( ListaDoblementeEnlazada *lista, int catidadCartas, Carta cartas[], int indice){
        for (int i = indice; i < catidadCartas; ++i) {
            if (i == catidadCartas-1) {
                cartas[i].ocultar = false;
            }
            lista->ingresar(cartas[i]);
        }
}

void ingresarCartasColas( Cola *cola, int catidadCartas, Carta cartas[], int indice){
    for (int i = indice; i < catidadCartas; ++i) {
            if (i == catidadCartas - 1) {
                cartas[i].ocultar = false;
            }
            cola->insertar(cartas[i]);
    }

}

void imprimirCartas(Cola *cola1, Cola *cola2, Pila *pila1, Pila *pila2, Pila *pila3, Pila *pila4, ListaDoblementeEnlazada *lista1,ListaDoblementeEnlazada *lista2, ListaDoblementeEnlazada *lista3, ListaDoblementeEnlazada *lista4, ListaDoblementeEnlazada *lista5, ListaDoblementeEnlazada *lista6, ListaDoblementeEnlazada *lista7){
    cola1->imprimir();
    cola2->imprimir();
    pila1->imprimir();
    pila2->imprimir();
    pila3->imprimir();
    pila4->imprimir();
    lista1->imprimir();
    lista2->imprimir();
    lista3->imprimir();
    lista4->imprimir();
    lista5->imprimir();
    lista6->imprimir();
    lista7->imprimir();
}

void cambiarCartasCola(Cola *cola, Pila *pilaCambio, Cola *colaCambio, ListaDoblementeEnlazada *listaCambio, int tipo){

    if(tipo == 1){
        if (cola == nullptr){
            return;
        }
        if(pilaCambio->devolverRaiz() == nullptr){
            return pilaCambio->insertar(std::move(cola->extraer()));
        }
        if(pilaCambio->devolverRaiz()->info.valor+1 ==  cola->devolverRaiz()->info.valor && pilaCambio->devolverRaiz()->info.color ==  cola->devolverRaiz()->info.color && pilaCambio->mostrarValor().tipo == cola->devolverRaiz()->info.tipo )  {
            pilaCambio->insertar(std::move(cola->extraer()));
        }

    }
    if(tipo == 2){
        if (cola == nullptr){
            return;
        }
        colaCambio->insertar(std::move(cola->extraer()));
    }
    if(tipo == 3){
        if (cola == nullptr){
            return;
        }
        if(listaCambio->devolverRaiz() == nullptr){
            return listaCambio->ingresar(std::move(cola->extraer()));
        }
        if(listaCambio->devolverRaiz()->info.valor-1 == cola->devolverRaiz()->info.valor && listaCambio->devolverRaiz()->info.color != cola->devolverRaiz()->info.color) {
            listaCambio->ingresar(std::move(cola->extraer()));
        }
    }
}

void cambiarCartasLista(ListaDoblementeEnlazada *lista , Pila *pilaCambio, Cola *colaCambio, ListaDoblementeEnlazada *listaCambio, int tipo, int pos){
    if(tipo == 1){
        if (lista == nullptr){
            return;
        }
        if(pilaCambio->devolverRaiz() == nullptr){
            return pilaCambio->insertar(std::move(lista->extraer(1)));
        }
        if(pilaCambio->devolverRaiz()->info.valor+1 ==  lista->devolverRaiz()->info.valor && pilaCambio->devolverRaiz()->info.color ==  lista->devolverRaiz()->info.color && pilaCambio->devolverRaiz()->info.tipo == lista->devolverRaiz()->info.tipo )  {
            pilaCambio->insertar(std::move(lista->extraer(1)));
        }
    }
    if(tipo == 2){
        if (lista == nullptr){
            return;
        }
        colaCambio->insertar(std::move(lista->extraer(1)));
    }
    if(tipo == 3){
        if (lista == nullptr){
            return;
        }
        if(listaCambio->devolverRaiz() == nullptr && lista->consultar(pos).valor == 13){
            return listaCambio->ingresar(std::move(lista->extraer(pos)));
        }
        if(listaCambio->devolverRaiz() == nullptr){
            return;
        }
        if(listaCambio->devolverRaiz()->info.valor-1 == lista->consultar(pos).valor && listaCambio->devolverRaiz()->info.color != lista->consultar(pos).color) {
            listaCambio->ingresar(std::move(lista->extraer(pos)));
        }
    }
}

void generarCopiaAnterior(Cola *cola,Pila *pila, ListaDoblementeEnlazada *lista, Pila *pilaCopia, int tipo){
    Carta cambio;
    if (tipo == 1){
        cola->mostrarPosValor(pilaCopia);
    }
    if (tipo == 2){
        pila->mostrarPosValor(pilaCopia);
    }
    if (tipo == 3){
        //lista->mostrarPosValor(pilaCopia);
    }
}

void restaurarCopia(Cola *cola,Pila *pila, ListaDoblementeEnlazada *lista, Pila *pilaCopia, int tipo){
    if (tipo == 1){
        cout<<"Entrando restauracion"<<endl;
        cout<<pilaCopia->devolverRaiz()<<endl;
        while(pilaCopia->devolverRaiz() != nullptr){
            cout<<"REstaurar"<<endl;
            cola->insertar(pilaCopia->extraer());
        }
    }
    if (tipo == 2){
        for (int i = 0; i < pila->contador(); i++ ){
            pila->insertar(pilaCopia->extraer());
        }
    }
    if (tipo == 3){
        for (int i = 0; i < lista->cantidad(); i++ ){
            lista->insertar(1,pilaCopia->extraer());
        }
    }
}

void solitario(){

    Carta cartas[] = { 1,"A<3R","****","R","C",true,
                       2,"2<3R","****","R","C",true,
                       3,"3<3R","****","R","C",true,
                       4,"4<3R","****","R","C", true,
                       5,"5<3R","****","R","C",true,
                       6, "6<3R","****","R","C",true,
                       7,"7<3R","****","R","C", true,
                       8,"8<3R","****","R","C", true,
                       9,"9<3R","****","R","C", true,
                       10,"10<3R","****","R","C",true,
                       11,"J<3R","****","R","C",true,
                       12,"Q<3R","****","R","C", true,
                       13,"K<3R", "****","R","C",true,
                       1, "A<>R", "****","R","D", true,
                       2, "2<>R", "****","R","D",true,
                       3, "3<>R", "****","R","D",true,
                       4, "4<>R", "****","R","D",true,
                       5, "5<>R", "****","R","D",true,
                       6, "6<>R", "****","R","D",true,
                       7, "7<>R", "****","R","D",true,
                       8, "8<>R", "****","R","D",true,
                       9, "9<>R", "****","R","D",true,
                       10, "10<>R", "****","R","D",true,
                       11, "J<>R", "****","R","D",true,
                       12, "Q<>R","****","R", "D",true,
                       13, "K<>R", "****","R","D",true,
                       1, "AE3N","****","N","T", true,
                       2, "2E3N", "****","N","T",true,
                       3, "3E3N", "****","N","T",true,
                       4, "4E3N", "****","N","T",true,
                       5, "5E3N", "****","N","T",true,
                       6, "6E3N", "****","N","T",true,
                       7, "7E3N", "****","N","T",true,
                       8, "8E3N", "****","N","T",true,
                       9, "9E3N", "****","N","T",true,
                       10, "10E3N","****","N","T",true,
                       11, "JE3N", "****","N","T",true,
                       12, "QE3N", "****","N","T",true,
                       13, "KE3N", "****","N","T",true,
                       1, "A!!N","****","N","E", true,
                       2, "2!!N", "****","N","E",true,
                       3, "3!!N", "****","N","E",true,
                       4, "4!!N", "****","N","E",true,
                       5, "5!!N", "****","N","E",true,
                       6, "6!!N", "****","N","E",true,
                       7, "7!!N", "****","N","E",true,
                       8, "8!!N", "****","N","E",true,
                       9, "9!!N", "****","N","E",true,
                       10, "10!!N", "****","N","E",true,
                       11, "J!!N", "****","N","E",true,
                       12, "Q!!N","****","N","E", true,
                       13, "K!!N","****","N","E", true};

    size_t numCartas = sizeof(cartas) / sizeof(cartas[0]);
    random_device rd;
    mt19937 g(rd());
    shuffle(cartas, cartas + numCartas, g);

    ListaDoblementeEnlazada *lista1 ;
    ListaDoblementeEnlazada *lista2 ;
    ListaDoblementeEnlazada *lista3 ;
    ListaDoblementeEnlazada *lista4 ;
    ListaDoblementeEnlazada *lista5 ;
    ListaDoblementeEnlazada *lista6 ;
    ListaDoblementeEnlazada *lista7 ;
    ListaDoblementeEnlazada *listaCopia[7];
    Cola *cola1;
    Cola *cola2;
    Pila *pila1;
    Pila *pila2;
    Pila *pila3;
    Pila *pila4;
    Pila *pila5;

    cola1 = new Cola();
    cola2 = new Cola();
    Cola *colaCopia[2];
    pila1 = new Pila();
    pila2 = new Pila();
    pila3 = new Pila();
    pila4 = new Pila();
    lista1 =new ListaDoblementeEnlazada();
    lista2 =new ListaDoblementeEnlazada();
    lista3 =new ListaDoblementeEnlazada();
    lista4 =new ListaDoblementeEnlazada();
    lista5 =new ListaDoblementeEnlazada();
    lista6 =new ListaDoblementeEnlazada();
    lista7 =new ListaDoblementeEnlazada();
    pila5 = new Pila();
    Pila *pilaCopia[27];
    for (int i = 0; i < 28; i++) {
        pilaCopia[i] = new Pila();
    }
    cola1->numCola=1;
    cola2->numCola=2;
    pila1->numPila=1;
    pila2->numPila=2;
    pila3->numPila=3;
    pila4->numPila=4;
    lista1->numLista = 1;
    lista2->numLista = 2;
    lista3->numLista = 3;
    lista4->numLista = 4;
    lista5->numLista = 5;
    lista6->numLista = 6;
    lista7->numLista = 7;
    ingresarCartas(lista1,1,cartas,0);
    ingresarCartas(lista2,3,cartas,1);
    ingresarCartas(lista3,6,cartas,3);
    ingresarCartas(lista4,10,cartas,6);
    ingresarCartas(lista5,15,cartas,10);
    ingresarCartas(lista6,21,cartas,15);
    ingresarCartas(lista7,28,cartas,21);
    ingresarCartasColas(cola1,52,cartas,28);

    std::cout << "********************************" << std::endl;
    std::cout << "*          Solitario           *" << std::endl;
    std::cout << "********************************" << std::endl;

    while (pila1->contador() < 13 && pila2->contador() < 13 && pila3->contador() < 13 && pila4->contador() < 13 ) {

        imprimirCartas(cola1, cola2, pila1, pila2, pila3, pila4, lista1, lista2, lista3, lista4, lista5, lista6,lista7);
        int seleccion;

        cout << "1. Colas " << endl;
        cout << "2. Barajas " << endl;
        cout << "3. volver " << endl;
        cout << " Ingrese un numero " << endl;
        cin >> seleccion;

        switch (seleccion) {
            case 1:
                imprimirCartas(cola1, cola2, pila1, pila2, pila3, pila4, lista1, lista2, lista3, lista4, lista5, lista6,lista7);
                cout << " A seleccionado Colas " << endl;
                cout << "1. Cola 1 " << endl;
                cout << "2. Cola 2 " << endl;
                cout << " Ingrese un numero " << endl;
                int colas;
                cin >> colas;
                switch (colas) {
                    case 1:
                        imprimirCartas(cola1, cola2, pila1, pila2, pila3, pila4, lista1, lista2, lista3, lista4, lista5,
                                       lista6, lista7);
                        cout << " A donde mover la carta " << endl;
                        cout << "1. Cola 2 " << endl;
                        cout << "2. Pila 1 " << endl;
                        cout << "3. Pila 2 " << endl;
                        cout << "4. Pila 3 " << endl;
                        cout << "5. Pila 4 " << endl;
                        cout << "6. Baraja 1 " << endl;
                        cout << "7. Baraja 2 " << endl;
                        cout << "8. Baraja 3 " << endl;
                        cout << "9. Baraja 4 " << endl;
                        cout << "10. Baraja 5 " << endl;
                        cout << "11. Baraja 6 " << endl;
                        cout << "12. Baraja 7 " << endl;
                        cout << " Ingrese un numero " << endl;
                        int mover;
                        cin >> mover;
                        pilaCopia[1]->borrar();
                        pilaCopia[2]->borrar();

                        generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[1],1);
                        generarCopiaAnterior(cola2, pila1,listaCopia[0],pilaCopia[2],1);

                        switch (mover) {
                            case 1:

                                if(cola1->contador()==0){
                                    cout<<cola1->contador()<<endl;
                                    cout<<cola2->contador()<<endl;

                                    while (cola2->contador() > 0){
                                        cout<<cola2->contador()<<endl;
                                        cambiarCartasCola(cola2, pila1, cola1, lista1, 2);

                                    }
                                }else{
                                    cambiarCartasCola(cola1, pila1, cola2, lista1, 2);
                                }
                                break;
                            case 2:
                                cambiarCartasCola(cola1, pila1, cola2, lista1, 1);
                                break;
                            case 3:
                                cambiarCartasCola(cola1, pila2, cola2, lista1, 1);
                                break;
                            case 4:
                                cambiarCartasCola(cola1, pila3, cola2, lista1, 1);
                                break;
                            case 5:
                                cambiarCartasCola(cola1, pila4, cola2, lista1, 1);
                                break;
                            case 6:
                                cambiarCartasCola(cola1, pila1, cola2, lista1, 3);
                                break;
                            case 7:
                                cambiarCartasCola(cola1, pila1, cola2, lista2, 3);
                                break;
                            case 8:
                                cambiarCartasCola(cola1, pila1, cola2, lista3, 3);
                                break;
                            case 9:
                                cambiarCartasCola(cola1, pila1, cola2, lista4, 3);
                                break;
                            case 10:
                                cambiarCartasCola(cola1, pila1, cola2, lista5, 3);
                                break;
                            case 11:
                                cambiarCartasCola(cola1, pila1, cola2, lista6, 3);
                                break;
                            case 12:
                                cambiarCartasCola(cola1, pila1, cola2, lista7, 3);
                                break;
                            default:
                                break;
                        }
                        break;
                    case 2:
                        imprimirCartas(cola1, cola2, pila1, pila2, pila3, pila4, lista1, lista2, lista3, lista4, lista5,lista6, lista7);
                        cout << " A donde mover la carta " << endl;
                        cout << "1. Pila 1 " << endl;
                        cout << "2. Pila 2 " << endl;
                        cout << "3. Pila 3 " << endl;
                        cout << "4. Pila 4 " << endl;
                        cout << "5. Baraja 1 " << endl;
                        cout << "6. Baraja 2 " << endl;
                        cout << "7. Baraja 3 " << endl;
                        cout << "8. Baraja 4 " << endl;
                        cout << "9. Baraja 5 " << endl;
                        cout << "10. Baraja 6 " << endl;
                        cout << "11. Baraja 7 " << endl;
                        cout << " Ingrese un numero " << endl;
                        int mover2;
                        cin >> mover2;
                        pilaCopia[1]->borrar();
                        pilaCopia[2]->borrar();

                        generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[1],1);
                        generarCopiaAnterior(cola2, pila1,listaCopia[0],pilaCopia[2],1);

                        switch (mover2) {
                            case 1:
                                cambiarCartasCola(cola2, pila1, cola2, lista1, 1);pilaCopia[5]->borrar();
                                generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[5],1);

                                break;
                            case 2:
                                cambiarCartasCola(cola2, pila2, cola2, lista1, 1);pilaCopia[5]->borrar();
                                generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[5],1);
                                break;
                            case 3:
                                cambiarCartasCola(cola2, pila3, cola2, lista1, 1);pilaCopia[5]->borrar();
                                generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[5],1);
                                break;
                            case 4:
                                cambiarCartasCola(cola2, pila4, cola2, lista1, 1);pilaCopia[5]->borrar();
                                generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[5],1);
                                break;
                            case 5:
                                cambiarCartasCola(cola2, pila1, cola2, lista1, 3);pilaCopia[5]->borrar();
                                generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[5],1);
                                break;
                            case 6:
                                cambiarCartasCola(cola2, pila1, cola2, lista2, 3);pilaCopia[5]->borrar();
                                generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[5],1);
                                break;
                            case 7:
                                cambiarCartasCola(cola2, pila1, cola2, lista3, 3);pilaCopia[5]->borrar();
                                generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[5],1);
                                break;
                            case 8:
                                cambiarCartasCola(cola2, pila1, cola2, lista4, 3);pilaCopia[5]->borrar();
                                generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[5],1);
                                break;
                            case 9:
                                cambiarCartasCola(cola2, pila1, cola2, lista5, 3);pilaCopia[5]->borrar();
                                generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[5],1);
                                break;
                            case 10:
                                cambiarCartasCola(cola2, pila1, cola2, lista6, 3);pilaCopia[5]->borrar();
                                generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[5],1);
                                break;
                            case 11:
                                cambiarCartasCola(cola2, pila1, cola2, lista7, 3);pilaCopia[5]->borrar();
                                generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[5],1);
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                imprimirCartas(cola1, cola2, pila1, pila2, pila3, pila4, lista1, lista2, lista3, lista4, lista5, lista6,lista7);
                cout << " A seleccionado Barajas " << endl;
                cout << "1. Baraja 1 " << endl;
                cout << "2. Baraja 2 " << endl;
                cout << "3. Baraja 3 " << endl;
                cout << "4. Baraja 4 " << endl;
                cout << "5. Baraja 5 " << endl;
                cout << "6. Baraja 6 " << endl;
                cout << "7. Baraja 7 " << endl;
                cout << " Ingrese un numero " << endl;
                int pilas;
                cin >> pilas;
                switch (pilas) {
                    case 1:

                        imprimirCartas(cola1, cola2, pila1, pila2, pila3, pila4, lista1, lista2, lista3, lista4, lista5,lista6, lista7);
                        cout << " A donde mover la carta " << endl;
                        cout << "1. Baraja 2 " << endl;
                        cout << "2. Baraja 3 " << endl;
                        cout << "3. Baraja 4 " << endl;
                        cout << "4. Baraja 5 " << endl;
                        cout << "5. Baraja 6 " << endl;
                        cout << "6. Baraja 7 " << endl;
                        cout << "7. Pila 1 " << endl;
                        cout << "8. Pila 2 " << endl;
                        cout << "9. Pila 3 " << endl;
                        cout << "10. Pila 4 " << endl;
                        cout << " Ingrese un numero " << endl;
                        int mover;
                        cin >> mover;
                        int filas;
                        pilaCopia[1]->borrar();
                        pilaCopia[2]->borrar();

                        generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[1],1);
                        generarCopiaAnterior(cola2, pila1,listaCopia[0],pilaCopia[2],1);

                        switch (mover) {
                            case 1:
                                cout << " Cuantas filas desea mover " << endl;
                                cin>>filas;
                                cout<< " filas " << filas<<endl;
                                cout << lista1->cartasSeleccionables();
                                if (filas <= lista1->cartasSeleccionables()) {
                                    for (int i = filas; i > 0; --i) {
                                        cambiarCartasLista(lista1, pila2, cola2, lista2, 3, i);
                                    }
                                }
                                break;
                            case 2:
                                cout << " Cuantas filas desea mover " << endl;
                                cin>>filas;
                                if (filas <= lista1->cartasSeleccionables()) {
                                    for (int i = filas; i > 0; --i) {
                                        cambiarCartasLista(lista1, pila2, cola2, lista2, 3, i);
                                    }
                                }
                                break;
                            case 3:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas;
                                if (filas <= lista1->cartasSeleccionables()) {
                                    for (int i = filas; i >= 0; --i) {
                                        cambiarCartasLista(lista1, pila4, cola2, lista4, 3,i);
                                    }
                                }
                                break;
                            case 4:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas;
                                cout<< " filas " << filas<<endl;
                                if (filas <= lista1->cartasSeleccionables()) {
                                    for (int i = filas; i >= 0; --i) {
                                        cambiarCartasLista(lista1, pila4, cola2, lista5, 3,i);
                                    }
                                }
                                break;
                            case 5:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas;
                                cout<< " filas " << filas<<endl;
                                if (filas <= lista1->cartasSeleccionables()) {
                                    for (int i = filas; i >= 0; --i) {
                                        cambiarCartasLista(lista1, pila4, cola2, lista6, 3,i);
                                    }
                                }
                                break;
                            case 6:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas;
                                cout<< " filas " << filas<<endl;
                                if (filas <= lista1->cartasSeleccionables()) {
                                    for (int i = filas; i >= 0; --i) {
                                        cambiarCartasLista(lista1, pila1, cola2, lista7, 3,i);
                                    }
                                }
                                break;
                            case 7:
                                cambiarCartasLista(lista1, pila1, cola2, lista2, 1,1);
                                break;
                            case 8:
                                cambiarCartasLista(lista1, pila2, cola2, lista3, 1,1);
                                break;
                            case 9:
                                cambiarCartasLista(lista1, pila3, cola2, lista4, 1,1);
                                break;
                            case 10:
                                cambiarCartasLista(lista1, pila4, cola2, lista5, 1,1);
                                break;
                            default:
                                break;
                        }
                        break;
                    case 2:
                        int filas2;
                        imprimirCartas(cola1, cola2, pila1, pila2, pila3, pila4, lista1, lista2, lista3, lista4, lista5,lista6, lista7);
                        cout << " A donde mover la carta " << endl;
                        cout << "1. Baraja 1 " << endl;
                        cout << "2. Baraja 3 " << endl;
                        cout << "3. Baraja 4 " << endl;
                        cout << "4. Baraja 5 " << endl;
                        cout << "5. Baraja 6 " << endl;
                        cout << "6. Baraja 7 " << endl;
                        cout << "7. Pila 1 " << endl;
                        cout << "8. Pila 2 " << endl;
                        cout << "9. Pila 3 " << endl;
                        cout << "10. Pila 4 " << endl;
                        cout << " Ingrese un numero " << endl;
                        int mover2;
                        cin >> mover2;
                        pilaCopia[1]->borrar();
                        pilaCopia[2]->borrar();

                        generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[1],1);
                        generarCopiaAnterior(cola2, pila1,listaCopia[0],pilaCopia[2],1);

                        switch (mover2) {
                            case 1:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas2;
                                if (filas2 <= lista2->cartasSeleccionables()) {
                                    for (int i = filas2; i > 0; --i) {
                                        cambiarCartasLista(lista2, pila2, cola2, lista1, 3,i);
                                    }
                                }
                                break;
                            case 2:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas2;
                                cout<< " filas " << filas2<<endl;
                                if (filas2 <= lista2->cartasSeleccionables()) {
                                    for (int i = filas2; i > 0; --i) {
                                        cambiarCartasLista(lista2, pila3, cola2, lista3, 3,i);
                                    }
                                }
                                break;
                            case 3:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas2;
                                cout<< " filas " << filas2<<endl;
                                if (filas2 <= lista2->cartasSeleccionables()) {
                                    for (int i = filas2; i > 0; --i) {
                                        cambiarCartasLista(lista2, pila4, cola2, lista4, 3,i);
                                    }
                                }
                                break;
                            case 4:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas2;
                                cout<< " filas " << filas2<<endl;
                                if (filas2 <= lista2->cartasSeleccionables()) {
                                    for (int i = filas2; i > 0; --i) {
                                        cambiarCartasLista(lista2, pila4, cola2, lista5, 3,i);
                                    }
                                }
                                break;
                            case 5:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas2;
                                cout<< " filas " << filas2<<endl;
                                if (filas2 <= lista2->cartasSeleccionables()) {
                                    for (int i = filas2; i > 0; --i) {
                                        cambiarCartasLista(lista2, pila4, cola2, lista6, 3,i);
                                    }
                                }
                                break;
                            case 6:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas2;
                                cout<< " filas " << filas2<<endl;
                                if (filas2 <= lista2->cartasSeleccionables()) {
                                    for (int i = filas2; i > 0; --i) {
                                        cambiarCartasLista(lista2, pila1, cola2, lista7, 3,i);
                                    }
                                }
                                break;
                            case 7:
                                cambiarCartasLista(lista2, pila1, cola2, lista2, 1,1);
                                break;
                            case 8:
                                cambiarCartasLista(lista2, pila2, cola2, lista3, 1,1);
                                break;
                            case 9:
                                cambiarCartasLista(lista2, pila3, cola2, lista4, 1,1);
                                break;
                            case 10:
                                cambiarCartasLista(lista2, pila4, cola2, lista5, 1,1);
                                break;
                            default:
                                break;
                        }
                        break;
                    case 3:
                        imprimirCartas(cola1, cola2, pila1, pila2, pila3, pila4, lista1, lista2, lista3, lista4, lista5,lista6, lista7);
                        cout << " A donde mover la carta " << endl;
                        cout << "1. Baraja 1 " << endl;
                        cout << "2. Baraja 2 " << endl;
                        cout << "3. Baraja 4 " << endl;
                        cout << "4. Baraja 5 " << endl;
                        cout << "5. Baraja 6 " << endl;
                        cout << "6. Baraja 7 " << endl;
                        cout << "7. Pila 1 " << endl;
                        cout << "8. Pila 2 " << endl;
                        cout << "9. Pila 3 " << endl;
                        cout << "10. Pila 4 " << endl;
                        cout << " Ingrese un numero " << endl;
                        int mover3;
                        cin >> mover3;
                        int filas3;
                        pilaCopia[1]->borrar();
                        pilaCopia[2]->borrar();

                        generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[1],1);
                        generarCopiaAnterior(cola2, pila1,listaCopia[0],pilaCopia[2],1);

                        switch (mover3) {
                            case 1:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas3;
                                cout<< " filas " << filas3<<endl;
                                if (filas3 <= lista3->cartasSeleccionables()) {
                                    for (int i = filas3; i >= 0; --i) {
                                        cambiarCartasLista(lista3, pila2, cola2, lista1, 3,i);
                                    }
                                }
                                break;
                            case 2:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas3;
                                cout<< " filas " << filas3<<endl;
                                if (filas3 <= lista3->cartasSeleccionables()) {
                                    for (int i = filas3; i >= 0; --i) {
                                        cambiarCartasLista(lista3, pila3, cola2, lista2, 3,i);
                                    }
                                }
                                break;
                            case 3:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas3;
                                cout<< " filas " << filas3<<endl;
                                if (filas3 <= lista3->cartasSeleccionables()) {
                                    for (int i = filas3; i >= 0; --i) {
                                        cambiarCartasLista(lista3, pila4, cola2, lista4, 3,i);
                                    }
                                }
                                break;
                            case 4:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas3;
                                cout<< " filas " << filas3<<endl;
                                if (filas3 <= lista3->cartasSeleccionables()) {
                                    for (int i = filas3; i >= 0; --i) {
                                        cambiarCartasLista(lista3, pila4, cola2, lista5, 3,i);
                                    }
                                }
                                break;
                            case 5:cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas3;
                                cout<< " filas " << filas3<<endl;
                                if (filas3 <= lista3->cartasSeleccionables()) {
                                    for (int i = filas3; i >= 0; --i) {
                                        cambiarCartasLista(lista3, pila4, cola2, lista6, 3,i);
                                    }
                                }
                                break;
                            case 6:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas3;
                                cout<< " filas " << filas3<<endl;
                                if (filas3 <= lista3->cartasSeleccionables()) {
                                    for (int i = filas3; i >= 0; --i) {
                                        cambiarCartasLista(lista3, pila1, cola2, lista7, 3,i);
                                    }
                                }
                                break;
                            case 7:
                                cambiarCartasLista(lista3, pila1, cola2, lista2, 1,0);
                                break;
                            case 8:
                                cambiarCartasLista(lista3, pila2, cola2, lista3, 1,0);
                                break;
                            case 9:
                                cambiarCartasLista(lista3, pila3, cola2, lista4, 1,0);
                                break;
                            case 10:
                                cambiarCartasLista(lista3, pila4, cola2, lista5, 1,0);
                                break;
                            default:
                                break;
                        }
                        break;
                    case 4:
                        imprimirCartas(cola1, cola2, pila1, pila2, pila3, pila4, lista1, lista2, lista3, lista4, lista5,lista6, lista7);
                        cout << " A donde mover la carta " << endl;
                        cout << "1. Baraja 1 " << endl;
                        cout << "2. Baraja 2 " << endl;
                        cout << "3. Baraja 3 " << endl;
                        cout << "4. Baraja 5 " << endl;
                        cout << "5. Baraja 6 " << endl;
                        cout << "6. Baraja 7 " << endl;
                        cout << "7. Pila 1 " << endl;
                        cout << "8. Pila 2 " << endl;
                        cout << "9. Pila 3 " << endl;
                        cout << "10. Pila 4 " << endl;
                        cout << " Ingrese un numero " << endl;
                        int mover4;
                        cin >> mover4;
                        int filas4;
                        pilaCopia[1]->borrar();
                        pilaCopia[2]->borrar();

                        generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[1],1);
                        generarCopiaAnterior(cola2, pila1,listaCopia[0],pilaCopia[2],1);

                        switch (mover4) {
                            case 1:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas4;
                                cout<< " filas " << filas4<<endl;
                                if (filas4 <= lista4->cartasSeleccionables()) {
                                    for (int i = filas4; i >= 0; --i) {
                                        cambiarCartasLista(lista4, pila2, cola2, lista1, 3,i);
                                    }
                                }
                                break;
                            case 2:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas4;
                                cout<< " filas " << filas4<<endl;
                                if (filas4 <= lista4->cartasSeleccionables()) {
                                    for (int i = filas4; i >= 0; --i) {
                                        cambiarCartasLista(lista4, pila3, cola2, lista2, 3,i);
                                    }
                                }
                                break;
                            case 3:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas4;
                                cout<< " filas " << filas4<<endl;
                                if (filas4 <= lista4->cartasSeleccionables()) {
                                    for (int i = filas4; i >= 0; --i) {
                                        cambiarCartasLista(lista4, pila4, cola2, lista3, 3,i);
                                    }
                                }
                                break;
                            case 4:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas4;
                                cout<< " filas " << filas4<<endl;
                                if (filas4 <= lista4->cartasSeleccionables()) {
                                    for (int i = filas4; i >= 0; --i) {
                                        cambiarCartasLista(lista4, pila4, cola2, lista5, 3,i);
                                    }
                                }
                                break;
                            case 5:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas4;
                                cout<< " filas " << filas4<<endl;
                                if (filas4 <= lista4->cartasSeleccionables()) {
                                    for (int i = filas4; i >= 0; --i) {
                                        cambiarCartasLista(lista4, pila4, cola2, lista6, 3,i);
                                    }
                                }
                                break;
                            case 6:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas4;
                                cout<< " filas " << filas4<<endl;
                                if (filas4 <= lista4->cartasSeleccionables()) {
                                    for (int i = filas4; i >= 0; --i) {
                                        cambiarCartasLista(lista4, pila1, cola2, lista7, 3,i);
                                    }
                                }
                                break;
                            case 7:
                                cambiarCartasLista(lista4, pila1, cola2, lista2, 1,0);
                                break;
                            case 8:
                                cambiarCartasLista(lista4, pila2, cola2, lista3, 1,0);
                                break;
                            case 9:
                                cambiarCartasLista(lista4, pila3, cola2, lista4, 1,0);
                                break;
                            case 10:
                                cambiarCartasLista(lista4, pila4, cola2, lista5, 1,0);
                                break;
                            default:
                                break;
                        }
                        break;
                    case 5:
                        imprimirCartas(cola1, cola2, pila1, pila2, pila3, pila4, lista1, lista2, lista3, lista4, lista5,lista6, lista7);
                        cout << " A donde mover la carta " << endl;
                        cout << "1. Baraja 1 " << endl;
                        cout << "2. Baraja 2 " << endl;
                        cout << "3. Baraja 3 " << endl;
                        cout << "4. Baraja 4 " << endl;
                        cout << "5. Baraja 6 " << endl;
                        cout << "6. Baraja 7 " << endl;
                        cout << "7. Pila 1 " << endl;
                        cout << "8. Pila 2 " << endl;
                        cout << "9. Pila 3 " << endl;
                        cout << "10. Pila 4 " << endl;
                        cout << " Ingrese un numero " << endl;
                        int mover5;
                        cin >> mover5;
                        int filas5;
                        pilaCopia[1]->borrar();
                        pilaCopia[2]->borrar();

                        generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[1],1);
                        generarCopiaAnterior(cola2, pila1,listaCopia[0],pilaCopia[2],1);

                        switch (mover5) {
                            case 1:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas5;
                                cout<< " filas " << filas5<<endl;
                                if (filas5 <= lista5->cartasSeleccionables()) {
                                    for (int i = filas5; i >= 0; --i) {
                                        cambiarCartasLista(lista5, pila2, cola2, lista1, 3,i);
                                    }
                                }
                                break;
                            case 2:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas5;
                                cout<< " filas " << filas5<<endl;
                                if (filas5 <= lista5->cartasSeleccionables()) {
                                    for (int i = filas5; i >= 0; --i) {
                                        cambiarCartasLista(lista5, pila3, cola2, lista2, 3,i);
                                    }
                                }
                                break;
                            case 3:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas5;
                                cout<< " filas " << filas5<<endl;
                                if (filas5 <= lista5->cartasSeleccionables()) {
                                    for (int i = filas5; i >= 0; --i) {
                                        cambiarCartasLista(lista5, pila4, cola2, lista3, 3,i);
                                    }
                                }
                                break;
                            case 4:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas5;
                                cout<< " filas " << filas5<<endl;
                                if (filas5 <= lista5->cartasSeleccionables()) {
                                    for (int i = filas5; i >= 0; --i) {
                                        cambiarCartasLista(lista5, pila4, cola2, lista4, 3,i);
                                    }
                                }
                                break;
                            case 5:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas5;
                                cout<< " filas " << filas5<<endl;
                                if (filas5 <= lista5->cartasSeleccionables()) {
                                    for (int i = filas5; i >= 0; --i) {
                                        cambiarCartasLista(lista5, pila4, cola2, lista6, 3,i);
                                    }
                                }
                                break;
                            case 6:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas5;
                                cout<< " filas " << filas5<<endl;
                                if (filas5 <= lista5->cartasSeleccionables()) {
                                    for (int i = filas5; i >= 0; --i) {
                                        cambiarCartasLista(lista5, pila1, cola2, lista7, 3,i);
                                    }
                                }
                                break;
                            case 7:
                               cambiarCartasLista(lista5, pila1, cola2, lista2, 1,0);
                                break;
                            case 8:
                               cambiarCartasLista(lista5, pila2, cola2, lista3, 1,0);
                                break;
                            case 9:
                               cambiarCartasLista(lista5, pila3, cola2, lista4, 1,0);
                                break;
                            case 10:
                               cambiarCartasLista(lista5, pila4, cola2, lista5, 1,0);
                                break;
                            default:
                                break;
                        }
                        break;
                    case 6:
                        imprimirCartas(cola1, cola2, pila1, pila2, pila3, pila4, lista1, lista2, lista3, lista4, lista5,lista6, lista7);
                        cout << " A donde mover la carta " << endl;
                        cout << "1. Baraja 1 " << endl;
                        cout << "2. Baraja 2 " << endl;
                        cout << "3. Baraja 3 " << endl;
                        cout << "4. Baraja 4 " << endl;
                        cout << "5. Baraja 5 " << endl;
                        cout << "6. Baraja 7 " << endl;
                        cout << "7. Pila 1 " << endl;
                        cout << "8. Pila 2 " << endl;
                        cout << "9. Pila 3 " << endl;
                        cout << "10. Pila 4 " << endl;
                        cout << " Ingrese un numero " << endl;
                        int mover6;
                        cin >> mover6;
                        int filas6;
                        pilaCopia[1]->borrar();
                        pilaCopia[2]->borrar();

                        generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[1],1);
                        generarCopiaAnterior(cola2, pila1,listaCopia[0],pilaCopia[2],1);

                        switch (mover6) {
                            case 1:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas6;
                                cout<< " filas " << filas6<<endl;
                                if (filas6 <= lista6->cartasSeleccionables()) {
                                    for (int i = filas6; i >= 0; --i) {
                                        cambiarCartasLista(lista6, pila2, cola2, lista1, 3,i);
                                    }
                                }
                                break;
                            case 2:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas6;
                                cout<< " filas " << filas6<<endl;
                                if (filas6 <= lista6->cartasSeleccionables()) {
                                    for (int i = filas6; i >= 0; --i) {
                                        cambiarCartasLista(lista6, pila3, cola2, lista2, 3,i);
                                    }
                                }
                                break;
                            case 3:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas6;
                                cout<< " filas " << filas6<<endl;
                                if (filas6 <= lista6->cartasSeleccionables()) {
                                    for (int i = filas6; i >= 0; --i) {
                                        cambiarCartasLista(lista6, pila4, cola2, lista3, 3,i);
                                    }
                                }
                                break;
                            case 4:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas6;
                                cout<< " filas " << filas6<<endl;
                                if (filas6 <= lista6->cartasSeleccionables()) {
                                    for (int i = filas6; i >= 0; --i) {
                                        cambiarCartasLista(lista6, pila4, cola2, lista4, 3,i);
                                    }
                                }
                                break;
                            case 5:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas6;
                                cout<< " filas " << filas6<<endl;
                                if (filas6 <= lista6->cartasSeleccionables()) {
                                    for (int i = filas6; i >= 0; --i) {
                                        cambiarCartasLista(lista6, pila4, cola2, lista5, 3,i);
                                    }
                                }
                                break;
                            case 6:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas6;
                                cout<< " filas " << filas6<<endl;
                                if (filas6 <= lista6->cartasSeleccionables()) {
                                    for (int i = filas6; i >= 0; --i) {
                                        cambiarCartasLista(lista6, pila1, cola2, lista7, 3,i);
                                    }
                                }
                                break;
                            case 7:
                                cambiarCartasLista(lista6, pila1, cola2, lista2, 1,0);
                                break;
                            case 8:
                                cambiarCartasLista(lista6, pila2, cola2, lista3, 1,0);
                                break;
                            case 9:
                                cambiarCartasLista(lista6, pila3, cola2, lista4, 1,0);
                                break;
                            case 10:
                                cambiarCartasLista(lista6, pila4, cola2, lista5, 1,0);
                                break;
                            default:
                                break;
                        }
                        break;
                    case 7:
                        imprimirCartas(cola1, cola2, pila1, pila2, pila3, pila4, lista1, lista2, lista3, lista4, lista5,lista6, lista7);
                        cout << " A donde mover la carta " << endl;
                        cout << "1. Baraja 1 " << endl;
                        cout << "2. Baraja 2 " << endl;
                        cout << "3. Baraja 3 " << endl;
                        cout << "4. Baraja 4 " << endl;
                        cout << "5. Baraja 5 " << endl;
                        cout << "6. Baraja 6 " << endl;
                        cout << "7. Pila 1 " << endl;
                        cout << "8. Pila 2 " << endl;
                        cout << "9. Pila 3 " << endl;
                        cout << "10. Pila 4 " << endl;
                        cout << " Ingrese un numero " << endl;
                        int mover7;
                        pilaCopia[1]->borrar();
                        pilaCopia[2]->borrar();

                        generarCopiaAnterior(cola1, pila1,listaCopia[0],pilaCopia[1],1);
                        generarCopiaAnterior(cola2, pila1,listaCopia[0],pilaCopia[2],1);

                        cin >> mover7;
                        int filas7;
                        switch (mover7) {
                            case 1:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas7;
                                cout<< " filas " << filas7<<endl;
                                if (filas7 <= lista7->cartasSeleccionables()) {
                                    for (int i = filas7; i >= 0; --i) {
                                        cambiarCartasLista(lista7, pila2, cola2, lista1, 3,i);
                                    }
                                }
                                break;
                            case 2:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas7;
                                cout<< " filas " << filas7<<endl;
                                if (filas7 <= lista7->cartasSeleccionables()) {
                                    for (int i = filas7; i >= 0; --i) {
                                        cambiarCartasLista(lista7, pila3, cola2, lista2, 3,i);
                                    }
                                }
                                break;
                            case 3:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas7;
                                cout<< " filas " << filas7<<endl;
                                if (filas7 <= lista7->cartasSeleccionables()) {
                                    for (int i = filas7; i >= 0; --i) {
                                        cambiarCartasLista(lista7, pila4, cola2, lista3, 3,i);
                                    }
                                }
                                break;
                            case 4:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas7;
                                cout<< " filas " << filas7<<endl;
                                if (filas7 <= lista7->cartasSeleccionables()) {
                                    for (int i = filas7; i >= 0; --i) {
                                        cambiarCartasLista(lista7, pila4, cola2, lista4, 3,i);
                                    }
                                }
                                break;
                            case 5:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas7;
                                cout<< " filas " << filas7<<endl;
                                if (filas7 <= lista7->cartasSeleccionables()) {
                                    for (int i = filas7; i >= 0; --i) {
                                        cambiarCartasLista(lista7, pila4, cola2, lista5, 3,i);
                                    }
                                }
                                break;
                            case 6:
                                cout << " Cuantas filas desea mover " << endl;
                                    cin>>filas7;
                                cout<< " filas " << filas7<<endl;
                                if (filas7 <= lista7->cartasSeleccionables()) {
                                    for (int i = filas7; i >= 0; --i) {
                                        cambiarCartasLista(lista7, pila1, cola2, lista6, 3,i);
                                    }
                                }
                                break;
                            case 7:

                                cambiarCartasLista(lista7, pila1, cola2, lista2, 1,0);
                                break;
                            case 8:
                                cambiarCartasLista(lista7, pila2, cola2, lista3, 1,0);
                                break;
                            case 9:
                                cambiarCartasLista(lista7, pila3, cola2, lista4, 1,0);
                                break;
                            case 10:
                                cambiarCartasLista(lista7, pila4, cola2, lista5, 1,0);
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                cout<<"Restaurando" << endl;
                    cola1->borrar();
                    cola2->borrar();
                    restaurarCopia(cola1, pila1, lista1, pilaCopia[1], 1);
                    restaurarCopia(cola2, pila1, lista1, pilaCopia[2], 1);

                break;
            default:
                break;
        }
    }

}

void menu(){
    int seleccion;

    std::cout << "********************************" << std::endl;
    std::cout << "*          Solitario           *" << std::endl;
    std::cout << "*                              *" << std::endl;
    std::cout << "* 1. Jugar                     *" << std::endl;
    std::cout << "* 2. Salir                     *" << std::endl;
    std::cout << "********************************" << std::endl;
    std::cin >> seleccion ;

    switch(seleccion)
    {
        case 1:
            solitario();
            std::cout << "********************************" << std::endl;
            std::cout << "*     Gracias por jugar        *" << std::endl;
            std::cout << "********************************" << std::endl;
            break;
        case 2:
            return;
        default:
            std::cout << "Ingrese un numero entre el 1 y 2" << std::endl;
            menu();
    }
}

int main() {
    menu();
    return 0;
}

