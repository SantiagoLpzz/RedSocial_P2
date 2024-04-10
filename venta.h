#ifndef venta_h
#define venta_h

#include "publicacion2.h"

using namespace std;

class Venta : public Publicacion {
private:
    float precio;
    string lugarDeVenta;
public:
    Venta(int id, Usuario* usuario, string fecha, string contenido, float precio, string lugarDeVenta);
    void mostrarPublicacion() override;
    // Otros métodos necesarios...
};

#endif
