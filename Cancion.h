//
// Created by mio on 24/03/23.
//

#include <cstring>
#include <iostream>
#include<fstream>

#ifndef PROYECTO1_EDD_CANCION_H
#define PROYECTO1_EDD_CANCION_H

#endif //PROYECTO1_EDD_CANCION_H

using namespace std;

struct Cancion{
public:
    string nombre;
    string path;

    Cancion(){
    }

    ~Cancion(){

    }
};

struct NodoCancion{
public:
    Cancion* cancion;
    NodoCancion* siguiente;

    NodoCancion(){
        this->siguiente = NULL;
    }

    ~NodoCancion() {

    }

};

struct ListaCanciones{
public:
    int tamanio =0;
    NodoCancion* primero;

    ListaCanciones(){
        this->primero = NULL;
    }

    void insertar(Cancion* cancion){
        NodoCancion* nodo = new NodoCancion();
        nodo->cancion = cancion;

        if(this->primero == NULL){
            primero = nodo;
            tamanio++;
            return;
        }

        NodoCancion* ultimo = encontrarUltimo();
        ultimo->siguiente = nodo;
        tamanio++;

    }

    void insertarEn(Cancion* cancion, int posicion){
        NodoCancion* nodoInsertar = new NodoCancion();
        nodoInsertar->cancion = cancion;
        if(posicion > tamanio){
            cout<<"Imposible agregar la canción en la posición: "<<posicion<<" porque la lista de canciones tiene un tamaño de: "<<tamanio<<"\n";
            return;
        }

        if(posicion == 1){
            nodoInsertar->siguiente = this->primero;
            this->primero = nodoInsertar;
            tamanio++;
            cout<<"Cancion agregada exitosamente."<<"\n";

            return;
        }

        NodoCancion* nodoEncontrar = encontrarEn(posicion);

        nodoInsertar->siguiente = nodoEncontrar->siguiente;
        nodoEncontrar->siguiente = nodoInsertar;
        tamanio++;
        cout<<"Cancion agregada exitosamente."<<"\n";

    }

    void eliminarEn(int posicion){
        if(posicion > tamanio){
            cout<<"Imposible  eliminar la canción en la posición: "<<posicion<<" porque la lista de canciones tiene un tamaño de: "<<tamanio<<"\n";
            return;
        }

        if(posicion == 1){
//            cout<<"Eliminando canción: "<<primero->cancion->nombre<<"\n";
            NodoCancion* nodoEliminar = primero;
            primero = this->primero->siguiente;
            nodoEliminar->~NodoCancion();
            tamanio--;
            return;
        }

        NodoCancion* nodoAnterior = encontrarEn(posicion);
        NodoCancion* nodoEliminar = nodoAnterior->siguiente;
//        cout<<"Eliminando canción: "<< nodoEliminar->cancion->nombre<<"\n";
        nodoAnterior->siguiente = nodoEliminar->siguiente;
        nodoEliminar->~NodoCancion();
        tamanio--;
    }

    string obtenerPorNombre(string nombre){
        int indice = 0;
        NodoCancion* nodoCancion = this->primero;
        while(nodoCancion != NULL){
            indice++;

            if(nodoCancion->cancion->nombre == nombre){
                return to_string(indice)+". Nombre: "+nodoCancion->cancion->nombre+". Ruta: "+nodoCancion->cancion->path;
            }
            nodoCancion = nodoCancion->siguiente;
        }

        return "";

    }

    void listar(){
        int posicion = 0;
        NodoCancion* nodo = this->primero;

        while(nodo != NULL){
//            cout<<"Imprimiendo nodo: "<<nodo->cancion<<"\n\n";
            cout<<++posicion<<". "<<nodo->cancion->nombre<<"\n";
//            cout<<"Siguiente: "<<nodo->siguiente<<"\n\n";
            nodo = nodo->siguiente;
        }

    }

    Cancion* encontrarCancionEn(int indice){
        if(indice > tamanio){
            cout<<"CANCIÓN NO ENCONTRADA\n";
            return NULL;
        }

        if(indice == 1){
            return this->primero->cancion;
        }

        NodoCancion* nodoCancion = encontrarEn(indice);
        return nodoCancion->siguiente->cancion;
    }


private:

    NodoCancion* encontrarUltimo(){
        NodoCancion* nodo = this->primero;
        while(nodo->siguiente != NULL){
//            cout<<"NodoCancion actual "<<nodo->cancion->nombre<<"\n";
            nodo = nodo->siguiente;

        }

        return nodo;
    }

    NodoCancion* encontrarEn(int posicion){
        int actual = 1;
        NodoCancion* nodo = this->primero;

        while(actual < posicion-1 && actual < tamanio){
            actual++;
            nodo = nodo->siguiente;
        }

        return nodo;

    }

};

struct NodoDoble{
public:
    Cancion* cancion;
    NodoDoble* siguiente;
    NodoDoble* anterior;

    NodoDoble(){
       this->cancion = NULL;
       this->siguiente = NULL;
       this->anterior = NULL;
    }

    ~NodoDoble(){

    }
};

struct ListaDoble{

public:
    int tamanio = 0;
    NodoDoble* primero;
    NodoDoble* actual;

    ListaDoble(){
        this->primero = NULL;
    }

