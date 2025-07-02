#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class Grafo{

    int numNodos;
    vector<vector<pair<int,int>>>adj;

    public:
        explicit Grafo(int nodos):numNodos(nodos),adj(nodos){}

        void AgregarArista(int origen,int destino,int peso){

            if(origen<0||destino<0||origen>numNodos||destino>numNodos)
            {

                throw out_of_range("Vertice fuera de rango");

            }else{

                adj[origen].emplace_back(destino,peso);

            }
            

        }

        void MostrarLista()
        {
 
            cout<<"**** LISTA DE ADYACENCIA ****\n";
            for(int i=0;i<numNodos;i++)
            {

                cout<<"Nodo -> "<<i<<": ";
                for(const auto& [vecino,peso]:adj[i])
                {

                    cout<<"("<<vecino<<","<<peso<<") ";

                }
                cout<<endl;

            }

        }
  

        void BFS(int inicio)
        {

            vector<bool>visitado(numNodos,false);
            queue<int>q;

            q.push(inicio);
            visitado[inicio]=true;

            cout<<"Recorrido BFS desde el nodo "<<inicio<<": ";
            while(!q.empty())
            {

                int nodo=q.front();
                q.pop();
                cout<<nodo<<" ";

                for(const auto& [vecino,peso]:adj[nodo])
                {

                    if(!visitado[vecino])
                    {

                        visitado[vecino]=true;
                        q.push(vecino);

                    }

                }

            }
            cout<<endl;

        }

        void DFS(int inicio)
        {

            vector<bool>visitado(numNodos,false);
            stack<int>pila;

            pila.push(inicio);

            cout<<"Recorrido DFS desde el nodo "<<inicio<<": ";
            while(!pila.empty())
            {

                int nodo=pila.top();
                pila.pop();
                if(!visitado[nodo])
                {

                    visitado[nodo]=true;
                    cout<<nodo<<" ";
                    for(const auto& [vecino,peso]:adj[nodo])
                    {

                        if(!visitado[vecino])
                        {

                            pila.push(vecino);

                        }

                    }
                
                }

            }
            cout<<endl;

        }

};

int main()
{

    try
    {

        Grafo grafo(5);

        grafo.AgregarArista(0,1,10);
        grafo.AgregarArista(0,2,20);
        grafo.AgregarArista(1,2,30);
        grafo.AgregarArista(2,3,40);

        grafo.BFS(0);
        grafo.DFS(0);

        grafo.MostrarLista();

    }catch(const exception& e){

        cerr<<"\nERROR: "<<e.what()<<'\n';

    }

    return 0;

}