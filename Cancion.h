//
// Created by mio on 24/03/23.
//

#include <cstring>
#include <iostream>

#ifndef PROYECTO1_EDD_CANCION_H
#define PROYECTO1_EDD_CANCION_H

#endif //PROYECTO1_EDD_CANCION_H

using namespace std;

class Cancion{
public:
    string nombre;
    string path;

    Cancion(string nombre, string path){
        this->nombre = nombre;
        this->path = path;
    }
};
