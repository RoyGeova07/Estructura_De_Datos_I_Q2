#ifndef COLA
#define COLA
#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T>
struct Nodo
{
    
    T valor;
    Nodo*siguiente;
    Nodo(T valor):valor(valor),siguiente(nullptr){}

};

template<typename T>
class Cola{

private: 

Nodo<T>*frente;
Nodo<T>*atras;

public:

bool vacio()const
{

    return frente==nullptr;

}

void Insertar(T valor)
{

    Nodo<T>*nuevo=new Nodo<T>(valor);
    if(vacio())
    {

        frente=atras=nuevo;

    }else{

        atras->siguiente=nuevo;
        atras=nuevo;

    }

}

void Eliminar()
{

    if(vacio())
    {

        cout<<"vacio bro\n";
        return;

    }
    Nodo<T>*aux=frente;
    frente=frente->siguiente;
    cout<<"Elemento "<<aux->valor<<" eliminado exitosamente\n";
    delete aux;
    if(frente==nullptr)atras=nullptr;

}

void Mostrar()
{

    Nodo<T>*actual=frente;
    while (actual!=nullptr)
    {
        
        cout<<actual->valor<<" -> ";
        actual=actual->siguiente;

    }
    cout<<"null"<<endl;
    

}

T Tope()const
{

    if(vacio())
    {

        throw runtime_error("\nvacio brou\n");

    }
    return frente->valor;

}
    

};


#endif // COLA