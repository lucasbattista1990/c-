/*Registración de Repuestos por Rubro
Se desean registrar repuestos de distintos rubros: [A]utomotor, [M]otos, [N]autica, [V]arios en archivos de repuestos,
uno por cada rubro. De cada repuesto se cuenta con los siguientes datos: código [Alpha], descripción [50] y código_marca [10].
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
};

void altaRepuestos(char);

int main()
{

    char opcion, aux;

    cout << "Ingrese la opcion deseada.." << endl;
    cout << "[A] automotor" << endl;
    cout << "[M] motos" << endl;
    cout << "[N] nautica" << endl;
    cout << "[V] varios" << endl;
    cout << "[S] salir" << endl;

    cin >> opcion;
    while (toupper(opcion) == 'A' || toupper(opcion) == 'M' || toupper(opcion) == 'N' || toupper(opcion) == 'V')
    {

        switch (toupper(opcion))
        {
        case 'A':
            altaRepuestos(opcion);
            break;
        case 'M':
            altaRepuestos(opcion);
            break;
        case 'N':
            altaRepuestos(opcion);
            break;
        case 'V':
            altaRepuestos(opcion);
            break;
        case 'S':

            system("cls");
            break;
        default:
            system("cls");
        }
    }
}

void altaRepuestos(char opc)
{
    struct repuestos repuesto;
    ofstream archivo;

    if (toupper(opc) == 'A')
    {

        archivo.open("automotor.dat", ios::app | ios::ate | ios::binary);
    }
    else if (toupper(opc) == 'M')
    {

        archivo.open("motos.dat", ios::app | ios::ate | ios::binary);
    }
    else if (toupper(opc) == 'N')
    {

        archivo.open("nautica.dat", ios::app | ios::ate | ios::binary);
    }
    else if (toupper(opc) == 'V')
    {

        archivo.open("varios.dat", ios::app | ios::ate | ios::binary);
    }
    else if (toupper(opc) == 'S')
    {
        system("cls");
    }
    else
    {
        cout << "opcion invalida" << endl;
    }

    cout << "Ingrese el codigo: " << endl;
    cin >> repuesto.codigo;
    cout << "Ingrese la descripcion: " << endl;
    cin.ignore();
    cin.getline(repuesto.descripcion, 50);
    cout << "Ingrese la marca: " << endl;
    cin >> repuesto.marca;

    archivo.write((char *)&repuesto, sizeof(repuesto));
    archivo.close();
    cout << endl
         << "Carga exitosa " << endl
         << endl;


}
