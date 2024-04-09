#ifndef publicacion2_h
#define publicacion2_h

#include <iostream>
#include <vector>
#include <string>
#include "usuario2.h"

class Usuario;

using namespace std;

class Publicacion{
private:
    int id;
public:
    string fecha;
    string contenido;
    Usuario* usuario;

//METODOS
    void mostrarPublicacion();

//CONSTRUCTORES
    Publicacion(Usuario* usuario, string fecha, string contenido);
};

#endif