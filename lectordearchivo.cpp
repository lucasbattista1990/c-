
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct EMPLEADOS
{
    char legajo1[10]; 
    int codigoinsumo;
    char nombreinsumo[30];
    int entregado;
}empleado;

struct INDICE{
    char legajo[10];
    int posicion;
}indice;

int main(){

    ifstream archivo;
    archivo.open("entregas.dat", ios::binary);
    ifstream indice1;
    indice1.open("indice.inx", ios::binary);
    cout << "Archivo datos! " << endl;
    while ( archivo.read((char*)&empleado, sizeof(empleado)) ){
        cout << "Legajo: " << empleado.legajo1 << endl;
        cout << "Codigo Insumo: " << empleado.codigoinsumo << endl;
        cout << "Nombre Insumo: " << empleado.nombreinsumo << endl;
        cout << "Entregado: " << empleado.entregado << endl;
        cout << endl;
    }
    
    cout << "Archivo indice! " << endl;
    while (indice1.read((char*)&indice, sizeof(indice)) ){
        cout << "legajo: " << indice.legajo << endl;
        cout << "posicion: " << indice.posicion << endl;
        cout << endl;
    }
    archivo.close();
    indice1.close();
}
    

