#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

//Declaración de funciones de los Algoritmos de Ordenamiento
void ordenarBurbuja(float arreglo[],int tam);
void ordenarSeleccion(float arreglo[],int tam);

//Imprimir resultados
void imprimirNotasOriginales(float arreglo[],int tam);
void imprimirNotasOrdenadas(float arreglo[],int tam);


//--------------------------------------------------------
void ordenarBurbuja(float arreglo[],int tam) 
{
	float temporal;
  imprimirNotasOriginales(arreglo,tam);
	for (int i = 0;i < tam; i++){
		for (int j = 0; j< tam-1; j++){
			if (arreglo[j] > arreglo[j+1]){ 
			temporal = arreglo[j]; 
			arreglo[j] = arreglo[j+1]; 
			arreglo[j+1] = temporal;
			}
		}
	}
  imprimirNotasOrdenadas(arreglo,tam);
}
//-----------------------------------------------------------------
void ordenarSeleccion(float arreglo[],int tam)
{
  int minimo;
  imprimirNotasOriginales(arreglo,tam);
  for(int i = 0; i < tam; i++ )
  {
    minimo = i; 
    for( int j = i + 1; j < tam; j++)
    {
      if( arreglo[j] < arreglo[minimo])
      minimo = j; 
    }
    if(minimo!=i){
      int aux = arreglo[i];
      arreglo[i]=arreglo[minimo];
      arreglo[minimo]=aux;
    }
  }
  imprimirNotasOrdenadas(arreglo,tam);
}
//---------------------------------------------------------------
void imprimirNotasOriginales(float arreglo[],int tam)
{
  cout<<"\nNotas originales: ";
  for(int i = 0; i < tam; i++ ){
	cout<<"|"<<fixed<<setprecision(2)<<arreglo[i]<<"|";
  }
}
//----------------------------------------------------------------
void imprimirNotasOrdenadas(float arreglo[],int tam)
{
  cout<<"\nNotas ordenadas: ";
  for(int i = 0; i < tam; i++ ){
	cout<<"|"<<fixed<<setprecision(2)<<arreglo[i]<<"|";
  }
  cout<<endl;
}

//-----------------------------------------------------------------