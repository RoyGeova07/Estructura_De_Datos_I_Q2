#include<iostream>
using namespace std;

/*

operaciones que hace un arbol de busqueda

1. Insertar un nuevo nodo en el arbol
2. Mostrar el arbol completo
3. Buscar un nodo especifico en el arbol
4. Recorrer el arbol 
5. Eliminar un nodo del arbol

*/


struct Nodo
{
    
    int dato;
    Nodo*izquierda;
    Nodo*derecho;
    Nodo*Padre;

};

Nodo*CrearNodo(int n,Nodo*padre)
{

    Nodo*nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;
    nuevo_nodo->izquierda=nullptr;
    nuevo_nodo->derecho=nullptr;
    nuevo_nodo->Padre=padre;

    return nuevo_nodo;

}

void InsertarNodo(Nodo*&arbol,int n,Nodo *padre)
{

    if(arbol==nullptr)
    {

        Nodo*nuevo_nodo=CrearNodo(n,padre);
        arbol=nuevo_nodo;//arbol apunta al nuevo nodo creado, osea la raiz

    }else{

        int ValorRaiz=arbol->dato;

        if(n<ValorRaiz)
        {

            InsertarNodo(arbol->izquierda,n,arbol);//si el elemento es menor q al nodo previo entonces se insertara al lado izquierdo

        }else{

            InsertarNodo(arbol->derecho,n,arbol);//si el elmento es mayor que al nodo previo entonces se insertara a lado derecho

        }

    }

}

//borrar el nodo que tiene hijos zig zag, mira a laderecha y de un solo a la izquierda
Nodo*minimo(Nodo*arbol)//funcion para determinar el nodo mas izquierdo posible
{

    if(arbol==nullptr)//si el arbol esta vacio
    {

        return nullptr;//retornas nul

    }else if(arbol->izquierda){//si tiene hijo izquierdo

        return minimo(arbol->izquierda);//entonces se llama a la funcion recursivamente para buscar el nodo mas izquierdo

    }else{

        return arbol;//si no tiene hijo izquierdo, entonces retorna el mismo nodo

    }

}

//funcion para reemeplazar 2 nodos 
void reemplazar(Nodo*arbol,Nodo*nuevoNodo)
{

    if(arbol->Padre)
    {
        //arbol->padre hay que asignarle el nuevo nodo
        if(arbol->dato==arbol->Padre->izquierda->dato)
        {

            arbol->Padre->izquierda=nuevoNodo;

        }else if(arbol->dato==arbol->Padre->derecho->dato){

            arbol->Padre->derecho=nuevoNodo;    

        }


    }
    if(nuevoNodo)
    {

        nuevoNodo->Padre=arbol->Padre;//asignamos a su nuevo padre

    }

}

//funcion para destruir nodo 
void DestruirNodo(Nodo*nodo)
{

    //si el nodo que reemplazamos tiene hijos pues
    nodo->izquierda=nullptr;//se olvida del hijo izquierdo
    nodo->derecho=nullptr;//del hijo derecho
    delete nodo;//y se muere XD

}


void MostrarArbol(Nodo*arbol,int contador)
{

    //si el arbol esta vacio por completo, retonamos 
    if(arbol==nullptr)
    {

        return;

    }else{

        MostrarArbol(arbol->derecho,contador+1);

        for(int i=0;i<contador;i++)
        {

            cout<<"   ";

        }
        cout<<arbol->dato<<endl;

        //y despues imprimir todo el lado derecho, imprimimos el lado izquierdo
        MostrarArbol(arbol->izquierda,contador+1);

    }

}

//funcion para eliminar el nodo encontrado
void EliminarNodo(Nodo*nodoEliminar)
{

    //aqui verificamos si el nodo a eliminar tiene hijos o no
    if(nodoEliminar->izquierda&&nodoEliminar->derecho)
    {

        Nodo*menor=minimo(nodoEliminar->derecho);//pasamos el nodo derecho para buscar el minimo de ese subArbol
        nodoEliminar->dato=menor->dato;//el valor del nodo a eliminar se reemplaza por el valor del nodo minimo encontrado
//    el q quiero eliminar = el numero que lo reemplaza
        EliminarNodo(menor);//ahora eliminamos el nodo minimo encontrado, 

    }else if(nodoEliminar->izquierda){//si tiene hijo izquierdo

        reemplazar(nodoEliminar,nodoEliminar->izquierda);
        DestruirNodo(nodoEliminar);

    }else if(nodoEliminar->derecho){//si tiene hijo derecho

        reemplazar(nodoEliminar,nodoEliminar->derecho);
        DestruirNodo(nodoEliminar);

    }else{//donde un nodo no tiene hijos, es decir, una hoja

        reemplazar(nodoEliminar,nullptr);
        DestruirNodo(nodoEliminar);

    }

}


