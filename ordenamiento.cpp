/*Ordenamiento
Desarrollar el proceso de ordenamiento de índices (A) y (B)
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

struct repuesto
{
    char codigo[10];
    char descripcion[50];
    char marca[10];
} repuestos;

struct indice
{
    char clave[10];
    int posicion;
} indices;

void ordenar(string);

int main()
{
    ordenar("motos");
    ordenar("autos");
    ordenar("nautica");
    ordenar("varios");
    ordenar("repuestosindicecompleto");
}

void ordenar(string archivo)
{
    indice indices;
    indice indice_aux;
    fstream inx;

    inx.open(archivo+".inx", ios::in | ios::out | ios::binary);


    int i, j;                                      // Variables contadoras del ciclo.
    inx.seekg(0, ios::end);                        // me posiciono en el final del archivo
    int ielementos = inx.tellg() / sizeof(indice); // ielementos contiene la cantidad de elementos del indice
    for (i = 1; i < ielementos; i++)               // primer bucle burbuja
    {
        for (j = 0; j < ielementos - i; j++) // segundo bucle piedra
        {
            inx.seekg(j * sizeof(indice));                 // se posiciona el elemento nro j
            inx.read((char *)&indice_aux, sizeof(indices)); // guarda el elemento nro j en struct auxiliar
            inx.read((char *)&indices, sizeof(indices));     // lee el elemento nro j+1 y guarda en struct indice

            if (strcmp(indice_aux.clave , indices.clave) <0 ) // Compara claves, si el segundo elemento es menor, invierte posiciones
            {
                inx.seekp(j * sizeof(indices)); // se posiciona el elemento nro j
                inx.write((char *)&indices, sizeof(indices));
                inx.write((char *)&indice_aux, sizeof(indices));
            }
        }
    }
    inx.close();
}