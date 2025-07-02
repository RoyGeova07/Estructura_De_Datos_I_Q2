#ifndef COLA_H
#define COLA_H
#include<iostream>
using namespace std;

template<typename T>
struct Nodo
{
    
    T dato;
    Nodo*siguiente;
    Nodo(T Valor):dato(Valor),siguiente(nullptr){}

};

template<typename T>
class Cola{

private:
Nodo<T>*frente;
Nodo<T>*atras;

public:

Cola():frente(nullptr),atras(nullptr){}

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

        cout<<"cola vacia bro\n";
        return;

    }
    Nodo<T>*aux=frente;
    frente=frente->siguiente;
    cout<<"Elemento "<<aux->dato<<" elimanado con exito";
    delete frente;
    if(frente==nullptr)atras=nullptr;

}

void Mostrar()
{

    Nodo<T>*actual=frente;
    while(actual!=nullptr)
    {

        cout<<actual->dato<<" -> ";
        actual=actual->siguiente;

    }
    cout<<"null"<<endl;

}

};  






#endif //COLA_H