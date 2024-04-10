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
    if(this->idRespuesta != 0){
        cout<<"| RESPONDIENDO A: .ID Publicacion "<<this->idRespuesta<<endl;
        cout<<"-----"<<endl;
    }
    cout<<"| "<<this->fecha<<endl;
    cout<<"| < "<<this->contenido<<" >"<<endl;
    cout<<"| --> "<<this->usuario->nombre<<" .ID "<<this->usuario->getId()<<endl;
    cout<<"-------------------- .ID Publicacion "<<this->idp<<endl<<endl;
}

Publicacion::Publicacion(int od,Usuario* usuario, string fecha, string contenido,int idrespuesta){
    this->idp=od;
    this->usuario=usuario;
    this->fecha=fecha;
    this->contenido=contenido;
    if (idrespuesta!=0){
        this->idRespuesta = idrespuesta;
    }else {
        this->idRespuesta = 0;
    }
}