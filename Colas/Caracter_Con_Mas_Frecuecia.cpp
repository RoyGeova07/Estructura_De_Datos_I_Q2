#include"Caracter_Con_Mas_Frecuencia.h"
#include<iostream>
#include<string>
using namespace std;

Cola<char> cola;

char CaracterMasBuscado(Cola<char> cola)
{

    int contador[256]={0};//CODIGO ASCIIIII
    while (!cola.vacio())
    {
        
        char letra=cola.Tope();
        contador[(unsigned char)letra]++;
        cola.Eliminar();

    }

    //aqui buscamo el caracter con mayor con frecuencia
    int max=0;
    char frecuente='\0';

    for (int i = 0; i < 256; i++)
    {
        
        if(contador[i]>max)
        {

            max=contador[i];
            frecuente=(char)i;

        }

    }
    
    return frecuente;

}

int main()
{

    int opcion;
    char letrita;
    Cola<char> cola;

    while (opcion!=5)
    {
        
        cout<<"\nMENUUUUU\n";
        cout<<"1. AGREGAR\n";
        cout<<"2. ELIMINAR\n";
        cout<<"3. MOSTRA\n";
        cout<<"4. CARACTER POPULAR\n";
        cout<<"5. SALIR\n";
        cout<<"Ingrese una opcion: \n";
        cin>>opcion;

        if(opcion==1)
        {

            cout<<"Ingrese un caracter: \n";
            cin>>letrita;
            cola.Insertar(letrita);
            cout<<"\nCaracter '"<<letrita<<"' ingresado correctamente\n";

        }else if(opcion==2){

            cola.Eliminar();

        }else if(opcion==3){

            cout<<"\nMostrando la cola\n";
            cola.Mostrar();

        }else if(opcion==4){

        }else if(opcion==5){

            cout<<"SALIENDOOOOOO\n";
            break;

        }

    }
    

}