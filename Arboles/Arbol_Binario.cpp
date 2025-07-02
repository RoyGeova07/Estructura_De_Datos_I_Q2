#include<iostream>
using namespace std;

struct Nodo
{
    
    int dato;
    Nodo*izquierda;
    Nodo*derecha;


    Nodo(int val):dato(val),izquierda(nullptr),derecha(nullptr){}

};

//esta funcion me ayudara a recorrer el arbol en preorden, es decir, primero el nodo actual, luego la izquierda y por ultimo la derecha
void preOrden(Nodo* nodo)
{

    if(nodo!=nullptr)
    {

        cout<<nodo->dato<<" ";//muestra el valor del nodo actual
        preOrden(nodo->izquierda);//llama a la funcion recursivamente para el nod izquierdo
        preOrden(nodo->derecha);//llama a la funcion recursivamente para el nodo derecho

    }
    //ejemplo visual
    // si el arbol es: 
//      10
//     
//    5   15

// la salida sera 
//10,5,15

//porque primero visita al 10, luego al izquierdo 5 y por ultimo al derecho 15

}

int main()
{

    Nodo*raiz=new Nodo(10);
    raiz->izquierda=new Nodo(5);
    raiz->derecha=new Nodo(15);

    cout<<"Recorrido Preorden del arbol binario\n";
    preOrden(raiz);

    return 0;
}

