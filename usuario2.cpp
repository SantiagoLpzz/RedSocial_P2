#include <iostream>
#include "usuario2.h"
#include "redSocial2.h"
#include "publicacion2.h"

class Usuario;

using namespace std;

/*
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
*/

//METODOS -----

int Usuario::getId(){
    return id;
}

void Usuario::mostrar(){
    cout<<nombre;
    cout<<edad;
    cout<<nacionalidad;
    cout<<id;
}
//Creo que ya esta pero no puedo compilar
void Usuario::mostrarAmigos(){
        cout << "Los amigos de " << nombre << " son:" << endl;

        for (int i = 0; i < amigos.size(); i++)
        {
            Usuario* amigo = amigos[i];

            cout << "Nombre: " << amigo->nombre << endl;
            cout << "Edad: " << amigo->edad << endl;
            cout << "Nacionalidad: " << amigo->nacionalidad << endl;
            cout << endl;

        }
}

void Usuario::mostrarPublicaciones(){
    for (int i=0;i<publicaciones.size();i++){
        Publicacion* publicacion = publicaciones[i];
        cout << "Fecha: " << publicacion->fecha << endl;
        cout << "Contenido: " << publicacion->contenido << endl;
        cout << "Usuario: " << publicacion->usuario->nombre << endl;
        cout << endl;
    }
}
// Creo que ya sirve pero no puedo compilr entonces no se
void Usuario::agregarAmigos(Usuario* nuevoAmigo){
    this->amigos.push_back(nuevoAmigo);
    nuevoAmigo->amigos.push_back(this);
}
//¯\_(ツ)_/¯
void Usuario::crearPublicacion(){
    Publicacion nueva(this, "Fecha de publicacion de", "Contenido de la publicacion");
    publicaciones.push_back(&nueva);
}

Usuario* Usuario::getAmigo(int id){
    for (int i = 0; i < amigos.size(); i++){
        if (id == amigos[i]->getId()){
            return amigos[i];
        }
    }
    return nullptr; // Devuelve nullptr si no se encuentra ninguna coincidencia
}


//CONSTRUCTORES -----

Usuario::Usuario (string nom){
    this->nombre=nom;
}

Usuario::Usuario (string nom,int ed){
    this->nombre=nom;
    this->edad=ed;
}

Usuario::Usuario (string nom,int ed,string nac){
    this->nombre=nom;
    this->edad=ed;
    this->nacionalidad=nac;
}