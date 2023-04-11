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
void opcionReproduccion(ListaCanciones* canciones);
void cargaDatos();
void agregarCancion();
void buscarCancion();
void eliminarCancion();
void agregarPlaylist();
void buscarPlaylist(int opcion);
void actualizarPlaylist(PlayList* playList);
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
                buscarPlaylist(3);
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
                cout<<CELESTE<<"\n\t.:LISTA DE CANCIONES:."<<NC<<"\n";
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
    cout<<VERDE<<"¿Desea ingresar la canción en una posición en específico?"<<NC<<"\n"
        <<"1. Si.\n"
        <<"2. No\n";
    cin>>option;
    if(option == 1){
        cout<<"Ingrese la posición en la que se ingresará la canción: ";
        cin>>option;
        listaCanciones->insertarEn(cancion, option);
        return;
    } else if(option == 2){
        listaCanciones->insertar(cancion);
        cout<<VERDE<<"Cancion agregada exitosamente."<<NC<<"\n";
    } else {
        cout<<ROJO<<"OPCIÓN INCORRECTA."<<NC<<"\n";

    }




}

void eliminarCancion(){
    int opcionEliminar;
    listaCanciones->listar();
    cout<<"\nIngrese el número de canción que desee eliminar: ";
    cin>>opcionEliminar;

    Cancion* cancionEliminar = listaCanciones->encontrarCancionEn(opcionEliminar);

    if(cancionEliminar == NULL){
        return;
    }

    cout<<"Canción a eliminar: "<<cancionEliminar->nombre<<"\n";

    NodoPlayList* nodoPlay = listaPlayList->primero;
    while(nodoPlay != NULL){
        NodoCancion* nodoCancion = nodoPlay->playList->listaCanciones->primero;

        while(nodoCancion != NULL){
            if(nodoCancion->cancion == cancionEliminar){
                cout<<ROJO<<"NO SE PUEDE ELIMINAR LA CANCIÓN YA QUE SE ENCUENTRA EN UNA PLAYLIST"<<NC<<"\n";
                return;
            }

            nodoCancion = nodoCancion->siguiente;
        }

        nodoPlay = nodoPlay->siguiente;

    }
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
                buscarPlaylist(4);
                break;
            case 5:
                cout<<CELESTE<<"\n\t.:AGREGAR CANCION:."<<NC<<"\n";
                buscarPlaylist(5);
                break;
            case 6:
                cout<<CELESTE<<"\n\t.:ELIMINAR CANCION:."<<NC<<"\n";
                buscarPlaylist(6);
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
    fflush(stdin);

    string nombrePlaylist = "";
    string descripcionPlaylist = "";
    ListaCanciones* canciones = new ListaCanciones();

    cout<<"Ingrese  el nombre de la playlist: ";
    cin>>nombrePlaylist;
    cout<<"Ingrese la descripción de la playlist: ";
    cin>>descripcionPlaylist;

    int opcion = 0;
    cout<<"Desea crear una lista canciones ahora (si no lo desea puede hacerlo después): 1.Si/2. No.\n";
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

void buscarPlaylist(int opcion){

    if(listaPlayList->tamanio == 0){
        cout<<ROJO<<"NO HA AGREGADO NINGUNA PLAYLIST AÚN."<<NC<<"\n";
        return;
    }

    int indice = 0;
    listaPlayList->listar();
    cout<<"\nIngrese el indice de la playlist: ";
    cin>>indice;
    PlayList* playList = listaPlayList->encontraPlaylistEn(indice);
    if(playList == NULL){
        cout<<ROJO<<"NO SE HA ENCONTRADO LA PLAYLIST."<<NC<<"\n";
        return;
    }

    if(opcion == 3){
        opcionReproduccion(playList->listaCanciones);
    }else if(opcion == 4){
        actualizarPlaylist(playList);
    }else if(opcion == 5){
        agregarCancionPlaylist(playList->listaCanciones);
    } else if(opcion == 6){
        eliminarCancionPlaylist(playList->listaCanciones);
    }
}

void agregarCancionPlaylist(ListaCanciones* canciones){

    if(listaCanciones->tamanio == 0){
        cout<<ROJO<<"NO HA AGREGADO NINGUNA CANCIÓN A LA STORE AÚN."<<NC<<"\n";
        return;
    }

    int opcion = 0;
    do{
        cout<<"\t\n"<<CELESTE<<".:LISTA DE CANCIONES:."<<NC<<"\n";
        listaCanciones->listar();
        cout<<"Ingrese el número de canción a agregar en la playlist: (Ingrese 0 para salir)\n";
        cin>>opcion;
        if(opcion == 0){
            cout<<VERDE<<"Regresando..."<<NC<<"\n";
        }else if(opcion > listaCanciones->tamanio){
            cout<<ROJO<<"NO SE HA ENCONTRADO LA CANCIÓN"<<NC<<"\n";

        } else{
            Cancion* cancion = listaCanciones->encontrarCancionEn(opcion);

            if(cancion == NULL){
                return;
            }

            cout<<"Agregando canción con nombre: "<<cancion->nombre<<"\n";
            canciones->insertar(cancion);
        }
    }while(opcion != 0);

}

void eliminarCancionPlaylist(ListaCanciones* canciones){

    if(canciones->tamanio == 0){
        cout<<ROJO<<"AÚN NO HA AGREGADO CANCIONES A ESTA PLAYLIST"<<NC<<"\n";
        return;
    }

    int opcion = 0;
    do{

        if(canciones->tamanio == 0){
            cout<<ROJO<<"ESTA PLAYLIST YA NO POSEE CANCIONES."<<NC<<"\n";
            break;
        }

        cout<<"\t\n"<<CELESTE<<".:LISTA DE CANCIONES:."<<NC<<"\n";
        canciones->listar();
        cout<<"Ingrese el número de canción a eliminar en la playlist: (Ingrese 0 para salir)\n";
        cin>>opcion;
        if(opcion == 0){
            cout<<VERDE<<"Regresando..."<<NC<<"\n";
        }else if(opcion > canciones->tamanio){
            cout<<ROJO<<"NO SE HA ENCONTRADO LA CANCIÓN"<<NC<<"\n";

        } else{

            canciones->eliminarEn(opcion);
        }
    }while(opcion != 0);
}

void actualizarPlaylist(PlayList* playList){
    int opcion = 0;

    do{
        cout<<"1. Actualizar Nombre.\n"
            <<"2. Actualizar Descrición.\n"
            <<"3. Volver.\n"
            <<"Ingrese la opción que desee modificar: ";
        cin>>opcion;

        switch (opcion) {
            case 1:
                cout<<"Ingrese el nuevo nombre de la playlist: ";
                cin>>playList->nombre;
                cout<<VERDE<<"NOMBRE ACTUALIZADO CON ÉXITO"<<NC<<"\n";
                break;
            case 2:
                cout<<"Ingrese la nueva descripción de la playlist: ";
                cin>>playList->descripcion;
                cout<<VERDE<<"DESCRIPCIÓN ACTUALIZADA CON ÉXITO"<<NC<<"\n";
                break;
            case 3:
                cout<<VERDE<<"Volviendo..."<<NC<<"\n";
                break;
            default:
                cout<<ROJO<<"Opción incorrecta."<<NC<<"\n";
                break;
        }



    }while(opcion != 3);

}


void opcionReproduccion(ListaCanciones* canciones){

    canciones->listar();
    ListaDoble* doble = simpleADoble(canciones);
//    cout<<"Lista doble\n";
//
//    ListaCircular* circular = simpleACircular(canciones);
//    cout<<"Lista circular\n";

    Cancion *actual = nullptr;

    cout<<"Listas declaradas\n";

    int opcion = 0;
    do{

        if(actual != NULL){
            cout<<"Canción actual: "<<VERDE<<actual->nombre<<NC<<"\n";
        }

        menuReproduccion();
        cin>>opcion;


        switch (opcion) {
            case 1:
                actual = doble->reproducir();
                break;
            case 2:
//                actual = circular->reproducir();
//                listaUsar = 2;
                break;
            case 3:
                actual = doble->siguiente();
                break;
            case 4:
                actual = doble->anterior();
                break;
        }

        if(actual == NULL){
            cout<<VERDE<<"REPRODUCCIÓN FINALIZADA."<<NC<<"\n";
            break;
        }

    }while(opcion != 7);

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
    cout<<CELESTE<<"\n\t.:REPRODUCCIÓN:."<<NC<<"\n"
        <<"1. Normal."<<"\n"
        <<"2. Repetir."<<"\n"
        <<"3. Siguiente."<<"\n"
        <<"4. Anterior."<<"\n"
        <<"5. Lista de Reproducción."<<"\n"
        <<"6. Agregar canción a la lista."<<"\n"
        <<"7. Volver."<<"\n"
        <<"Ingrese la opción que desee realizar: "
    ;
}

void cargaDatos(){
    cout<<ROJO<<"\nÁrea en mantenimiento"<<NC<<"\n\n";
}
