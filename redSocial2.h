#ifndef redSocial2_h
#define redSocial2_h

#include <iostream>
#include <vector>
#include <string>
#include "usuario2.h"
#include "publicacion2.h"
#include "venta.h"

using namespace std;

class Usuario;
class Publicacion;
class Venta;

class RedSocial{
private:
    vector <Usuario*> usuarios;
    vector <Publicacion*> publicaciones;
    vector <Venta*> ventas;
public:
    string nombre;
    int numeroDeUsuarios;
    int numeroDePublicaciones;
    int numeroDeVentas;

//METODOS
    void agregarUsuario(Usuario* usuario);
    void mostrarUsuarios();
    void agregarPublicaciones(Publicacion* publicacion);
    void agregarVentas(Venta* venta);
    void mostrarPublicaciones();
    void ayuda_AU(int odu);
    Usuario* getUsuario(int id);

//CONSTRUCTORES
    RedSocial(string nombre);
    RedSocial(string nombre, vector <Usuario*> usuarios);
    RedSocial(string nombre, vector <Usuario*> usuarios,vector <Publicacion*>publicaciones);
};

#endif