#include <iostream>
#include <vector>
#include <string>
#include "redSocial2.h"
#include "usuario2.h"
#include "publicacion2.h"
#include "venta.h"
using namespace std;
 
int main() {
        Usuario new1(1,"Orion",16,"Mexicano");
        Usuario new2(2,"Santiago",18,"Extraterrestre");
        Usuario new3(3,"Juan",17,"Chileno");
        Publicacion puw1(1,&new1,"08/04/2024","No me funciona el codigo, pipipipi",0);
        Publicacion puw2(2,&new3,"14/05/2024","No me importa",1);
        Publicacion puw3(3,&new1,"015/04/2024","Como asi chavalin, PREOCUPESE",2);
            new1.agregarPublicacion(&puw1);
            new3.agregarPublicacion(&puw2);
            new1.agregarPublicacion(&puw3);
                vector <Usuario*> usus;
                vector <Publicacion*> publ;
        usus.push_back(&new1);
        usus.push_back(&new2);
        usus.push_back(&new3);
            publ.push_back(&puw1);
            publ.push_back(&puw2);
            publ.push_back(&puw3);
    RedSocial shopibuy("SHOPIBUY",usus,publ);
    int option,odu=4,odp=4,odv=1;
    bool off=0;
    again:
    option = 0;
    cout<<"SHOPIBUY .MENU"<<endl<<endl;
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
            shopibuy.mostrarUsuarios();
            off=1;
            break;
        }
        case 2: {
            shopibuy.mostrarPublicaciones();
            off=1;
            break;
        }
        case 3: {

            int idUsuario,uMenuOp=1,id_before,idUsuarioAmigo,idUsuarioPos;
            bool forAmigo,alreadyAmigo;
            Usuario* usuarioExplorado;
            Usuario* usuarioExploradoNewAmigo;

            cout << ".INGRESE EL ID DEL USUARIO QUE DESEA ENCONTRAR" << endl<<endl<<"-->";
            cin >> idUsuario;
            exploreAmigo:
            forAmigo=0;
            usuarioExplorado = shopibuy.getUsuario(idUsuario);
            if (usuarioExplorado != nullptr)
            {
                    MenuUsu:
                    alreadyAmigo = 0;
                while(uMenuOp!=0){
                cout<<".MENU USUARIO --- "<<shopibuy.getUsuario(idUsuario)->nombre << endl<<endl;
                    if(uMenuOp==1){
                cout<<endl;
                cout << ".INFORMACION DEL USUARIO:" << endl;
                cout << "Nombre: " << shopibuy.getUsuario(idUsuario)->nombre << endl;
                cout << "Edad: " << shopibuy.getUsuario(idUsuario)->edad << endl;
                cout << "Nacionalidad: " << shopibuy.getUsuario(idUsuario)->nacionalidad << endl;
                cout << endl<<endl;
                    }

                cout<<"0. SALIR"<<endl;
                cout<<"1. VER INFORMACION DEL USUARIO "<<endl;
                cout<<"2. VER LISTA DE AMIGOS"<<endl;
                cout<<"3. VER PUBLICACIONES"<<endl;
                cout<<"4. CREAR PUBLICACION"<<endl;
                cout<<"5. ENTRAR A PERFIL DE AMIGO"<<endl;
                cout<<"6. AGREGAR UN NUEVO AMIGO"<<endl<<endl<<"--> ";
                cout<<"7. CREAR VENTA"<<endl;
                cin>>uMenuOp;
                if (uMenuOp == 1){
                    
                }
                if(uMenuOp == 2){

                    cout << ".AMIGOS DEL USUARIO" << endl;
                    shopibuy.getUsuario(idUsuario)->mostrarAmigos();
                    cout << endl;
                }
                if (uMenuOp == 3){

                    cout << ".PUBLICACIONES DEL USUARIO" << endl;
                    shopibuy.getUsuario(idUsuario)->mostrarPublicaciones();
                    cout << endl;
                    goto MenuUsu;
                }
                if (uMenuOp == 4){
                    shopibuy.numeroDePublicaciones++;
                   // shopibuy.getUsuario(idUsuario)->crearPublicacion(odp);
                     shopibuy.agregarPublicaciones(shopibuy.getUsuario(idUsuario)->crearPublicacion(odp));
                   // cout<<". */
                    //crearPublicacion();                                                             YEEEEEEEEEEEEAAAAAAAAAAAAAHHHHHH"<<endl;
                    goto exploreAmigo;
                }
                if (uMenuOp == 5){
                    cout << ".INGRESE EL ID DEL AMIGO QUE DESEA ENCONTRAR" << endl<<endl<<"--> ";
                    cin >> idUsuarioAmigo;
                    for (int i=0;i < shopibuy.getUsuario(idUsuario)->amigos.size();i++){
                        if (idUsuarioAmigo==shopibuy.getUsuario(idUsuario)->amigos[i]->getId()){
                            forAmigo=1;
                        }
                    }
                    if (forAmigo==1){
                    idUsuario=idUsuarioAmigo;
                    goto exploreAmigo;
                    }else {
                        if (idUsuario==idUsuarioAmigo){
                            cout<<".ESTE USUARIO NO ES TU AMIGO PUES ERES TU"<<endl;
                        }else {
                            cout<<".ESTE USUARIO NO ES TU AMIGO"<<endl;
                        }
                    }
                }
                if (uMenuOp == 6){
                    shopibuy.mostrarUsuarios();
                    cin>>idUsuarioAmigo;
                    if (idUsuarioAmigo!=idUsuario){
                        for (int i=0;i<shopibuy.getUsuario(idUsuario)->amigos.size();i++){
                            if (idUsuarioAmigo == shopibuy.getUsuario(idUsuario)->amigos[i]->getId()){
                                alreadyAmigo = 1;
                            }
                        }
                        if (alreadyAmigo == 1){
                            cout<<".ESTE USUARIO YA ES TU AMIGO"<<endl;
                        }else {
                            usuarioExploradoNewAmigo = shopibuy.getUsuario(idUsuarioAmigo);
                            shopibuy.getUsuario(idUsuario)->agregarAmigos(usuarioExploradoNewAmigo);
                            alreadyAmigo = 0;
                        }
                    }else {
                        cout<<".NO PUEDES SER TU PROPIO AMIGO BOOMER"<<endl;
                    }
                }
                if (uMenuOp == 7){
                     shopibuy.numeroDeVentas++;
                     shopibuy.agregarVentas(shopibuy.getUsuario(idUsuario)->crearVenta(odv));
                     odv++;
                     goto exploreAmigo;
                }

                }
            } else {
                cout << ".NO SE ENCONTRARON COINCIDENCIAS CON EL ID QUE INGRESO" << endl;
            }
            off=1;
            break;
        }
        case 4: {
            string name, nationality;
            int age;
            cout << "Ingrese el nombre, edad y nacionalidad del nuevo usuario" << endl;
            cin >> name >> age >> nationality;
            //pruebaRed.ayuda_AU(odu);

            Usuario* newusuario = new Usuario(odu,name, age, nationality);
            shopibuy.agregarUsuario(newusuario);
            odu++;
            off=1;
            break;
        }
        default: {
            cout<<". INSERTE UNA OPCION CONSIDERADA POR EL PROGRAMA"<<endl<<endl;
            off=1;
            break;
        }
    }

    if (off==1){
        goto again;
    }
    cout<<"BYE BYE";
    return 0;
}