#include <iostream>
#include "publicacion2.h"
#include "usuario2.h"
#include "redSocial2.h"
#include "venta.h"

Venta::Venta(int id, Usuario* usuario, string fecha, string contenido, float precio, string lugarDeVenta)
    : Publicacion(id, usuario, fecha, contenido), precio(precio), lugarDeVenta(lugarDeVenta) {}

void Venta::mostrarPublicacion() {
    Publicacion::mostrarPublicacion();
    cout << "Precio: " << precio << endl;
    cout << "Lugar de Venta: " << lugarDeVenta << endl;
}
