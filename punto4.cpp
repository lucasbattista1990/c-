/* Realizamos la operación inversa al ejercicio 3.
Abrir el archivo de texto generado en ejercicio anterior y cargar 
uno a uno los valores del archivo en un array (considerar dimensionamiento dinámico).
Al finalizar la lectura desde el archivo, mostrar por pantalla la cantidad de elementos
 leídos y el listado de los mismos.*/

#include <iostream>
#include <fstream>


using namespace std;

int main()
{
    int *array;
    int variable;
    int posicion = 0;


    array = (int*) calloc(1,sizeof(int));

    ifstream archivo;
    archivo.open("archivo.bin", ios::in|ios::binary);

    if (!archivo.is_open())
    {
        cout << "archivo erroneo" << endl;
    }
    while (!archivo.eof())
    {
        archivo>>variable;
        array[posicion] = variable;
        posicion++;
        cout<<variable<<endl<<endl;
    }
  

    return 0;
}