#include <iostream>
#include "usuario2.h"
#include "redSocial2.h"
#include "publicacion2.h"
#include "venta.h"

Venta::Venta(int id, Usuario* usuario, string fecha, string contenido, double precio, string lugarDeVenta)
    : Publicacion(id, usuario, fecha, contenido), precio(precio), lugarDeVenta(lugarDeVenta) {}

void Venta::mostrarVenta() {
    mostrarPublicacion();
    cout << "Precio: $" << precio << endl;
    cout << "Lugar de venta: " << lugarDeVenta << endl;
}