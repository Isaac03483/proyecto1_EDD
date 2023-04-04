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
void agregarCancionPlaylist(ListaCanciones* canciones);
void eliminarCancionPlaylist(ListaCanciones* canciones);

ListaCanciones* listaCanciones = new ListaCanciones();
ListaPlayList* listaPlayList = new ListaPlayList();
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
                listaCanciones->listar();
                break;
            case 4:
                cout<<CELESTE<<"\n\t.:BUSCAR CANCIÓN:."<<NC<<"\n";
                buscarCancion();
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

    int option = 0;
    cout<<"¿Desea ingresar la canción en una posición en específico?\n"
        <<"1. Si.\n"
        <<"2. No\n";
    cin>>option;
    if(option == 1){
        cout<<"Ingrese la posición en la que se ingresará la canción: ";
        cin>>option;
        listaCanciones->insertarEn(cancion, option);
        return;
    }


    listaCanciones->insertar(cancion);
    cout<<VERDE<<"Cancion agregada exitosamente."<<NC<<"\n";

}

void eliminarCancion(){
    int opcionEliminar;
    listaCanciones->listar();
    cout<<"\nIngrese el número de canción que desee eliminar: ";
    cin>>opcionEliminar;

    listaCanciones->eliminarEn(opcionEliminar);

}

void buscarCancion(){
    string nombre = "";
    cout<<"Ingrese el nombre de la canción a buscar: ";
    cin>>nombre;
    string descripcion = listaCanciones->obtenerPorNombre(nombre);

    if(descripcion.empty()){
        cout<<ROJO<<"NO SE HA ENCONTRADO LA CANCIÓN"<<NC<<"\n";
        return;
    }

    cout<<descripcion;

}

void opcionPlaylist(){
    int opcion = 0;
    do {
        fflush(stdin);
        menuPlaylist();
        cin>>opcion;
        switch (opcion) {
            case 1:
                cout<<CELESTE<<"\n\t.:CREANDO PLAYLIST NUEVA:."<<NC<<"\n";
                agregarPlaylist();
                break;
            case 2:
                cout<<CELESTE<<"\n\t.:LISTANDO PLAYLIST:."<<NC<<"\n";
                listaPlayList->listar();
                break;
            case 3:
                cout<<CELESTE<<"\n\t.:ELIMINAR PLAYLIST:."<<NC<<"\n";
                eliminarPlaylist();
                break;
            case 4:
                cout<<CELESTE<<"\n\t.:ACTUALIZAR PLAYLIST:."<<NC<<"\n";

                break;
            case 5:
                cout<<CELESTE<<"\n\t.:AGREGAR CANCION:."<<NC<<"\n";
                buscarPlaylist();
                break;
            case 6:
                cout<<CELESTE<<"\n\t.:ELIMINAR CANCION:."<<NC<<"\n";

                listaPlayList->listar();
                break;
            case 7:
                cout<<VERDE<<"Volviendo al menú principal."<<NC<<"\n";
                break;
            default:
                cout<<"\n"<<ROJO<<"Opción incorrecta."<<NC<<"\n\n";
        }
    } while(opcion != 7);
}

void agregarPlaylist(){
    string nombrePlaylist = "";
    string descripcionPlaylist = "";
    ListaCanciones* canciones = new ListaCanciones();

    cout<<"Ingrese  el nombre de la playlist: ";
    cin>>nombrePlaylist;
    cout<<"Ingrese la descripción de la playlist: ";
    cin>>descripcionPlaylist;

    int opcion = 0;
    cout<<"Desea crear una lista canciones ahora (si no lo desea puede hacerlo después): 1.Si/2. No\n";
    cin>>opcion;

    if(opcion == 1){
        agregarCancionPlaylist(canciones);
    }

    PlayList* playList = new PlayList(nombrePlaylist,descripcionPlaylist, canciones);
    listaPlayList->insertar(playList);
    cout<<VERDE<<"PLAYLIST CREADA CON EXITO"<<NC<<"\n";
}

void eliminarPlaylist(){
    int indice = 0;
    listaPlayList->listar();
    cout<<"INGRESE EL INDICE DE LA PLAYLIST A ELIMINAR: ";
    cin>>indice;

    listaPlayList->eliminarEn(indice);
    cout<<VERDE<<"PLAYLIST ELIMINADA CON EXITO"<<NC<<"\n";
}

void buscarPlaylist(){
    int indice = 0;
    listaPlayList->listar();
    cout<<"\nIngrese el indice de la playlist: ";
    cin>>indice;
    PlayList* playList = listaPlayList->encontraPlaylistEn(indice);
    if(playList == NULL){
        cout<<ROJO<<"NO SE HA ENCONTRADO LA CANCIÓN"<<NC<<"\n";
    }

    agregarCancionPlaylist(playList->listaCanciones);
}

void agregarCancionPlaylist(ListaCanciones* canciones){


}

void eliminarCancionPlaylist(ListaCanciones* canciones){

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
        <<"5. Agregar canción."<<"\n"
        <<"6. Eliminar canción."<<"\n"
        <<"7. Volver."<<"\n"
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
