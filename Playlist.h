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

};

class NodoPlayList{
public:
    PlayList* playList;
    NodoPlayList* siguiente;

    NodoPlayList(PlayList* playList){
        this->playList = playList;
        siguiente = NULL;
    }

    virtual ~NodoPlayList() {

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

    void insertar(PlayList* playList){

        NodoPlayList* nodo = new NodoPlayList(playList);

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
            cout<<++posicion<<". Nombre: "<<nodo->playList->nombre<<". Descripción:"<<nodo->playList->descripcion<<"\n";
            nodo = nodo->siguiente;
        }

    }

    void eliminarEn(int posicion){
        if(posicion > tamanio){
            cout<<"Imposible eliminar la playlist en la posición: "<<posicion<<" porque la lista de playlist tiene un tamaño de: "<<tamanio<<"\n";
            return;
        }

        if(posicion == 1){
            NodoPlayList* nodoEliminar = this->primero;
            this->primero = this->primero->siguiente;
            nodoEliminar->~NodoPlayList();
            tamanio--;
        }

        NodoPlayList* nodoAnterior = encontrarEn(posicion);
        NodoPlayList* nodoEliminar = nodoAnterior->siguiente;
        nodoAnterior->siguiente = nodoEliminar->siguiente;
        nodoEliminar->~NodoPlayList();
        tamanio--;


    }

    PlayList* encontraPlaylistEn(int posicion){
        if(posicion > tamanio){
            cout<<"No se ha encontrado la posicion: "<<posicion<<" porque la lista de playlist tiene un tamaño de: "<<tamanio<<"\n";
            return NULL;
        }

        if(posicion == 1){
            return this->primero->playList;
        }

        NodoPlayList* nodoPlayList = encontrarEn(posicion);
        return  nodoPlayList->siguiente->playList;

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
        while(actual < posicion-2 && actual < tamanio){
            actual++;
            nodo=nodo->siguiente;
        }

        return nodo;
    }


};