    void insertar(Cancion* cancion){

        NodoDoble* nodoInsertar = new NodoDoble();
        nodoInsertar->cancion = cancion;

        if(primero == NULL){
            primero = nodoInsertar;
            return;
        }

        NodoDoble* ultimoNodo = encontrarUltimo();
        ultimoNodo->siguiente = nodoInsertar;
        nodoInsertar->anterior = ultimoNodo;

    }

    Cancion* reproducir(){
        if(this->actual == NULL){
            this->actual = primero;
        }

        return actual->cancion;
    }

    Cancion* siguiente(){
        this->actual = this->actual->siguiente;

        if(this->actual == NULL){
            return NULL;
        }
        return this->actual->cancion;
    }

    Cancion* anterior(){
        this->actual = this->actual->anterior;

        if(this->actual == NULL){
            return NULL;
        }
        return this->actual->cancion;

    }

    void imprimir(){
        cout<<"IMPRIMIENDO LISTA DE REPRODUCCIÓN\n";
        NodoDoble* nodoDoble = this->actual->siguiente;
        while(nodoDoble != NULL){
            cout<<"Cancion: "<<nodoDoble->cancion->nombre<<"| ";
            nodoDoble = nodoDoble->siguiente;
        }

        cout<<"\n";
    }

private:

    NodoDoble* encontrarUltimo(){
        NodoDoble* nodo = this->primero;

        while(nodo->siguiente != NULL){
            nodo = nodo->siguiente;
        }

        return nodo;
    }
};

struct ListaCircular{

public:
    NodoDoble* primero;
    NodoDoble* actual;

    ListaCircular(){
        this->primero = NULL;
    }

    void insertar(Cancion* cancion){

        NodoDoble* nodoInsertar = new NodoDoble();
        nodoInsertar->cancion = cancion;

        if(primero == NULL) {
            this->primero = nodoInsertar;
            this->primero->siguiente = this->primero;
            this->primero->anterior = this->primero;
            return;
        }

        if(this->primero->siguiente == this->primero){
            this->primero->siguiente = nodoInsertar;
            nodoInsertar->siguiente = this->primero;
            nodoInsertar->anterior = this->primero;
            this->primero->anterior = nodoInsertar;
            return;
        }

        NodoDoble* ultimo = encontrarUltimo();

        ultimo->siguiente = nodoInsertar;
        nodoInsertar->siguiente = this->primero;
        this->primero->anterior = nodoInsertar;
        nodoInsertar->anterior = ultimo;

    }

    Cancion* reproducir(){
        if(this->actual == NULL){
            this->actual = this->primero;
        }

        return this->actual->cancion;
    }

    Cancion* siguiente(){

        this->actual = this->actual->siguiente;

        if(this->actual == NULL){
            return NULL;
        }

        return this->actual->cancion;
    }

    Cancion* anterior(){

        this->actual = this->actual->anterior;

        if(this->actual == NULL){
            return NULL;
        }

        return this->actual->cancion;
    }

    void imprimir() {
        cout<<"IMPRIMIENDO LISTA DE REPRODUCCIÓN\n";
        NodoDoble* nodoDoble = this->actual->siguiente;
        while(nodoDoble != this->primero){
            cout<<"Cancion: "<<nodoDoble->cancion->nombre<<"| ";
            nodoDoble = nodoDoble->siguiente;
        }

        cout<<"\n";
    }

private:

    NodoDoble* encontrarUltimo(){
        NodoDoble* nodo = this->primero;

        while(nodo->siguiente != this->primero){
            nodo = nodo->siguiente;
        }

        return nodo;
    }

};

struct Pila {
    NodoCancion* ultimo;

    Pila(){
        this->ultimo = NULL;
    }

    void apilar(Cancion* cancion){
        NodoCancion* nodoInsertar = new NodoCancion();
        nodoInsertar->cancion = cancion;

        if(this->ultimo == NULL){
            this->ultimo = nodoInsertar;
            return;
        }

        nodoInsertar->siguiente = this->ultimo;
        this->ultimo = nodoInsertar;


    }

    void imprimirPila(){
        NodoCancion* nodoCancion = this->ultimo;
        cout<<"Imprimiendo Pila de reproducción:\n";
        while(nodoCancion != NULL){
            cout<<"Canción: "<<nodoCancion->cancion->nombre<<"| ";
            nodoCancion = nodoCancion->siguiente;
        }

        cout<<"\n";
    }

    Cancion* desapilar(){

        if(vacia()){
            return NULL;
        }

        NodoCancion* nodoDesapilar = this->ultimo;
        this->ultimo = this->ultimo->siguiente;

        return nodoDesapilar->cancion;
    }

    int vacia(){
        return this->ultimo == NULL;
    }

};


ListaDoble* simpleADoble(ListaCanciones* lista){
    NodoCancion* nodo = lista->primero;
    ListaDoble* listaDoble = new ListaDoble();

    while(nodo != NULL){
        listaDoble->insertar(nodo->cancion);

        nodo = nodo->siguiente;
    }

    return listaDoble;
}

ListaCircular* simpleACircular(ListaCanciones* lista){
    NodoCancion* nodo = lista->primero;
    ListaCircular* listaCircular = new ListaCircular();

    while(nodo != NULL){
        listaCircular->insertar(nodo->cancion);
        nodo = nodo->siguiente;
    }

    return listaCircular;

}
