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
    int idp;
public:
    string fecha;
    string contenido;
    Usuario* usuario;

//METODOS
    int getIdp();
    void mostrarPublicacion();
//CONSTRUCTORES
    Publicacion(int od,Usuario* usuario, string fecha, string contenido);
};

#endif