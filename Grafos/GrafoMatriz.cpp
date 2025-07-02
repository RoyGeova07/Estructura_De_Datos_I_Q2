#include"GrafoMatriz.h"
#include<stdexcept>
using namespace std;

int main() {
    int numVertices;
    cout << "Ingrese la cantidad de vertices: ";
    cin >> numVertices;

    GrafoMatriz grafo(numVertices);

    // Agregar vertices
    for (int i = 0; i < numVertices; i++) {
        string nombre;
        cout << "Ingrese el nombre del vertice " << i + 1 << ": ";
        cin >> nombre;
        grafo.AgregarVertice(nombre);
    }

    int numAristas;
    cout << "Ingrese la cantidad de aristas: ";
    cin >> numAristas;

    // Agregar aristas
    for (int i = 0; i < numAristas; i++) {
        string origen, destino;
        int peso;
        cout << "Arista " << i + 1 << ":\n";
        cout << "  Desde: "; cin >> origen;
        cout << "  Hasta: "; cin >> destino;
        cout << "  Peso: "; cin >> peso;

       
    }

    grafo.MatrizAdyacencia();

    return 0;
}

