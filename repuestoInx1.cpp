/*Indexar Repuestos (A)
Desarrollar el proceso que tome los archivos de repuestos y genere su índice. Considerar un archivo de índice por rubro.
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct repuestos
{
    char codigo[10];
    char descripcion[50];
    char marca[10];
}repuesto;

struct indice
{
    char clave[10];
    int posicion;
}indices;
void pepe(string);


int main()
{
   pepe("automotor");
   pepe("motos");
   pepe("nautica");
   pepe("varios");    
}

void pepe(string arc)
{

    ifstream archivo1;
    archivo1.open(arc+".dat", ios::binary);
    ofstream archivo2;
    archivo2.open(arc + ".inx", ios::binary);

    while (!archivo1.read((char *)&repuesto, sizeof(repuesto)).eof())
    {

        indices.posicion = archivo1.tellg();
        indices.posicion -= sizeof(repuesto);
        strcpy(indices.clave, repuesto.codigo);

        archivo2.write((char *)&indices, sizeof(indices));
    }

    archivo2.close();
    archivo1.close();
}
