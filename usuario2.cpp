#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "usuario2.h"
#include "redSocial2.h"
#include "publicacion2.h"
#include "venta.h"

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
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Edad: "<<edad<<endl;
    cout<<"Nacionalidad: "<<nacionalidad<<endl;
    cout<<"Id: "<<id<<endl;
}
//Creo que ya esta pero no puedo compilar
void Usuario::mostrarAmigos(){
        cout << ". "<<nombre<< endl<< endl;
        for (int i = 0; i < amigos.size(); i++)
        {
            cout<<i+1<<"."<<endl;
            Usuario* amigo = amigos[i];

            cout << "Nombre: " << amigo->nombre << endl;
            cout << "Edad: " << amigo->edad << endl;
            cout << "Nacionalidad: " << amigo->nacionalidad << endl;
            cout<< "Id: "<< amigo->getId() <<endl;
            cout << endl;
            //Tal vez arriesgarnos y usar la funcion mostrar() de amigo??????

        }
}

void Usuario::mostrarVentas(){
    cout << ". " << nombre << endl<<endl;

    for (int i=0;i<this->ventas.size();i++){
        cout<<i+1<<"."<<endl;
        this->ventas[i]->mostrarVenta();
    }
}

void Usuario::mostrarPublicaciones(){
    cout << ". " << nombre << endl<<endl;

    for (int i=0;i<this->publicaciones.size();i++){
        cout<<i+1<<"."<<endl;
        //Publicacion* publicacion = this->publicaciones[i];
        this->publicaciones[i]->mostrarPublicacion();
        /*
        cout << "Fecha: " << publicaciones[i]->fecha << endl;
        cout << "Contenido: " << publicacion->contenido << endl;
        cout << "Usuario: " << publicacion->usuario->nombre << endl;
        cout << endl;
        */
    }
    cout<<".VENTAS"<<endl;
    for (int i=0;i<this->ventas.size();i++){
        cout<<i+1<<"."<<endl;
        this->ventas[i]->mostrarVenta();
    }
}
// Creo que ya sirve pero no puedo compilr entonces no se
void Usuario::agregarAmigos(Usuario* nuevoAmigo){ 
    this->amigos.push_back(nuevoAmigo);
    nuevoAmigo->amigos.push_back(this);
}
//¯\_(ツ)_/¯
Publicacion* Usuario::crearPublicacion(int odp){
    string fecha,contenido;
    int id_respuesta,idr_c;
    cout<<endl<<".INTRODUSCA LA FECHA DEL DIA DE HOY"<<endl<<endl<<"--> ";
    cin>>fecha;
    cout<<endl<<".INTRODUSCA EL CONTENIDO DE LA PUBLICACION"<<endl<<endl<<"--> ";
    cin>>contenido;
    cout<<endl<<".INTRODUSCA CUALQUIER NUMERO QUE NO SEA .0. SI QUIERE RESPONDER"<<endl<<endl<<"--> ";
    cin>>idr_c;
    if(idr_c ==0){
        id_respuesta=0;
    }else {
        cout<<".INTRODUSCA EL ID DE LA PUBLICACION A LA QUE DESEA RESPONDER"<<endl;
        cin>>id_respuesta;
    }
    cout<<endl;
    Publicacion* nueva = new Publicacion(odp,this,fecha,contenido,id_respuesta);
    this->publicaciones.push_back(nueva);
    //Publicacion* send = &nueva;
    return (nueva);
}

void Usuario::agregarPublicacion(Publicacion* NuevaPublicacion){
    this->publicaciones.push_back(NuevaPublicacion);
}

Usuario* Usuario::getAmigo(int id){
    for (int i = 0; i < amigos.size(); i++){
        if (id == amigos[i]->getId()){
            return amigos[i];
        }
    }
    return nullptr; // Devuelve nullptr si no se encuentra ninguna coincidencia
}

Venta* Usuario::crearVenta(int odv) {
    string fecha, contenido, lugarDeVenta;
    double precio;

    cout << endl << "Introduzca la fecha de la venta: ";
    cin >> fecha;
    cout << endl << "Introduzca el contenido de la venta: ";
    cin >> contenido;
    cout << endl << "Introduzca el precio de la venta: ";
    cin >> precio;
    cout << endl << "Introduzca el lugar de la venta: ";
    cin >> lugarDeVenta;
    Venta* nuevav = new Venta(odv, this, fecha, contenido, precio, lugarDeVenta);
    this->ventas.push_back(nuevav);
    return nuevav;
}

//CONSTRUCTORES -----

Usuario::Usuario (int od,string nom){
    this->id=od;
    this->nombre=nom;
    this->edad = 0;
    this->nacionalidad = "Desconocido";

    srand(time(NULL));
    this->id = this->li_u + rand() % (this->ls_u + 1 -this->li_u); //Randomizacion de la id
}

Usuario::Usuario (int od,string nom,int ed){
    this->id=od;
    this->nombre=nom;
    this->edad=ed;
    this->nacionalidad = "Desconocido";

    //srand(time(NULL));
    //this->id = this->li_u + rand() % (this->ls_u + 1 -this->li_u); //Randomizacion de la id
}

Usuario::Usuario (int od,string nom,int ed,string nac){
    this->id=od;
    this->nombre=nom;
    this->edad=ed;
    this->nacionalidad=nac;

    //srand(time(NULL));
    //this->id = this->li_u + rand() % (this->ls_u + 1 -this->li_u); //Randomizacion de la id
}