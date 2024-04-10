#include <iostream>
#include "publicacion2.h"
#include "usuario2.h"
#include "redSocial2.h"
#include "venta.h"


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
    cout<<"| "<<this->fecha<<endl;
    cout<<"| < "<<this->contenido<<" >"<<endl;
    cout<<"| --> "<<this->usuario->nombre<<" .ID "<<this->usuario->getId()<<endl;
    cout<<"-------------------- .IDP "<<this->idp<<endl;
}

Publicacion::Publicacion(int od,Usuario* usuario, string fecha, string contenido){
    this->idp=od;
    this->usuario=usuario;
    this->fecha=fecha;
    this->contenido=contenido;
}

