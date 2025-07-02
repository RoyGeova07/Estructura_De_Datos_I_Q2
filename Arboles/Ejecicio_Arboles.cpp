#include<iostream>
using namespace std;

struct Nodo
{

    char dato;
    Nodo*izquierda;
    Nodo*derecha;
    int frecuencia;//para contar repeticionessss

};

Nodo*CrearNodo(char c)
{

    Nodo*nuevo_nodo=new Nodo();
    nuevo_nodo->dato=c;
    nuevo_nodo->izquierda=nullptr;
    nuevo_nodo->derecha=nullptr;
    nuevo_nodo->frecuencia=1;

    return nuevo_nodo;

}

void InsertarNodo(Nodo*&arbol,char c)
{

    if(arbol==nullptr)
    {

        arbol=CrearNodo(c);

    }else if(c==arbol->dato){

        arbol->frecuencia++;

    }else if(c<arbol->dato){

        InsertarNodo(arbol->izquierda,c);

    }else{

        InsertarNodo(arbol->derecha,c);

    }

}

void InOrde(Nodo*arbol)
{

    if(arbol!=nullptr)
    {

        InOrde(arbol->izquierda);
        cout<<"'"<<arbol->dato<<"' aparece "<<arbol->frecuencia<<" veces\n";
        InOrde(arbol->derecha);

    }

}

void ContarCaracteres(Nodo*arbol,int&total)
{

    if(arbol)
    {
        ContarCaracteres(arbol->izquierda,total);
        total+=arbol->frecuencia;
        ContarCaracteres(arbol->derecha,total);

    }

}

void BuscarMasRepetido(Nodo*arbol,char&masRep,int&maxFrecuencia)
{

    if(arbol)
    {

        BuscarMasRepetido(arbol->izquierda,masRep,maxFrecuencia);
        if(arbol->frecuencia>maxFrecuencia)
        {

            maxFrecuencia=arbol->frecuencia;
            masRep=arbol->dato;

        }
        BuscarMasRepetido(arbol->derecha,masRep,maxFrecuencia);

    }

}


void MostrarArbol(Nodo*arbol,int contador)
{

    //si el arbol esta vacio por completo, retonamos 
    if(arbol==nullptr)
    {

        return;

    }else{

        MostrarArbol(arbol->derecha,contador+1);

        for(int i=0;i<contador;i++)
        {

            cout<<"   ";

        }
        cout<<arbol->dato<<endl;

        //y despues imprimir todo el lado derecho, imprimimos el lado izquierdo
        MostrarArbol(arbol->izquierda,contador+1);

    }

}


Nodo* Minimo(Nodo* nodo) {
    while (nodo->izquierda != nullptr)
        nodo = nodo->izquierda;
    return nodo;
}

Nodo* EliminarNodo(Nodo* raiz, char c) {
    if (raiz == nullptr) return nullptr;

    if (c < raiz->dato) {
        raiz->izquierda = EliminarNodo(raiz->izquierda, c);
    } else if (c > raiz->dato) {
        raiz->derecha = EliminarNodo(raiz->derecha, c);
    } else {
        // Si hay frecuencia mayor que 1, solo restamos
        if (raiz->frecuencia > 1) {
            raiz->frecuencia--;
            return raiz;
        }

        // Si es hoja o tiene un solo hijo
        if (raiz->izquierda == nullptr) {
            Nodo* temp = raiz->derecha;
            delete raiz;
            return temp;
        } else if (raiz->derecha == nullptr) {
            Nodo* temp = raiz->izquierda;
            delete raiz;
            return temp;
        }

        // Dos hijos
        Nodo* temp = Minimo(raiz->derecha);
        raiz->dato = temp->dato;
        raiz->frecuencia = temp->frecuencia;
        temp->frecuencia = 1; // Evitar doble decremento
        raiz->derecha = EliminarNodo(raiz->derecha, temp->dato);
    }
    return raiz;
}



int main() {
    Nodo* arbol = nullptr;
    int opcion;
    char letra;

    do {
        cout << "\n==== MENU ====\n";
        cout << "1. Insertar caracteres\n";
        cout << "2. Mostrar arbol\n";
        cout << "3. Mostrar conteo por caracter\n";
        cout << "4. Mostrar total y más repetido\n";
        cout << "5. Eliminar caracter\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese una cadena: ";
                cin>>letra;
                InsertarNodo(arbol,letra);
                break;

            case 2:
                cout << "\nArbol actual:\n";
                MostrarArbol(arbol,0);
                break;

            case 3:
                cout << "\n=== Cantidad por caracter ===\n";
                InOrde(arbol);
                break;

            case 4: {
                int total = 0;
                char masRepetido = '\0';
                int maxFrecuencia = 0;
                ContarCaracteres(arbol, total);
                BuscarMasRepetido(arbol, masRepetido, maxFrecuencia);
                cout << "Total: " << total << ", mas repetido: '" << masRepetido << "' con " << maxFrecuencia << " repeticiones\n";
                break;
            }

            case 5:
                cout << "Ingrese el caracter a eliminar: ";
                cin >> letra;
                arbol = EliminarNodo(arbol, letra);
                break;

            case 6:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while (opcion != 6);

    return 0;
}