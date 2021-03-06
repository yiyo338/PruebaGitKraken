//
// Created by cris on 25/02/18.
//

#include "ListaDoble.h"
#include <iostream>

using namespace std;


void ListaDoble ::inicializa() {

    primero = nullptr;
    ultimo = nullptr;

}

bool ListaDoble ::vacia() {
    if(primero == nullptr &&  ultimo == nullptr)
    {
        return true;
    }else
    {
        return false;
    }

}

int ListaDoble::tamano() {
    NodoListaDobleInt *tmp = ultimo;
    int cont = 0;
    while(tmp != nullptr){
        tmp = tmp->anterior;
        cont++;
    }
    delete tmp;
    return cont;

}

void ListaDoble::mostrar() {
    NodoListaDobleInt *tmp = primero;
    cout<<"[ ";
    while(tmp != nullptr){
        cout<<tmp->dato<<" ";
        tmp = tmp->siguiente;
    }
    cout<<"]";
    delete tmp;
}

void ListaDoble ::insertarAlInicio(int el) {
    NodoListaDobleInt *tmp = new NodoListaDobleInt;
    tmp->dato = el;
    tmp->anterior = nullptr;
    tmp->siguiente = nullptr;

    if(vacia()){
        primero = tmp;
        ultimo = tmp;
    }else{
        tmp->siguiente = primero;
        primero->anterior = tmp;
        primero = tmp;
    }
}

void ListaDoble::insertarAlFinal(int el) {
    NodoListaDobleInt *tmp = new NodoListaDobleInt;
    tmp->dato = el;
    tmp->anterior = nullptr;
    tmp->siguiente = nullptr;

    if(vacia()){
        primero = tmp;
        ultimo = tmp;
    }else{
        tmp->anterior = ultimo;
        ultimo->siguiente = tmp;
        ultimo = tmp;
    }
}

void ListaDoble::insertarEnPosicion(int pos, int el) {
    if(pos == tamano())
    {
        insertarAlFinal(el);
    }

    else if(pos == 0)
    {
        insertarAlInicio(el);
    }

    else if(pos>0 && pos<tamano())
    {
        NodoListaDobleInt *aux = primero;
        NodoListaDobleInt *tmp = new NodoListaDobleInt;
        tmp->dato = el;
        tmp->siguiente, tmp->anterior = nullptr;
        for(int x = 0; x<pos; x++)
        {
            aux = aux->siguiente;
        }
        aux->anterior->siguiente = tmp;
        tmp->siguiente = aux;
        tmp->anterior = aux->anterior;
        aux->anterior = tmp;

        delete aux;

    }else{
        cout<<"No existe la posicion.";
    }
}

int ListaDoble::obtenerPorPosicion(int pos) {
    int dato;
    if(vacia()){
        cout<<"No hay elementos en la lista.";
    }else if(pos<tamano() && pos>0){
        NodoListaDobleInt *tmp = primero;
        for(int x = 0; x<pos; x++){
            tmp = tmp->siguiente;
        }
        dato = tmp->dato;
        delete tmp;
        return dato;
    }else{
        cout<<"La posición no existe";
        return dato;
    }

}

void ListaDoble::eliminarPrimero() {
    primero = primero->siguiente;
    delete primero->anterior;
    primero->anterior = nullptr;
}

void ListaDoble::eliminarUltimo() {
    ultimo = ultimo->anterior;
    delete ultimo->siguiente;
    ultimo->siguiente = nullptr;
}

void ListaDoble::eliminarPorPosicion(int pos) {

    if(pos==0){
        eliminarPrimero();

    }else if(pos == tamano()){
        eliminarUltimo();
    }

    else if(pos>0 && pos<tamano()){
        NodoListaDobleInt *aux = primero;
        for(int x = 0; x<pos; x++){
            aux = aux->siguiente;
        }
        aux->anterior->siguiente = aux->siguiente;
        ultimo->anterior = aux->anterior;
        delete(aux);

    }else{
        cout<<"Posicion no valida.";
    }
}

void ListaDoble::editarPorPosicion(int pos, int el) {
    if(pos>tamano() or pos<0)
    {
        cout<<"Posicion no valida";
    }
    else
    {
         NodoListaDobleInt *aux = primero;
         for(int x = 0; x<pos; x++){
             aux = aux->siguiente;
    }
    aux->dato = el;
    }
}
