#include <iostream>
#include <vector>
#include <string>
#include "redSocial2.h"
#include "usuario2.h"
#include "publicacion2.h"
using namespace std;

int main() {
    RedSocial pruebaRed("SHOPIBUY");
    int option;
    again:
    option = 0;
    cout << "0. Salir" << endl << "1. Lista de usuarios" << endl << "2. Lista de pubicaciones" << endl << "3. Explorar usuario" << endl << "4. Agregar usuario";
    cin >> option;
    switch(option) {
        case 1: {
            pruebaRed.mostrarUsuarios();
            break;
        }
        case 2: {
            pruebaRed.mostrarPublicaciones();
            break;
        }
        case 3: {
            int idUsuario;
            cout << "Ingrese el ID del usuario que desea encontrar" << endl;
            cin >> idUsuario;

            Usuario* usuarioExplorado = pruebaRed.getUsuario(idUsuario);
            if (usuarioExplorado != nullptr) {
                cout << "Infromacion del usuario:" << endl;
                cout << "Nombre: " << usuarioExplorado->nombre << endl;
                cout << "Edad: " << usuarioExplorado->edad << endl;
                cout << "Nacionalidad: " << usuarioExplorado->nacionalidad << endl;
                cout << endl;

                cout << "Amigos de usuario" << endl;
                usuarioExplorado->mostrarAmigos();
                cout << endl;

                cout << "Publicaciones del usuario:" << endl;
                usuarioExplorado->mostrarPublicaciones();
                cout << endl;
            } else {
                cout << "No se encontraron coincidencias con el ID que ingreso" << endl;
            }
            break;
        }
        case 4: {
            string name, nationality;
            int age;
            cout << "Ingrese el nombre, edad y nacionalidad del nuevo usuario" << endl;
            cin >> name >> age >> nationality;
            Usuario newusuario(name, age, nationality);
            pruebaRed.agregarUsuario(&newusuario);
            break;
        }
        default: {
            cout << endl << endl << endl;
            goto again;
            break;
        }
    }

    return 0;
}

