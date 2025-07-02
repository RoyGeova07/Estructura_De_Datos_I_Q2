#include<iostream>
#include<vector>

using namespace std;

class ListaGrafo
{

    private:
        int numVertice;
        vector<vector<pair<int,int>>>ListaA;//pair porque va tener 2 pares, destino y peso | LISTA A

    public:
        explicit ListaGrafo(int V):numVertice(V),ListaA(V){}

        void AgregarArista(int origen,int destino,int peso)//tiene q tener un origen un destino y un peso
        {

            if(origen<0||origen>numVertice||destino<0||destino>numVertice)
            {

                throw out_of_range("Vertice fuera de rango");

            }else{
                //con esto se relaciona 
                ListaA[origen].emplace_back(destino,peso);//emplace_back agrega un elemento al final del vector, en este caso agrega un par de destino y peso

            }
            

        }

        void MostrarLista()
        {

            cout<<"***** LISTA DE ADYACENCIA *****\n";
            for(int i=0;i<numVertice;i++)//con este for recorre de cada nodo
            {

                cout<<"Nodo -> "<<i<<": ";
                for(const auto& [vecino,peso]:ListaA[i])//arista es un par de destino y peso
                {

                    cout<<"("<<vecino<<","<<peso<<") ";//aqui se imprime el vecino y el peso de la arista

                }
                cout<<endl;


            }


        }
        
 

};

int main()
{

    ListaGrafo grafo(4);

    grafo.AgregarArista(0,1,10);
    grafo.AgregarArista(0,2,20);
    grafo.AgregarArista(1,2,30);
    grafo.AgregarArista(2,3,40);

    grafo.MostrarLista();

    return 0;
}