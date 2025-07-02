#include<iostream>
#include"GrafoMatriz.h"

using namespace std;

int main()
{

    try
    {
        
        GrafoMatriz grafo(5);//aqui se crea un grafo con capaciad de 5 vertices 

        grafo.AgregarVertice("A");
        grafo.AgregarVertice("B");
        grafo.AgregarVertice("C");
        grafo.AgregarVertice("D");

        grafo.AgregarArco("A","B");
        grafo.AgregarArco("A","C");
        grafo.AgregarArco("B","D");
        grafo.AgregarArco("C","D");
        grafo.AgregarArco("D","A");

        //aqui se muestra la informacion del grafo
        cout<<"Grafo creado con " <<grafo.getNumVertices()<<" vertices de "<<grafo.getCapacidad()<<" posibles.\n";

        //aqui se verifica si son adyacentes
        cout<<"\n Verificando adyacencia:\n";
        cout<<"A -> B: "<<(grafo.esAdyacente("A","B")? "Si":"No")<<endl;
        cout<<"B -> A "<<(grafo.esAdyacente("B","A")?"Si":"No")<<endl;

        grafo.MatrizAdyacencia();

    }catch(const std::exception& e){

        std::cerr <<"\nERORR: "<<e.what()<<'\n';
        return 1;

    }
    

    return 0;
}