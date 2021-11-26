/*
Ejercicio 2.1) Estación de servicios
Desarrollar el programa que permite buscar las ventas
por Playero, por surtidor o por tipo de combustible y
muestre por pantalla la cantidad de ventas y el total de
litros.
Condiciones:

 Utilizar el archivo binario: estacion.dat
 Leer archivo por Read()

*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct VENTA
{
    int playero;
    int surtidor;
    char combustible[3];
    int cantidad_litros;
};

int main()
{
    struct VENTA venta;
    int contador = 0;
    int contador_litros = 0;
    int opcion = 0;
    int opcion_aux = 0;
    char tipo_combustible[3];

    ifstream archivo;

    while (opcion != 0)
    {
        archivo.open("estacion.dat", ios::binary);
        if (archivo.is_open())
        {
            cout << "******************************************************" << endl;
            cout << "   BIENVENIDO AL SISTEMA, ESTACION DE SERVICIOS YPF   " << endl;
            cout << "******************************************************" << endl
                 << endl;
            cout << "Pulse la opcion que desea visualizar. . . " << endl
                 << endl;
            cout << "Ventas por playero(1)\t ventas por surtidor(2)\t\nVentas por tipo de combustible(3)\t salir(0)" << endl;
            cin >> opcion;
            contador_litros = 0;
            contador = 0;

            switch (opcion)
            {
            case 1:
                cout << "Ingrese el Nro del playero " << endl;
                cin >> opcion_aux;

                if (opcion_aux < 1 || opcion_aux > 5)
                {
                    cout << "Numero de playero incorrecto" << endl;
                    cout << "Ingrese un numero del 1 al 5" << endl;
                    cin >> opcion_aux;
                }

                while (archivo.read((char *)&venta, sizeof(VENTA)))
                {
                    if (opcion_aux == venta.playero)
                    {
                        contador_litros += venta.cantidad_litros;
                        contador++;
                    }
                    cout << "Cantidad de ventas realizadas " << opcion_aux << endl;
                    cout << "Fueron realizadas por el playero: " << contador << endl;
                    cout << "cantidad de litros: " << contador_litros << endl;
                    break;
                }

            case 2:

                cout << "ingrese el Nro del surtidor " << endl;
                cin >> opcion_aux;

                if (opcion_aux < 1 || opcion_aux > 7)
                {
                    cout << "Numero de surtidor incorrecto. . ." << endl;
                    cout << "Ingrese un numero del 1 al 7" << endl;
                    cin >> opcion_aux;
                }
                while (archivo.read((char *)&venta, sizeof(VENTA)))
                {
                    if (opcion_aux == venta.surtidor)
                    {
                        contador_litros += venta.cantidad_litros;
                        contador++;
                    }
                }

                cout << "Cantidad de ventas realizadas en el surtidor Nro " << opcion_aux << endl;
                cout << "Numero de surtidor: " << contador << endl;
                cout << "cantidad de litros: " << contador_litros << endl;
                break;
            case 3:
                cout << "Tipo de combustible " << endl;
                cin >> tipo_combustible;

                if (strcmp(tipo_combustible, (char *)"np") != 0 && strcmp(tipo_combustible, (char *)"nc") != 0 && strcmp(tipo_combustible, (char *)"gp") != 0 && strcmp(tipo_combustible, (char *)"gc") != 0)
                {
                    cout << "Tipo de conbustible incorrecto. . ." << endl;
                    cout << " ingrese uno tipo valido: " << endl;
                    cout << "Nafta Premium [np], Nafta comun [nc], GasOil Premium [gp], GasOil comun [gc]" << endl;
                    cin >> tipo_combustible;
                }
                while (strcmp(tipo_combustible, (char *)"np") != 0 && strcmp(tipo_combustible, (char *)"nc") != 0 &&
                       strcmp(tipo_combustible, (char *)"gp") != 0 && strcmp(tipo_combustible, (char *)"gc") != 0)
                {
                    while (archivo.read((char *)&venta, sizeof(VENTA)))
                    {
                        if (strcmp(tipo_combustible, venta.combustible) == 0)
                        {
                            contador_litros += venta.cantidad_litros;
                            contador++;
                        }
                    }
                }
                cout << "Cantidad de litros de: " << tipo_combustible << endl;
                cout << " Cantidad vendida: " << contador_litros << endl;
                cout << "cantidad de ventas: " << contador << endl;
                break;
            default:
                cout << "opcion incorrecta. . .";
                break;

                archivo.close();
            }
        }
        else
        {
            cout << "no se pudo abrir el archivo. . .";
            exit(0);
        }
    }
    return 0;
}