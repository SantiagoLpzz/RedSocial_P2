#ifndef publicacion2_h
#define publicacion2_h

#include <iostream>
#include <vector>
#include <string>

class Usuario; 

using namespace std;

class Publicacion{
private:
    int idp;
public:
    int idRespuesta;
    string fecha;
    string contenido;
    Usuario* usuario;

//METODOS
    int getIdp();
    void mostrarPublicacion();
//CONSTRUCTORES
    Publicacion(int od,Usuario* usuario, string fecha, string contenido,int idrespuesta);
};

#endif