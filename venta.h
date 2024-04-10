#ifndef venta_h
#define venta_h

#include <iostream>
#include "publicacion2.h"
#include "redSocial2.h"
#include "usuario2.h"

class Venta : public Publicacion {
private:
    double precio;
    string lugarDeVenta;

public:
    Venta(int id, Usuario* usuario, string fecha, string contenido, double precio, string lugarDeVenta);
    void mostrarVenta();
};

#endif
