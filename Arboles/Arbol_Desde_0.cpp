#include <iostream>
#include <queue>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
    
    Nodo(int valor) : dato(valor), izq(nullptr), der(nullptr) {}
};

class ArbolBinario {
private:
    Nodo* raiz;
    
    void imprimirEspacios(int n) {
        for(int i = 0; i < n; i++) {
            cout << " ";
        }
    }
    
    void imprimirConexiones(int espacios, bool hayIzq, bool hayDer) {
        if(hayIzq && hayDer) {
            imprimirEspacios(espacios - 1);
            cout << "/";
            imprimirEspacios(5);
            cout << "\\" << endl;
        } else if(hayIzq) {
            imprimirEspacios(espacios - 1);
            cout << "/" << endl;
        } else if(hayDer) {
            imprimirEspacios(espacios + 5);
            cout << "\\" << endl;
        }
    }
    
public:
    ArbolBinario() : raiz(nullptr) {}
    
    void insertar(int valor) {
        if(raiz == nullptr) {
            raiz = new Nodo(valor);
            return;
        }
        
        queue<Nodo*> q;
        q.push(raiz);
        
        while(!q.empty()) {
            Nodo* actual = q.front();
            q.pop();
            
            if(actual->izq == nullptr) {
                actual->izq = new Nodo(valor);
                return;
            } else if(actual->der == nullptr) {
                actual->der = new Nodo(valor);
                return;
            } else {
                q.push(actual->izq);
                q.push(actual->der);
            }
        }
    }
    
    void imprimir() {
        if(raiz == nullptr) {
            cout << "Arbol vacio" << endl;
            return;
        }
        
        queue<Nodo*> q;
        q.push(raiz);
        
        while(!q.empty()) {
            int tamanoNivel = q.size();
            
            // Calcular espacios para centrar
            int espacios = 6;
            
            for(int i = 0; i < tamanoNivel; i++) {
                Nodo* actual = q.front();
                q.pop();
                
                if(i == 0) {
                    imprimirEspacios(espacios);
                }
                
                if(actual != nullptr) {
                    cout << actual->dato;
                    q.push(actual->izq);
                    q.push(actual->der);
                } else {
                    cout << " ";
                    q.push(nullptr);
                    q.push(nullptr);
                }
                
                if(i < tamanoNivel - 1) {
                    imprimirEspacios(10);
                }
            }
            cout << endl;
            
            // Imprimir conexiones solo si hay siguiente nivel
            bool hayProximoNivel = false;
            queue<Nodo*> temp = q;
            while(!temp.empty() && !hayProximoNivel) {
                if(temp.front() != nullptr) {
                    hayProximoNivel = true;
                }
                temp.pop();
            }
            
            if(hayProximoNivel) {
                
                for(int i = 0; i < tamanoNivel; i++) {
                    if(i == 0) {
                        imprimirEspacios(espacios);
                    }
                    
                    // Verificar si hay hijos
                    int pos = i * 2;
                    bool hayIzq = false, hayDer = false;
                    
                    if(pos < q.size()) {
                        queue<Nodo*> tempQ = q;
                        for(int j = 0; j < pos && !tempQ.empty(); j++) {
                            tempQ.pop();
                        }
                        if(!tempQ.empty() && tempQ.front() != nullptr) {
                            hayIzq = true;
                        }
                    }
                    
                    if(pos + 1 < q.size()) {
                        queue<Nodo*> tempQ = q;
                        for(int j = 0; j < pos + 1 && !tempQ.empty(); j++) {
                            tempQ.pop();
                        }
                        if(!tempQ.empty() && tempQ.front() != nullptr) {
                            hayDer = true;
                        }
                    }
                    
                    if(hayIzq) cout << "/";
                    else cout << " ";
                    
                    imprimirEspacios(4);
                    
                    if(hayDer) cout << "\\";
                    else cout << " ";
                    
                    if(i < tamanoNivel - 1) {
                        imprimirEspacios(4);
                    }
                }
                cout << endl;
            }
            
            espacios -= 3;
            if(espacios < 0) espacios = 0;
        }
    }
    
    // Versión simplificada para árboles pequeños
void imprimirSimple() {
        if(raiz == nullptr) {
            cout << "Arbol vacio" << endl;
            return;
        }
        
        // Imprimir raíz
        cout << "    " << raiz->dato << endl;
        
        // Imprimir conexiones
        bool hayIzq = (raiz->izq != nullptr);
        bool hayDer = (raiz->der != nullptr);
        
        if(hayIzq || hayDer) {
            cout << "  ";
            if(hayIzq) cout << "/";
            else cout << " ";
            cout << "     ";
            if(hayDer) cout << "\\";
            else cout << " ";
            cout << endl;
            
            // Imprimir hijos
            cout << "";
            if(hayIzq) cout << raiz->izq->dato;
            else cout << " ";
            cout << "      ";
            if(hayDer) cout << raiz->der->dato;
            else cout << " ";
            cout << endl;
        }
    }
};

int main() {
    ArbolBinario arbol;
    
    // Ejemplo como el que mostraste
    arbol.insertar(67);
    arbol.insertar(4);
    arbol.insertar(78);
    arbol.insertar(56);
    arbol.insertar(23);

    
    cout << "Arbol (version simple):" << endl;
    arbol.imprimirSimple();
    
    cout << "\n\nArbol con mas nodos:" << endl;
    arbol.insertar(25);
    arbol.insertar(90);
    arbol.insertar(2);
    arbol.insertar(45);
    arbol.insertar(23);
    arbol.insertar(78);
    
    arbol.imprimirSimple();
    
    return 0;
}