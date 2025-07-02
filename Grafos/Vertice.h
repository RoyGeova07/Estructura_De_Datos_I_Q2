#ifndef VERTICE_H
#define VERTICE_H
#include<iostream>
#include<string>
using namespace std;

class Vertice
{
private:
    string nombre;
    int id;
public:
    
    Vertice():nombre(""),id(-1){}//vertice 

    Vertice(const string& nombre):nombre(nombre),id(-1){}

    Vertice(const string& nombre,int id):nombre(nombre),id(id){}

    //getters
    const string& getNombre()const{return nombre;}

    int getId()const{return id;}
    //setters
    void setNombre(const string& nuevoNombre){nombre=nuevoNombre;}
    void setId(int nuevoId){id=nuevoId;}

    bool operator==(const Vertice& otro)const
    {

        return nombre==otro.nombre;

    }
};
#endif //VERTICE_H