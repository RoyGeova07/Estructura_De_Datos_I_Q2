#include <iostream>
using namespace std;

struct Nodo
{
    
    int dato;
    Nodo*derecho;
    Nodo*izquierdo;

};

Nodo*Arbol=nullptr;

//primero creamos el nodo
Nodo*CrearNodo(int n)
{

    Nodo*nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;
    nuevo_nodo->derecho=nullptr;
    nuevo_nodo->izquierdo=nullptr;

    return nuevo_nodo;

}

//Ahora la funcion de insertar elementos en el arbol
void InsertarNodo(Nodo*&arbol,int n)
{

    //para insertar un nodo en el arbol, hay q tener en cuenta que:
    // El arbol puede estar vacio
    //El arbol ya tiene un nodo o mas

    if(arbol==nullptr)//si el arbol esta vacio, se crea un nuevo nodo
    {

        Nodo *nuevo_nodo=CrearNodo(n);
        arbol=nuevo_nodo;

    }else{//Si el nodo tiene uno o mas de un nodo 

        //obtenemos el valor de la raiz
        int ValorRaiz=arbol->dato;

        if(n<ValorRaiz)//si el elemento que queremos insertar es menor que el valor de la raiz, se insertara al lado izquierdoo
        {

            InsertarNodo(arbol->izquierdo,n);//recurisividaddd ;)

        }else{//si el elemento es mayor a la raiz, insertamos en derecho

            InsertarNodo(arbol->derecho,n);

        }

    }

}

void Menu()
{

    int dato,opcion;
    do
    {
        
        cout<<"\n=====Menu====\n";
        cout<<"1. Insertar un nuevo nodo\n";
        cout<<"2.Salir\n";
        cout<<"Elija una opcion: ";
        cin>>opcion;

        if (opcion==1)
        {
            
            cout<<"\nDigite un numero: ";
            cin>>dato;
            InsertarNodo(Arbol,dato);
            cout<<"\n";
            

        }
        else if (opcion==2)
        {
            
            cout<<"\nTermino\n";
            break;

        }
        else
        {
            cout<<"\nOpcion no valida\n";
        }
        

    } while (opcion!=2);
    
    

}

int main()
{

    Menu();

}