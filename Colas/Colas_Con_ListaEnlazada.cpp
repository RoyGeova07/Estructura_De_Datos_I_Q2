#include"Colas_Con_ListaEnlazada.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{

    int opcion;
    string valor;
    Cola<string>cola;

    while(opcion!=4)
    {

        cout<<"\t\n=====MENU=====\t\n";
        cout<<"1. Insertar dato a cola\n";
        cout<<"2. Eliminar dato a cola\n";
        cout<<"3. mostrar\n";
        cout<<"4. salir\n";
        cout<<"Ingrese una opcion: \n";
        cin>>opcion;

        if(opcion==1)
        {

            cout<<"\nIngrese un dato: ";
            cin>>valor;
            cola.Insertar(valor);
            cout<<"\nElemento ingresado correctamnte a la cola\n";

        }else if(opcion==2){

            cola.Eliminar();
            cout<<"Elemento eliminado exitosamente\n";

        }else if(opcion==3){

            cout<<"Mostrando los elementos \n";
            cola.Mostrar();

        }else{

            cout<<"\nopcion no valida internte de nuevo: ";

        }
        

    }
    cout<<"terminai";

    return 0;
}