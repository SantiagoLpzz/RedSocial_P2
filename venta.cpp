#include <iostream>
#include "usuario2.h"
#include "redSocial2.h"
#include "publicacion2.h"
#include "venta.h"

using namespace std;

Venta::Venta(int id, Usuario* usuario, string fecha, string contenido, double precio, string lugarDeVenta) : Publicacion(id, usuario, fecha, contenido), precio(precio), lugarDeVenta(lugarDeVenta) {
    this->idv = id;
    this->usuario = usuario;
    this->fecha = fecha;
    this->contenido = contenido;
    this->precio = precio;
    this->lugarDeVenta = lugarDeVenta;
    }

void Venta::mostrarVenta() {
    cout<<"----------"<<endl;
    cout<<"| "<<this->fecha<<endl;
    cout<<"| < Descripcion: "<<this->contenido<<" >"<<endl;
    cout<<"| >>> $"<<this->precio<<" <<<"<<endl;
    cout<<"| >>> Visitalo en: "<<this->lugarDeVenta<<" <<<"<<endl;
    cout<<"| --> "<<this->usuario->nombre<<" .ID "<<this->usuario->getId()<<endl;
    cout<<"------------------------- .ID Venta "<<this->idv<<endl;
    //mostrarPublicacion(); <--no funciona porque necesita idp de class Publicacion y esa variable es privada
    cout << "Precio: $" << precio << endl;
    cout << "Lugar de venta: " << lugarDeVenta << endl;
}