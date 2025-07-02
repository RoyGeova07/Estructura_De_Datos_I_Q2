#include <iostream>
#include <limits.h>
using namespace std;

const int N = 7; // Cantidad de nodos: I, A, B, C, D, E, T
const int INF = INT_MAX;//se usa INT_MAX para representar infinito, que es un valor muy grande que no se puede alcanzar en el grafo

// Indices de los nodos
// 0: I, 1: A, 2: B, 3: C, 4: D, 5: E, 6: T
string nombres[] = {"I", "A", "B", "C", "D", "E", "T"};

//con esta matriz de adyacencia representamos el grafo de quien esta conectado con quien
int matriz[N][N] = {
    // I  A  B  C  D  E  T
    { 0, 7, 6, 8, 0, 0, 0 }, // I
    { 7, 0, 0, 0, 2, 0, 0 }, // A
    { 6, 0, 0, 0, 7, 0, 0 }, // B
    { 8, 0, 0, 0, 3, 4, 0 }, // C
    { 0, 2, 7, 3, 0, 5, 1 }, // D
    { 0, 0, 0, 4, 5, 0, 1 }, // E
    { 0, 0, 0, 0, 1, 1, 0 }  // T
};

void dijkstra(int inicio, int destino) {
    int distancia[N];//este variable guarda la distancia mas corta de cada nodo
    bool visitado[N] = {false};//esta variabel guarda si un nodo ya fue visitado
    int previo[N];//esta variable guarda el nodo anterior en el camino mas corto

    //con este bucle recorremos todo los nodos para incializar las distancias entre el nodo de inicio y los demas nodos
    for (int i=0;i<N;i++) {
        distancia[i]=INF;//usamos INF porque no conocemos la distancia inicial
        previo[i]=-1;//no hay nodo previo al inicio
    }
    distancia[inicio]=0;//la distancia al nodo de inicio es 0, porque no hay distancia que recorrer para llegar al mismo nodo

    //este bucle sirve para recorrer todos los nodos y encontrar el camino mas corto
    for (int i=0;i<N;i++) {
        int minDist=INF;//inicialiamos la distancia minima como infinito, porque no conocemos la distancia minima al inicio
        int nodo=-1;//inicializamos el nodo como -1, que significa que no hay nodo seleccionado

        //este bucle sirve para encontrar el nodo con la distancia minima que no ha sido visitado
        for(int j=0;j<N;j++){
            if(!visitado[j]&&distancia[j]<minDist)//si el nodo no fue visitado y su distacia es menor que la minima
            {
                minDist=distancia[j];//entonces actualizamos la distancia minima
                nodo=j;//y actualizamos el nodo seleccionado
            }
        }

        if(nodo==-1)break;//con esto verificamos si no hay mas nodos por visitar, si es asi salimos del bucle
        visitado[nodo]=true;//marcamo el nodo como visitado

        //y por ultimo, recorremos todos los nodos para actualiza las distancias de los nodos vecinos al nodo seleccionado
        for(int k=0;k<N;k++) 
        {
            if(matriz[nodo][k]!=0&&!visitado[k]) {//si hay una conexion entre el nodo actual y el nodo k, y el nodo k no fue visitado
                int nuevaDist = distancia[nodo] + matriz[nodo][k];//entonces calculamos la nueva distancia desde el nodo actual al nodo k
                if(nuevaDist < distancia[k]) {//si la nueva distancia es menor que la distancia actual

                    distancia[k] = nuevaDist;//entontces actualizamos la distancia
                    previo[k] = nodo;// y guardamos el nodo actual como el nodo previo de k

                }
            }
        }
    }

    // Mostrar resultado
    if (distancia[destino] == INF) {
        cout << "No hay ruta desde " << nombres[inicio] << " hasta " << nombres[destino] << endl;
        return;
    }

    // Reconstruir camino
    int actual = destino;
    string ruta = nombres[actual];
    while (previo[actual] != -1) {//mientras haya un nodo previo
        actual = previo[actual];//actualizamos el nodo actual al nodo previo
        ruta = nombres[actual] + " -> " + ruta;//agregamo el nodo actual al inicio de la ruta
    }

    cout << "Ruta mas corta: " << ruta << endl;
    cout << "Costo total: " << distancia[destino] << endl;
}

int main() 
{

    int nodoInicio=0;  // I
    int nodoDestino=6; // T
    dijkstra(nodoInicio, nodoDestino);
    return 0;

}