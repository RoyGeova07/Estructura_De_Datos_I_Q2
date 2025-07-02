#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H
#include"Vertice.h"
#include<vector>
#include<stdexcept>
#include<iostream>
using namespace std;

class GrafoMatriz
{
private:
    
    int capacidad;
    int numVertices;
    vector<Vertice>vertices;
    vector<vector<int>>matrizAdyacencia;

    int encontrarIndice(const string&nombre)const
    {

        for (int i=0;i<numVertices;i++)
        {
            
            if(vertices[i].getNombre()==nombre)
            {

                return i;

            }

        }
        return-1;
        

    }

public:
    
    explicit GrafoMatriz(int maxVertices):capacidad(maxVertices),numVertices(0),vertices(maxVertices),matrizAdyacencia(maxVertices,vector<int>(maxVertices,0)){}

    int getNumVertices()const{return numVertices;}
    int getCapacidad()const{return capacidad;}

    void AgregarVertice(const string&nombre)
    {

        
        if(encontrarIndice(nombre)!=-1)//si no lo encuentra es -1 
        {

            throw runtime_error("el vertice ya existe");

        }

        if(numVertices>=capacidad)
        {

            throw runtime_error("Capacidad maxima de vertices alcanzada");

        }

        vertices[numVertices]=Vertice(nombre,numVertices);
        numVertices++;

    }

    bool ExisteArista(const string&origen,const string&destino)
    {

        int indexOrigen=encontrarIndice(origen);
        int indexDestino=encontrarIndice(destino);

        if(indexOrigen==-1||indexDestino==-1)return false;
        return matrizAdyacencia[indexOrigen][indexDestino]!=0;

    }

    bool esAdyacente(const string&origen,const string&destino)const
    {

        int indexOrigen=encontrarIndice(origen);
        int indexDestino=encontrarIndice(destino);

        if(indexOrigen==-1||indexDestino==-1)
        {

            throw runtime_error("Uno o ambos vertices no existen");

        }
        return matrizAdyacencia[indexOrigen][indexDestino]!=0;


    }

    const Vertice& ObtenerVertice(int indice)const{

        if(indice<0||indice>=numVertices)
        {

            throw out_of_range("Indice fuera de rango");

        }
        return vertices[indice];

    }

    void MatrizAdyacencia()const
    {

        //si esta vacio
        if(numVertices==0)
        {

            cout<<"El grafo esta vacio"<<endl;
            return;

        }

        cout<<"\nMatriz Adyacencia:\n";
        cout<<"  ";
        for (int i = 0; i < numVertices; i++)
        {
            
            cout<<vertices[i].getNombre()<<" ";

        }
        cout<<endl;

        for (int i = 0; i < numVertices; i++)
        {
            
            cout<<vertices[i].getNombre()<<" ";
            for (int j = 0; j < numVertices; j++)
            {
                
                cout<<matrizAdyacencia[i][j]<<" ";

            }
            cout<<endl;
            

        }
        
        

    }

    void AgregarArco(const string&origen,const string&destino,int valor=1)
    {

        int indexOrigen=encontrarIndice(origen);
        int indexDestino=encontrarIndice(destino);

        if(indexOrigen==-1||indexDestino==-1)
        {

            throw runtime_error("Uno o ambos vertices no existen");

        }
        matrizAdyacencia[indexOrigen][indexDestino]=valor;

    }

    const vector<vector<int>>&getMatriz()const
    {

        return matrizAdyacencia;

    }

};

#endif // GRAFOMATRIZ_H