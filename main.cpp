#include <iostream>
#include <vector>
#include <string>
#include "redSocial2.h"
#include "usuario2.h"
#include "publicacion2.h"
using namespace std;

int main() {
    Usuario new1(1,"Orion",16,"Mexicano");
    Usuario new2(2,"Santiago",18,"Extraterrestre");
    Usuario new3(3,"Juan",17,"Chileno");
    vector <Usuario*> usus;
    usus.push_back(&new1);
    usus.push_back(&new2);
    usus.push_back(&new3);
    RedSocial pruebaRed("SHOPIBUY",usus);
    int option,od=4;
    bool off=0;
    again:
    option = 0;
    cout<<".MENU"<<endl<<endl;
    cout << "0. Salir" << endl;
    cout << "1. Lista de usuarios" << endl;
    cout << "2. Lista de pubicaciones" << endl;
    cout << "3. Explorar usuario" << endl;
    cout << "4. Agregar usuario"<<endl<<endl<<"--> ";
    cin >> option;
    switch(option) {
        case 0: {
            off=0;
            break;
        }
        case 1: {
            pruebaRed.mostrarUsuarios();
            off=1;
            break;
        }
        case 2: {
            pruebaRed.mostrarPublicaciones();
            off=1;
            break;
        }
        case 3: {

            int idUsuario,uMenuOp=1,id_before,idUsuarioAmigo;
            Usuario* usuarioExplorado;
            Usuario* usuarioExploradoNewAmigo;

            exploreAmigo:
            cout << ".INGRESE EL ID DEL USUARIO QUE DESEA ENCONTRAR" << endl<<endl<<"-->";
            cin >> idUsuario;

            usuarioExplorado = pruebaRed.getUsuario(idUsuario);
            if (usuarioExplorado != nullptr)
            {
                while(uMenuOp!=0){
                cout<<".MENU USUARIO --- "<<pruebaRed.getUsuario(idUsuario)->nombre << endl<<endl;
                    if(uMenuOp==1){
                cout<<endl;
                cout << ".INFORMACION DEL USUARIO:" << endl;
                cout << "Nombre: " << pruebaRed.getUsuario(idUsuario)->nombre << endl;
                cout << "Edad: " << pruebaRed.getUsuario(idUsuario)->edad << endl;
                cout << "Nacionalidad: " << pruebaRed.getUsuario(idUsuario)->nacionalidad << endl;
                cout << endl<<endl;
                    }

                cout<<"0. SALIR"<<endl<<"1. VER INFORMACION DEL USUARIO "<<endl<<"2. VER LISTA DE AMIGOS"<<endl<<"3. VER PUBLICACIONES"<<endl<<"4. CREAR PUBLICACION"<<endl<<"5. ENTRAR A PERFIL DE AMIGO"<<endl<<"6. AGREGAR UN NUEVO AMIGO"<<endl<<endl<<"-->";
                cin>>uMenuOp;
                if (uMenuOp == 1){
                    
                }
                if(uMenuOp == 2){

                    cout << ".AMIGOS DEL USUARIO" << endl;
                    pruebaRed.getUsuario(idUsuario)->mostrarAmigos();
                    cout << endl;
                }
                if (uMenuOp == 3){

                    cout << ".PUBLICACIONES DEL USUARIO" << endl;
                    pruebaRed.getUsuario(idUsuario)->mostrarPublicaciones();
                    cout << endl;
                }
                if (uMenuOp == 4){
                    pruebaRed.getUsuario(idUsuario)->crearPublicacion();
                }
                if (uMenuOp == 5){
                    goto exploreAmigo;
                }
                if (uMenuOp == 6){
                    pruebaRed.mostrarUsuarios();
                    cin>>idUsuarioAmigo;
                    usuarioExploradoNewAmigo = pruebaRed.getUsuario(idUsuarioAmigo);
                    pruebaRed.getUsuario(idUsuario)->agregarAmigos(usuarioExploradoNewAmigo);
                }

                }
            } else {
                cout << ".NO SE ENCONTRARON COINCIDENCIAS CON EL ID QUE INGRESO" << endl;
            }
        

            /*
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
            }*/
            off=1;
            break;
        }
        case 4: {
            string name, nationality;
            int age;
            cout << "Ingrese el nombre, edad y nacionalidad del nuevo usuario" << endl;
            cin >> name >> age >> nationality;
            Usuario newusuario(od,name, age, nationality);
            od++;
            pruebaRed.agregarUsuario(&newusuario);
            off=1;
            break;
        }
        default: {
            cout<<". INSERTE UNA OPCION CONSIDERADA PRO EL PROGRAMA"<<endl<<endl;
            off=1;
            break;
        }
    }

    if (off==1){
        goto again;
    }
    return 0;
}

