#include <iostream>
#include "redSocial2.h"
#include "usuario2.h"
#include "publicacion2.h"
using namespace std;

/*
//METODOS
    void agregarUsuario();
    void mostrarUsuarios();
    void mostrarPublicaciones();
    Usuario* getUsuario(int id);

//CONSTRUCTORES
    RedSocial(string nombre);
    RedSocial(string nombre, vector <Usuario*> usuarios);
    RedSocial(string nombre, vector <Usuario*> usuarios,vector <Publicacion*>publicaciones);
*/

//METODOS -----

void RedSocial::agregarUsuario(Usuario* usuario){
    this->usuarios.push_back(usuario);
}

void RedSocial::mostrarUsuarios(){
    for (int i=0;i<usuarios.size();i++){
        usuarios[i]->mostrar();
        cout << endl;
    }
}

void RedSocial::agregarPublicaciones(Publicacion* publicacion){
    this->publicaciones.push_back(publicacion);
};

void RedSocial::mostrarPublicaciones(){
    for (int i=0;i<publicaciones.size();i++){
        publicaciones[i]->mostrarPublicacion();
    }
}

Usuario* RedSocial::getUsuario(int id){
    for (int i = 0; i < usuarios.size(); i++){
        if (id == usuarios[i]->getId()){
            return usuarios[i];
        }
    }
    return nullptr; 
}

//CONSTRUCTORES -----

//CHECA ESTA MADRE v v v v v ! ! ! ! !
RedSocial::RedSocial(string nom){
    this->nombre=nom;
}

RedSocial::RedSocial(string nom, vector <Usuario*> usu){
    this->nombre=nom;
    this->usuarios=usu;
}

RedSocial::RedSocial(string nom, vector <Usuario*> usu, vector <Publicacion*>pub){
    this->nombre=nom;
    this->usuarios=usu;
    this->publicaciones=pub;
}