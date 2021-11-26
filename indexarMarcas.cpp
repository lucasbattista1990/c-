/*Indexar Marcas
Desarrollar el proceso que tome el archivo de Marcas y genere su respectivo índice.*/


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Marca
{
    char codigo[10];            // MI CLAVE
    char descripcion[20];
};

struct Indice
{
    char clave[10];
    int posicion;
};

int main()
{

    //ABRIR MAESTRO

    struct Marca marcas;

    ifstream archivoM;
    archivoM.open("Marcas.dat", ios::binary);

    struct Indice indices;

    ofstream archivoI;
    archivoI.open("Marcas.inx", ios::ate | ios::app | ios::binary);

    while (!archivoM.read((char*)  &marcas,sizeof(marcas)).eof())
    {

        indices.posicion = archivoM.tellg() ;
        indices.posicion -=  sizeof(marcas);
        strcpy(indices.clave  ,  marcas.codigo);

        archivoI.write((char*) &indices, sizeof(indices)  );

    }

    archivoI.close();
    archivoM.close();




}