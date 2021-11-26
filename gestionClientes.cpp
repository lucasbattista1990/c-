/*Gestión de Clientes
Se desea desarrollar un programa para gestionar clientes.
 
De cada cliente se cuenta con la siguiente información: cuil, Razón Social, fecha de alta, dirección y localidad
 
Desarrollar un menú que permita: Alta de clientes, buscar por cuil o razón social y Salir del programa según 
el usuario lo desee.
 
Opción Alta: Validar que NO exista el CUIL para otro cliente
 
Opción Buscar: Mostrar por pantalla todos los datos del cliente. Si no lo encuentra indicar que el cliente no existe.
 
Opción Salir: consultar al usuario si está seguro de querer finalizar el programa.
Importante: 
Las búsquedas deberán realizar sobre índices utilizando el método binario.
El índice debe regenerarse ante cada alta de un nuevo cliente
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void alta();
int buscar();
bool validar(struct clientes);

struct clientes
{
    char cuil[10];
    char razonsocial[50];
    int dia;
    int mes;
    int anio;
    char direccion[30];
    int numero;
    char localidad[30];
};

struct indices
{
    int posicion;
    char cuil[10];
};

struct indices2
{
    int posicion;
    char razonsocial[50];
};

int cantidadAltas = 0;

int main()
{
    int opcion;
    cout << "*****************************************************************************" << endl;
    cout << "*****************************************************************************" << endl;
    cout << "--------------------------- BIENVENIDO AL SISTEMA ---------------------------" << endl;
    cout << "*****************************************************************************" << endl;
    cout << "*****************************************************************************" << endl
         << endl;
    cout << "Pulse la opcion deseada. . . " << endl
         << endl;
    cout << "1. Alta cliente\t2. Buscar por cuil\t3. Buscar por razon social\t0. Salir del programa" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        alta();
        break;
    case 2:
        buscar();
    case 3:
        buscar();
    default:
        break;
    }

    return 0;
}

void alta()
{
    struct clientes cliente;
    struct indices inx, aux;
    struct indices2 inx2, aux2;
    cout << "ingrese su cuil: " << endl;
    cin >> cliente.cuil;

    if (validar(cliente)==true)
    {
        cout << endl
             << "El codigo ingresado YA existe";
    }
    else
    {

        cout << "Ingrese razon social: " << endl;
        cin >> cliente.razonsocial;
        cout << "Ingrese su dia de nacimiento: " << endl;
        cin >> cliente.dia;
        cout << "Ingrese el mes: " << endl;
        cin >> cliente.mes;
        cout << "Ingrese el anio: " << endl;
        cin >> cliente.anio;
        cout << "Ingrese el nombre de su calle: " << endl;
        cin >> cliente.direccion;
        cout << "Ingrese la altura: " << endl;
        cin >> cliente.numero;
        cout << "Ingrese su localidad de recidencia: " << endl;
        cin >> cliente.localidad;

        ofstream Aclientes;
        Aclientes.open("Clientes.dat", ios::binary | ios::app | ios::ate);

        strcpy(inx.cuil, cliente.cuil);
        strcpy(inx2.razonsocial, cliente.razonsocial);

        Aclientes.write((char *)&cliente, sizeof(cliente));
        inx.posicion = Aclientes.tellp();
        inx.posicion = inx.posicion - sizeof(cliente);
        Aclientes.close();

        ofstream Iclientes;
        Iclientes.open("clientes.inx", ios::binary | ios::app | ios::ate);
        Iclientes.write((char *)&inx, sizeof(inx));
        Iclientes.close();

        ofstream Irazonsocial;
        Irazonsocial.open("razonsocial.inx", ios::binary | ios::app | ios::ate);
        Irazonsocial.write((char *)&inx2, sizeof(inx2));
        Irazonsocial.close();

        cantidadAltas++;

        if (cantidadAltas >= 10)
        {
            buscar();
        }
    }
}

bool validar(struct clientes cliente)
{

    struct indices inx;
    ifstream Iclientes;
    Iclientes.open("clientes.inx", ios::binary);

    while (Iclientes.read((char *)&inx, sizeof(inx)))
    {
        if (strcmp(inx.cuil, cliente.cuil) == 0)
        {
            Iclientes.close();
            return true;
        }
    }
    Iclientes.close();
    return false;
}

int buscar()
{
    struct clientes cliente;
    struct indices inx, aux;
    struct indices2 inx2, aux2;
    fstream Iclientes;
    Iclientes.open("clientes.inx", ios::in | ios::out | ios::binary | ios::app | ios::ate);
    fstream Irazonsocial;
    Irazonsocial.open("razonsocial.inx", ios::in | ios::out | ios::binary | ios::app | ios::ate);

    //******** BURBUJA  *******
    int i, j;
    int ielementos = Iclientes.tellg() / sizeof(indices);

    cout << endl
         << sizeof(indices) << " " << Iclientes.tellg() << " ** " << ielementos;

    for (i = 1; i < ielementos; i++)
    {
        for (j = 0; j < ielementos - i; j++)
        {

            cout << endl
                 << j * sizeof(indices);

            Iclientes.seekg(j * sizeof(indices));
            Iclientes.read((char *)&aux, sizeof(indices));
            Iclientes.read((char *)&inx, sizeof(indices));

            if (strcmp(aux.cuil, inx.cuil) == 1)
            {
                Iclientes.seekp(j * sizeof(indices));

                Iclientes.write((char *)&inx, sizeof(indices));
                Iclientes.write((char *)&aux, sizeof(indices));
            }
        }
        cout << endl
             << sizeof(indices2) << " " << Irazonsocial.tellg() << " ** " << ielementos;

        cout << endl
             << "Cuil:" << cliente.cuil;
        cout << endl
             << "Razon social: " << cliente.razonsocial << endl;
        cout << endl
             << "fecha de nacimiento: " << cliente.dia << "/" << cliente.mes << "/"<<cliente.anio<< endl; 
        cout << endl
             << "Direccion: " << cliente.direccion << " " << cliente.numero;
        cout << endl;

        for (i = 1; i < ielementos; i++)
        {
            for (j = 0; j < ielementos - i; j++)
            {

                cout << endl
                     << j * sizeof(indices2);

                Irazonsocial.seekg(j * sizeof(indices2));
                Irazonsocial.read((char *)&aux2, sizeof(indices2));
                Irazonsocial.read((char *)&inx2, sizeof(indices2));

                if (strcmp(aux2.razonsocial, inx2.razonsocial) == 1)
                {
                    Irazonsocial.seekp(j * sizeof(indices2));

                    Irazonsocial.write((char *)&inx2, sizeof(indices2));
                    Irazonsocial.write((char *)&aux2, sizeof(indices2));
                }
            }
        }
        Iclientes.close();
        Irazonsocial.close();
    }

    cantidadAltas = 0;
}
