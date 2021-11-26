/*Ejercicio 1) Personas
Se desea desarrollar un programa para resguardar datos en un archivo binario almacenados en una estructura de Personas. 
Entre los datos están: Documento, apellido y nombre.
Desarrollar un menú que permita: Cargar, Listar, Mostrar, Buscar y Salir del programa según el usuario lo desee.

Opción Cargar: una vez registrados los datos en el archivo deberá indicarse la posición del registro. Ej: registro guardado en posición: 3

Opción Listar: deberán mostrarse todos los datos de las personas almacenadas en el archivo además de la posición del 
registro dentro del archivo.

Opción Mostrar: solicitar al usuario el registro (posición) de la persona que desea mostrar por pantalla.
 De no encontrarse indicar que el registro no existe.

Opción Buscar: solicitar al usuario el Documento de la persona, buscarlo en el archivo y mostrar su posición.
De no encontrarse indicar que el documento no existe.

Opción Salir: consultar al usuario si está seguro de querer finalizar el programa.*/

#include <iostream>
#include <fstream>

using namespace std;

struct PERSONAS
{
    int documento;
    char apellido[25];
    char nombre[25];
};

int main()
{
    struct PERSONAS persona;
    int opcion;
    int posicion = 0;

    cout << "***************************" << endl;
    cout << "   BIENVENIDO AL SISTEMA   " << endl;
    cout << "***************************" << endl
         << endl;
    cout << "Pulse la opcion deseada. . . " << endl
         << endl;
    cout << "1. Cargar\t2. Listar\t3. Mostrar\t4. Buscar\t 0. Salir" << endl;
    cin >> opcion;

    ofstream archivo;
    archivo.open("personas.dat", ios::app | ios::binary | ios::ate);
    if (!archivo.is_open())
    {
        cout << "Archivo erroneo" << endl;
    }

    switch (opcion)
    {
    case 1:
    {
        cout << "Ingrese el numero de DNI: " << endl;
        cin >> persona.documento;
        cout << "Ingrese el Apellido: " << endl;
        cin >> persona.apellido;
        cout << "Ingrese el Nombre: " << endl;
        cin >> persona.nombre;
        cout << "Guardado en posicion:" << archivo.tellp() << endl;
        archivo.write((char *)&persona, sizeof(persona));
        posicion++;
        archivo.close();
    }
    break;
    case 2:
    {
        ifstream archivo;
        archivo.open("personas.dat", ios::binary);

        while (archivo.read((char *)&persona, sizeof(persona)))
        {
            cout << persona.apellido << endl;
            cout << persona.nombre << endl;
            cout << persona.documento << endl;
            cout << "Posicion:" << archivo.tellg() << endl;
            cout << "registro:" << archivo.tellg() / sizeof(persona) << endl;
            cout << endl;
            posicion++;
        }
        if (archivo.eof())
        {
            archivo.close();
            archivo.open("personas.dat", ios::binary);
        }
    }
    break;
    case 3:
    {
        

        cout << "Digite la posicion que desea buscar :";
        cin >> posicion;

        ifstream archivo;
        archivo.open("personas.dat", ios::binary);
        archivo.seekg((posicion - 1) * sizeof(persona));
        if (archivo.read((char *)&persona, sizeof(persona)) && !archivo.eof())
        {

            cout << "Apellido:" << persona.apellido << endl;
            cout << "Nombre: " << persona.nombre << endl;
            cout << "DNI: " << persona.documento << endl;

            archivo.close();
        }
        else
        {
            cout << "Posicion invalida. . ." << endl;
        }
    }
    break;
    case 4:
    {
        ifstream archivo;
        int aux_dni = 0;
        int bandera, posicion = 0;
        archivo.open("personas.dat", ios::binary);
        cout << "Digite un numero de DNI :";
        cin >> aux_dni;
        while (!archivo.eof())
        {
            if (archivo.read((char *)&persona, sizeof(persona)) && aux_dni == persona.documento)
            {
                posicion = archivo.tellg() / sizeof(persona);
                bandera = 1;
            }
        }

        if (bandera == 1)
        {
            cout << "El DNI se encuentra en la posicion: " << posicion << endl;
        }
        else
        {
            cout << "DNI no encontrado. . ." << endl;
        }

        archivo.close();
    }
    break;
    default:
        cout << "Programa finalizado con exito. . ." << endl;
        exit(0);
        break;
    }

    archivo.close();
    return 0;
}