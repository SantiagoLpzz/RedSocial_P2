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

void Publicacion::mostrarPublicacion(){
    cout<<fecha<<endl;
    cout<<contenido<<endl;
    cout<<usuario->nombre;
}

Publicacion::Publicacion(Usuario* usuario, string fecha, string contenido){
    this->usuario=usuario;
    this->fecha=fecha;
    this->contenido=contenido;
}
