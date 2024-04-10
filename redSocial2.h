#ifndef redSocial2_h
#define redSocial2_h

#include <iostream>
#include <vector>
#include <string>
#include "usuario2.h"
#include "publicacion2.h"

using namespace std;

class Usuario;
class Publicacion;

class RedSocial{
private:
    vector <Usuario*> usuarios;
    vector <Publicacion*> publicaciones;
public:
    string nombre;
    int numeroDeUsuarios;
    int numeroDePublicaciones;

//METODOS
    void agregarUsuario(Usuario* usuario);
    void mostrarUsuarios();
    void agregarPublicaciones(Publicacion* publicacion);
    void mostrarPublicaciones();
    void ayuda_AU(int odu);
    Usuario* getUsuario(int id);
    void agregarVenta(Venta* venta); 


//CONSTRUCTORES
    RedSocial(string nombre);
    RedSocial(string nombre, vector <Usuario*> usuarios);
    RedSocial(string nombre, vector <Usuario*> usuarios,vector <Publicacion*>publicaciones);
};

#endif
