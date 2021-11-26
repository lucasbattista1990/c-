/*Indexar Repuestos (B)
Desarrollar el proceso que tome los archivos de repuestos y genere su índice. Considerar un UNICO archivo de índices.*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct repuestos
{
    char codigo[10];
    char descripcion[50];
    char marca[10];
};

struct indice
{
    char clave[10];
    int posicion;
};

int main()
{
    struct repuestos repuesto;
    struct indice indices;

    ifstream archivo1;
    archivo1.open("automotor.dat", ios::binary);
    ifstream archivo2;
    archivo2.open("motos.dat", ios::binary);
    ifstream archivo3;
    archivo3.open("nautica.dat", ios::binary);
    ifstream archivo4;
    archivo4.open("varios.dat", ios::binary);

    ofstream archivoI;
    archivoI.open("repuestosindicecompleto.inx", ios::binary);

    while (!archivo1.read((char *)&repuesto, sizeof(repuesto)).eof())
    {
        indices.posicion = archivo1.tellg();
        indices.posicion -= sizeof(repuesto);
        strcpy(indices.clave, repuesto.codigo);
        archivoI.write((char *)&indices, sizeof(indices));
    }
    while (!archivo2.read((char *)&repuesto, sizeof(repuesto)).eof())
    {
        indices.posicion = archivo2.tellg();
        indices.posicion -= sizeof(repuesto);
        strcpy(indices.clave, repuesto.codigo);
        archivoI.write((char *)&indices, sizeof(indices));
    }
    while (!archivo3.read((char *)&repuesto, sizeof(repuesto)).eof())
    {
        indices.posicion = archivo3.tellg();
        indices.posicion -= sizeof(repuesto);
        strcpy(indices.clave, repuesto.codigo);
        archivoI.write((char *)&indices, sizeof(indices));
    }
    while (!archivo4.read((char *)&repuesto, sizeof(repuesto)).eof())
    {

        indices.posicion = archivo4.tellg();
        indices.posicion -= sizeof(repuesto);
        strcpy(indices.clave, repuesto.codigo);
        archivoI.write((char *)&indices, sizeof(indices));
    }

    archivoI.close();
    archivo1.close();
    archivo2.close();
    archivo3.close();
    archivo4.close();
}
