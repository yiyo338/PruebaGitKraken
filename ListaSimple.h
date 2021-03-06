//
// Created by cris on 23/02/18.
//

#ifndef TRABAJOEXTRACLASEDATOS2_LISTASIMPLE_H
#define TRABAJOEXTRACLASEDATOS2_LISTASIMPLE_H


class NodoSimpleInt{
public:
    NodoSimpleInt(){
        siguiente = 0;
    }

    NodoSimpleInt(int el, NodoSimpleInt *ptr =0 ){
        dato = el; siguiente = ptr;
    }

    int dato;
    NodoSimpleInt *siguiente;
};

class ListaSimple {
public:
    ListaSimple(){
        primero = ultimo = 0;
    }
    ~ListaSimple();
    int EstaVacia(){
        return primero == 0;
    }
    void InsertarAlInicio(int el);
    void InsertarAlFinal(int el);
    void InsertarEnPosicion(int pos, int el);
    int EliminarPrimero();
    int EliminarUltimo();
    void EliminarPorPosicion(int pos);
    void EditarPorPosicion(int pos, int el);
    int ObtenerPorPosicion(int pos);
    void ImprimirLista();

private:
    NodoSimpleInt *primero, *ultimo;
    int tamanio = 0;
};


#endif //TRABAJOEXTRACLASEDATOS2_LISTASIMPLE_H
