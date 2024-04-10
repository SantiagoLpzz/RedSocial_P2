#include <iostream>
#include "redSocial2.h"
#include "usuario2.h"
#include "publicacion2.h"
#include "venta.h"
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
    /*
    this->numeroDeUsuarios++;
    this->usuarios.insert(numeroDeUsuarios,usuario); <-- no sirve pero tiene futuro
    */
    this->usuarios.push_back(usuario); // sirve a medias
}

void RedSocial::ayuda_AU(int odu){
    string name, nationality;
    int age;
        cout << "Ingrese el nombre, edad y nacionalidad del nuevo usuario" << endl;
        cin >> name >> age >> nationality;
}

void RedSocial::mostrarUsuarios(){
    for (int i=0;i<usuarios.size();i++){
        usuarios[i]->mostrar();
        cout << endl;
    }
}

void RedSocial::agregarPublicaciones(Publicacion* publicacion){
    this->publicaciones.push_back(publicacion);

    this->numeroDePublicaciones++;
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

    this->numeroDeUsuarios = 0;
    this->numeroDePublicaciones = 0;
}

RedSocial::RedSocial(string nom, vector <Usuario*> usu){
    this->nombre=nom;
    this->usuarios=usu;

    this->numeroDeUsuarios = usu.size();
    this->numeroDePublicaciones = 0;
}

RedSocial::RedSocial(string nom, vector <Usuario*> usu, vector <Publicacion*>pub){
    this->nombre=nom;
    this->usuarios=usu;
    this->publicaciones=pub;

    this->numeroDeUsuarios = usu.size();
    this->numeroDePublicaciones = pub.size();
}