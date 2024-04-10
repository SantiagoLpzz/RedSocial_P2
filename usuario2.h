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

    int li_u=1; //limite inferior para la randomización del id;
    int ls_u=10000; //limite superior para la randomización del id;
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
    void agregarPublicacion(Publicacion* NuevaPublicacion);
    void crearPublicacion(int odp);
    Usuario* getAmigo(int id);
    void crearVenta(int odp);

//CONSTRUCTORES
    Usuario(int od,string nombre);
    Usuario(int od,string nombre, int edad);
    Usuario(int od,string nombre, int edad,string nacionalidad);

};

#endif
