#ifndef usuario2_h
#define usuario2_h

#include <iostream>
#include <vector>
#include <string>
#include "redSocial2.h"
#include "publicacion2.h"

using namespace std;

class Usuario{
private:
    int id;
public:
    string nombre;
    int edad;
    string nacionalidad;
    vector <Usuario*> amigos;
    vector <Publicacion*> publicaciones;

//METODOS
    int getId ();
    void mostrar();
    void mostrarAmigos();
    void mostrarPublicaciones();
    void agregarAmigos(Usuario* nuevoAmigo);
    void crearPublicacion();
    Usuario* getAmigo(int id);

//CONSTRUCTORES
    Usuario(string nombre);
    Usuario(string nombre, int edad);
    Usuario(string nombre, int edad,string nacionalidad);

};

#endif