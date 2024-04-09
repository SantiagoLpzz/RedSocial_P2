#include <iostream>
#include "publicacion2.h"
#include "usuario2.h"
#include "redSocial2.h"


using namespace std;


/*
//METODOS
    void mostrarPublicacion();

//CONSTRUCTORES
    Publicacion(Usuario* usuario, string fecha, string contenido);
*/

int Publicacion::getIdp(){
    return idp;
}

void Publicacion::mostrarPublicacion(){
    cout<<"-----"<<endl;
    cout<<"| "<<fecha<<endl;
    cout<<"| <"<<contenido<<">"<<endl;
    cout<<"| --> "<<usuario->nombre<<" .ID "<<usuario->getId()<<endl;
    cout<<"-------------------- .IDP "<<idp<<endl;
}

Publicacion::Publicacion(int od,Usuario* usuario, string fecha, string contenido){
    this->idp=od;
    this->usuario=usuario;
    this->fecha=fecha;
    this->contenido=contenido;
}
