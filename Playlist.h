//
// Created by mio on 24/03/23.
//

#ifndef PROYECTO1_EDD_LISTA_H
#define PROYECTO1_EDD_LISTA_H

#endif //PROYECTO1_EDD_LISTA_H

#include <iostream>
#include "Cancion.h"

class PlayList{
public:
    ListaCanciones* listaCanciones;
    string nombre;
    string descripcion;

    PlayList(string nombre, string descripcion, ListaCanciones* listaCanciones){
        this->nombre = nombre;
        this->descripcion = descripcion;
        this->listaCanciones = listaCanciones;
    }

    PlayList(string nombre, string descripcion){
        this->nombre = nombre;
        this->descripcion = descripcion;
        this->listaCanciones = NULL;
    }

};

class NodoPlayList{
public:
    PlayList* playList;
    NodoPlayList* siguiente;

    NodoPlayList(PlayList* playList){
        this->playList = playList;
        siguiente = NULL;
    }

};

class ListaPlayList{
public:
    int tamanio=0;
    NodoPlayList* primero;

public:
    ListaPlayList(){
        this->primero = NULL;
    }

    void insertar(NodoPlayList* nodo){
        if(this->primero == NULL){
            primero = nodo;
            tamanio++;
            return;
        }

//        cout<<"Insertando siguiente nodo"<<"\n";
        NodoPlayList* ultimo = encontrarUltimo();
        ultimo->siguiente = nodo;
        tamanio++;

    }

    void insertarEn(NodoPlayList* nodo, int posicion){
        if(posicion > tamanio){
            cout<<"Imposible agregar la playlist en la posición: "<<posicion<<" porque la lista de playlist tiene un tamaño de: "<<tamanio<<"\n";
            return;
        }

        NodoPlayList* nodoEncontrar = encontrarEn(posicion);

        nodo->siguiente = nodoEncontrar->siguiente;
        nodoEncontrar->siguiente = nodo;

    }

    void listar(){
        int posicion = 0;
        NodoPlayList* nodo = this-> primero;

        while(nodo != NULL){
            cout<<++posicion<<". "<<nodo->playList->nombre<<"\n";
            nodo = nodo->siguiente;
        }

    }

    void eliminarEn(int posicion){
        if(posicion > tamanio){
            cout<<"Imposible eliminar la playlist en la posición: "<<posicion<<" porque la lista de playlist tiene un tamaño de: "<<tamanio<<"\n";
            return;
        }

        NodoPlayList* nodoEliminar = encontrarEn(posicion);
        cout<<"Nodo a eliminar: "<<nodoEliminar->playList->nombre<<".\n";

    }

private:

    NodoPlayList* encontrarUltimo(){
        NodoPlayList* nodo = this->primero;
        while(nodo->siguiente != NULL){
//            cout<<"NodoCancion actual "<<nodo->cancion->nombre<<"\n";
            nodo = nodo->siguiente;

        }

        return nodo;
    }

    NodoPlayList* encontrarEn(int posicion){
        int actual = 0;
        NodoPlayList* nodo = this->primero;
        while(actual != posicion-1 && actual < tamanio){
            actual++;
            nodo=nodo->siguiente;
        }

        return nodo;
    }


};