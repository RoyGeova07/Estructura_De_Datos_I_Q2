#include<iostream>
using namespace std;

//Metodo Burbuja
//Es un sencillo algoritmo de ordenamiento. Funciona revisando cada elemento de la lista que va ser
//ordenada con el siguiente intercambiandolos de posicion si estan en el orden equivocado. Es necesario
//revisar varias veces toda la lista hasta que no se necesiten mas intercamiarlos, lo cual significa 
//que la lista esta ordenada

//hhace que los numeros mas livianos, suban hasta arriba como una busbuja en una gaseosa 

int main(){

    

    int nu[30];
    int cantidad;

    cout<<"Cantidad que va a ingresar en el arreglo: \n";
    cin>>cantidad;
    for (int i = 0; i < cantidad; i++)
    {
        
        cout<<"["<<i<<"]"<<" Ingrese un elemento: \n";
        cin>>nu[i];

    }
    

    int aux;

    for (int i = 0; i < cantidad; i++)
    {
        
        for (int j = 0; j < cantidad; j++)
        {
                        //siguiente
            if(nu[j]>nu[j+1])
            {

                //aqui intercambio con aux
                aux=nu[j];
                nu[j]=nu[j+1];
                nu[j+1]=aux; 

            }

        }
        

    }

    cout<<"Muestra Ascendente\n";
    for (int i = 0; i < cantidad; i++)
    {
        
        cout<<nu[i]<<" ";

    }
    
    

    return 0;
}