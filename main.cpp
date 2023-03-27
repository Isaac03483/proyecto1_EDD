#include <iostream>
#include "Playlist.h"

#define ROJO "\e[0;31m"
#define NC "\e[0m"
#define VERDE "\e[0;32m"
#define CELESTE "\e[0;36m"

using namespace std;

void menuPrincipal();
void menuCanciones();
void menuPlaylist();
void menuReproduccion();
void opcionCanciones();
void opcionPlaylist();
void opcionReproduccion();
void cargaDatos();
void agregarCancion();
void buscarCancion();
void eliminarCancion();
void agregarPlaylist();
void buscarPlaylist();
void eliminarPlaylist();
void agregarCancionAPlaylist();

ListaCanciones listaCanciones = ListaCanciones();
/*
int main(){
    Cancion cancion1("cancion1", "path1");
    Cancion cancion2("cancion2", "path2");
    Cancion cancion3("cancion3", "path3");
    Cancion cancion4("cancion4", "path4");
    ListaCanciones canciones = ListaCanciones();

    NodoCancion nodoCancion1(&cancion1);
    NodoCancion nodoCancion2(&cancion2);
    NodoCancion nodoCancion3(&cancion3);
    NodoCancion nodoCancion4(&cancion4);

    canciones.insertar(&nodoCancion1);
//    canciones.insertar(&nodoCancion2);
//    canciones.insertarEn(&nodoCancion3, 1);
//    canciones.listar();
//    cout<<"\n";
//    canciones.insertarEn(&nodoCancion4, 2);

    canciones.listar();

    return 0;
}
*/


int main() {
    int opcion = 0;
    do {
        fflush(stdin);
        menuPrincipal();
        cin>>opcion;
        switch (opcion) {
            case 1:
                opcionCanciones();
                break;
            case 2:
                opcionPlaylist();
                break;
            case 3:
                opcionReproduccion();
                break;
            case 4:
                cargaDatos();
                break;
            case 5:
                cout<<VERDE<<"Nos vemos :D"<<NC<<"\n";
                break;
            default:
                cout<<"\n"<<ROJO<<"Opción incorrecta."<<NC<<"\n\n";
        }

    }while(opcion != 5);
    return 0;
}

//Opciones del menú principal
void opcionCanciones(){
    int opcion = 0;
    do {
        fflush(stdin);
        menuCanciones();
        cin>>opcion;
        switch (opcion) {
            case 1:
                cout<<CELESTE<<"\n\t.:AGREGANDO CANCIÓN NUEVA:."<<NC<<"\n";
                agregarCancion();
                break;
            case 2:
                cout<<CELESTE<<"\n\t.:ELIMINANDO CANCIÓN:."<<NC<<"\n";
                eliminarCancion();
                break;
            case 3:
                cout<<CELESTE<<"\n\t.:CANCIONES:."<<NC<<"\n";
                listaCanciones.listar();
                break;
            case 4:
                cargaDatos();
                break;
            case 5:
                cout<<VERDE<<"Volviendo al menú principal."<<NC<<"\n";
                break;
            default:
                cout<<"\n"<<ROJO<<"Opción incorrecta."<<NC<<"\n\n";
        }
    } while(opcion != 5);
}

void agregarCancion(){
    string nombreCancion = "";
    string pathCancion = "";

    cout<<"Ingrese el nombre de la canción: ";
    cin>>nombreCancion;


    cout<<"Ingrese la ruta de la canción: ";
    cin>>pathCancion;

    Cancion* cancion =new Cancion();
    cancion->nombre = nombreCancion;
    cancion->path = pathCancion;
    listaCanciones.insertar(cancion);
    cout<<VERDE<<"Cancion agregada exitosamente."<<NC<<"\n";

}

void eliminarCancion(){
    int opcionEliminar;
    listaCanciones.listar();
    cout<<"\nIngrese el número de canción que desee eliminar: ";
    cin>>opcionEliminar;

    listaCanciones.eliminarEn(opcionEliminar);

}

void opcionPlaylist(){

}

void opcionReproduccion(){

}



//MENÚS, SIMPLEMENTE LA IMPRESIÓN DE CADA UNO DE ELLOS
void menuPrincipal(){
    cout<<CELESTE<<"\n\t.:MENÚ PRINCIPAL:."<<NC<<"\n"
        <<"1. Canciones."<<"\n"
        <<"2. Playlist."<<"\n"
        <<"3. Reproduccir música."<<"\n"
        <<"4. Cargar información."<<"\n"
        <<"5. Salir"<<"\n"
        <<"Ingrese la opción que desee realizar: "
    ;
}

void menuCanciones(){
    cout<<CELESTE<<"\n\t.:CANCIONES:."<<NC<<"\n"
        <<"1. Insertar canción."<<"\n"
        <<"2. Eliminar canción."<<"\n"
        <<"3. Listar canciones."<<"\n"
        <<"4. Buscar canción."<<"\n"
        <<"5. Volver."<<"\n"
        <<"Ingrese la opción que desee realizar: "
    ;
}

void menuPlaylist(){
    cout<<CELESTE<<"\n\t.:PLAYLIST:."<<NC<<"\n"
        <<"1. Crear playlist."<<"\n"
        <<"2. Listar playlist."<<"\n"
        <<"3. Eliminar playlist."<<"\n"
        <<"4. Actualizar playlist."<<"\n"
        <<"4. Agregar canción."<<"\n"
        <<"4. Eliminar canción."<<"\n"
        <<"Ingrese la opción que desee realizar: "
    ;
}

void menuReproduccion(){
    cout<<CELESTE<<"\n\t.:PLAYLIST:."<<NC<<"\n"
        <<"1. Crear playlist."<<"\n"
        <<"2. Listar playlist."<<"\n"
        <<"3. Eliminar playlist."<<"\n"
        <<"4. Actualizar playlist."<<"\n"
        <<"4. Agregar canción."<<"\n"
        <<"4. Eliminar canción."<<"\n"
        <<"Ingrese la opción que desee realizar: "
    ;
}

void cargaDatos(){
    cout<<ROJO<<"\nÁrea en mantenimiento"<<NC<<"\n\n";
}
