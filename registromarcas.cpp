/*Registración de Marcas
Se desean registrar las Marcas de repuestos para todos los rubros.
Por cada marca se cuenta con los siguientes datos: código_marca [10] y descripción [20].
*/

#include <iostream>
#include <fstream>
using namespace std;

struct Marca
{
    char codigo[10];
    char descripcion[20];
};

int main()
{

    struct Marca marcas;

    cout <<endl << "ingreso rubro:" ;
    cin >> marcas.codigo;
    cout <<endl << "ingreso descripcion:" ;
    cin >> marcas.descripcion;

    ofstream archivo;
    archivo.open("Marcas.dat", ios::app | ios::ate | ios::binary);

    archivo.write((char*) &marcas, sizeof(marcas));
    archivo.close();

}