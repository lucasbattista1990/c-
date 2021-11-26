/*Ejercicio 2) Estación de servicios
Una estación de servicios desea actualizar sus sistemas, almacenando las ventas en archivos.
Hasta el momento la estación cuenta con:
7 surtidores (del 1 al 7) 
4 tipos de combustibles (Nafta Premium [Np], Nafta común [Nc], GasOil Premium [Gp], GasOil común [Gc]) 
5 playeros (del 1 al 5).
El programa deberá consultar si desea iniciar una venta (V) o Finalizar (F), cualquier otra opción deberá informar: Opción incorrecta,
ingrese Venta (V) o Finalización (F).
Por cada venta deberá solicitar: Nro de playero, Nro de Surtidor, Tipo de 
combustible y cantidad (litros) vendidos, almacenando temporalmente en una estructura {Venta} los datos de la misma 
antes de ser volcados al archivo.
De ingresarse un playero o el tipo de combustible inválidos deberá informar al operador y solicitar valores correctos.
La venta en Litros No podrá ser 0 (cero).
Para guardar los datos en el archivo, deberá utilizarse la función Guardar() 
que reciba como parámetro la Venta{} realizada.
condiciones:
Archivo tipo binario, nombre: estacion.dat
Grabar archivo por Write()
Si contiene información previa, la misma deberá conservarse.
Las validaciones de Surtidor, Playero, tipo de Combustible y Litros deberá realizar utilizan 
funciones INDEPENDIENTES que reciban la {Venta} como parámetro. */
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct VENTA
{
    int surtidor;
    int playero;
    int cant_litros;
    char combustible[3];
};
int validacion1(VENTA);
int validacion2(VENTA);
int validacion3(VENTA);
int guardar(VENTA);

int main()
{
    struct VENTA venta;

    char opcion;

    ofstream archivo;
    archivo.open("estacion.dat", ios::app | ios::binary);
    if (!archivo.is_open())
    {
        cout << "Archivo erroneo" << endl;
    }

    cout << "******************************************************" << endl;
    cout << "   BIENVENIDO AL SISTEMA, ESTACION DE SERVICIOS YPF   " << endl;
    cout << "******************************************************" << endl
         << endl;
    cout << "Pulse la opcion deseada. . . " << endl
         << endl;
    cout << "Iniciar venta (V)\tFinalizar (F)" << endl;
    cin >> opcion;

    if (toupper(opcion) == 'F')
    {
        cout << "El programa finalizo correctamente. . . " << endl;
    }

    while (toupper(opcion) != 'V' && toupper(opcion) != 'F')
    {
        cout << "Opcion incorrecta! " << endl
             << endl;
        cout << "Iniciar venta (V)\tFinalizar (F)" << endl;
        cin >> opcion;
    }

    while (!archivo.eof())
    {
        switch (opcion)
        {
        case 'v':
            cout << "Ingrese el Nro de Playero: " << endl
                 << endl;
            cin >> venta.playero;
            if (venta.playero < 1 || venta.playero > 5)
            {
                validacion1(venta);
            }
            cout << "Ingrese el Nro de Surtidor: " << endl
                 << endl;
            cin >> venta.surtidor;
            if (venta.surtidor < 1 || venta.surtidor > 7)
            {
                validacion2(venta);
            }
            cout << "Ingrese el Tipo de Combustible: " << endl;
            cout << "(np) para nafta premium:\t(nc) para nafta comun:\t(gp) para gasoil premium\t(gc) para gasoil comun: " << endl;
            cin >> venta.combustible;
            if (strcmp(venta.combustible, "np") != 0 && strcmp(venta.combustible, "nc") != 0 && strcmp(venta.combustible, "gp") != 0 && strcmp(venta.combustible, "gc") != 0)
            {
                validacion3(venta);
            }
            cout << "Ingrese cuantos litros cargo: " << endl;
            cin >> venta.cant_litros;
            if (venta.cant_litros == 0)
            {
                cout << "Imposible realizar el registro. . ." << endl;
                cout << "vuelva a ingresar la cantidad de litros" << endl;
                cin >> venta.cant_litros;
            }
            cout << "Iniciar venta (V)\tFinalizar (F)" << endl;
            cin >> opcion;
            if (toupper(opcion) == 'F')
            {
                cout << "El programa finalizo correctamente. . . " << endl;
            }
            guardar(venta);
        }
    }
    opcion = 0;
    archivo.close();
    return 0;
}

int validacion1(struct VENTA venta)
{

    if (venta.playero > 1 && venta.playero < 5)
    {
        cout << "Ingrese el numero de playero: " << endl;
        cin >> venta.playero;
    }
    else
    {
        cout << "solicite un valor valido. . . " << endl
             << endl;
        cout << "Ingrese el numero de playero: " << endl;
        cin >> venta.playero;
    }
}

int validacion2(struct VENTA venta)
{
    if (venta.surtidor > 1 && venta.surtidor < 7)
    {
        cout << "Ingrese el numero de surtidor: " << endl;
        cin >> venta.surtidor;
    }
    else
    {
        cout << "solicite un valor valido. . . " << endl
             << endl;
        cout << "Ingrese el numero de surtidor: " << endl;
        cin >> venta.surtidor;
    }
}

int validacion3(struct VENTA venta)
{
    if (strcmp(venta.combustible, "np") != 0 && strcmp(venta.combustible, "nc") != 0 && strcmp(venta.combustible, "gp") != 0 && strcmp(venta.combustible, "gc") != 0)
    {
        cout << "solicite un valor valido. . . " << endl
             << endl;
        cout << "Ingrese el tipo de combustible: " << endl;
        
        cin >> venta.combustible;
        cin.getline(venta.combustible, 3, '\n');
  
    }
    else
    {
        cout << "Ingrese el tipo de combustible: " << endl;
        cout << "(np) para nafta premium:\t(nc) para nafta comun:\t(gp) para gasoil premium\t(gc) para gasoil comun: " << endl;
        cin >> venta.combustible;
        cin.getline(venta.combustible, 3, '\n');
    }
}

int guardar(struct VENTA venta)
{
    ofstream archivo;
    archivo.open("estacion.dat", ios::app | ios::binary);
    if (!archivo.is_open())
    {
        cout << "Archivo erroneo" << endl;
    }
    archivo.write((char *)&venta, sizeof(venta));
}