bool BuscarElementoArbol(Nodo*arbol,int n)
{

    //primero se verifica si el arbol esta vacio
    if(arbol==nullptr)
    {

        cout<<"\nNo hay elementos en el arbol\n";
        return false;

    }else if(arbol->dato==n){//segundo caso si el elemento es el primero

        return true;

    }else if(n<arbol->dato){//si el elemento es el primer nodo de la izquierda

        return BuscarElementoArbol(arbol->izquierda,n);

    }else{

        return BuscarElementoArbol(arbol->derecho,n);//si el elemento es el primer nodo de la derecha

    }

}

//ahora la funcion de recorrer el arbol en preorden
void PreOrden(Nodo*nodo)
{

    if(nodo!=nullptr)
    {

        cout<<nodo->dato<<" - ";
        PreOrden(nodo->izquierda);//primero recorre el lado izquierdo
        PreOrden(nodo->derecho);

    }

}

void InOrden(Nodo*nodo)
{

    if(nodo!=nullptr)
    {

        InOrden(nodo->izquierda);//primero recorre el nodo de la izquierda
        cout<<nodo->dato<<" - ";//despues el nodo actual
        InOrden(nodo->derecho);//y por ultimo el nodo de la derecha

    }

}

void PostOrden(Nodo*nodo)
{

    if(nodo!=nullptr)
    {

        PostOrden(nodo->izquierda);//primero recorre el noodo de la izquierda
        PostOrden(nodo->derecho);//despues el nodo de la derecha
        cout<<nodo->dato<<" - ";//y por ultimo el nodo actual

    }

}

//para poder eliminar un nodo del arbol, es muy bueno que el nodo sepa exactamente quien es su padre
void Eliminar(Nodo*arbol,int n)
{

    if(arbol==nullptr)
    {

        cout<<"\nEl arbol esta vacio, no se puede eliminar el nodo\n";
        return;

    }else if(n<arbol->dato){//si el valor es menor 

        Eliminar(arbol->izquierda,n);//busca por la izquierda

    }else if(n>arbol->dato){// si el valor es mayor

        Eliminar(arbol->derecho,n);//busca por la derecha

    }else{//si ya encontraste el valor

        EliminarNodo(arbol);

    }

}


int main()
{

    Nodo*Arbol=nullptr;
    int opcion,dato;

    do
    {
        
        cout<<"\n=====MENU====\n";
        cout<<"1. Insertar un nuevo nodo\n";
        cout<<"2. Mostrar Arbol\n";
        cout<<"3. Buscar elemento dentro del arbol\n";
        cout<<"4. Recorrer el arbol en preorden\n";
        cout<<"5. Recorrer el arbol en inorden\n";
        cout<<"6. Recorrer el arbol en postOrden\n";
        cout<<"7. Eliminar un nodo del arbol\n";
        cout<<"8. Salir\n";
        cout<<"Elija una opcion: ";
        cin>>opcion;

        if (opcion==1)
        {
            
            cout<<"\nDigite un numero: ";
            cin>>dato;
            InsertarNodo(Arbol,dato,nullptr);

        }else if (opcion==2){
            
            MostrarArbol(Arbol,0);
            cout<<"\n";

        }else if(opcion==3){
            
            cout<<"Ingrese el elemento a buscar dentro del arbol: ";
            cin>>dato;
            if(BuscarElementoArbol(Arbol,dato)==true)
            {

                cout<<"\nEl elemento "<<dato<<" SI EXISTE en el arbol\n";

            }else{

                cout<<"\nEl elemento "<<dato<<" NO EXISTE en el arbol\n";

            }

        }else if(opcion==4){

            cout<<"\n===RECORRIDO EN PREORDEN===\n";
            PreOrden(Arbol);
            cout<<"\n";

        }else if(opcion==5){

            cout<<"\n===RECORRIDO EN InORDEN===\n";
            InOrden(Arbol);
            cout<<"\n";

        }else if(opcion==6){

            cout<<"\n===RECORRIDO EN POSTORDEN===\n";
            PostOrden(Arbol);
            cout<<"\n";

        }else if(opcion==7){

            cout<<"Ingrese el elemento a eliminar del arbol: ";
            cin>>dato;
            Eliminar(Arbol,dato);
            cout<<"\n";
            
        }else if(opcion==8){

            cout<<"\nTermino\n";
            break;

        }
        

    } while (opcion!=8);
    

    return 0;
}