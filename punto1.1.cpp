/* Ejercicio 1) Personas
Se desea desarrollar un programa para resguardar datos utilizando una estructura de Persona.
Entre los datos solicitados están: apellido[20], nombre[20], int edad, char sexo.
El sistema deberá consultar al usuario si desea Cargar un Persona o Finalizar.
Los datos ingresados en la carga deberán ser resguardados en el archivo.
Condiciones:
Archivo tipo binario, nombre: personas.bin
Grabar archivo por Write()
Si contiene información previa, la misma deberá conservarse.
La edad deberá estar comprendida entre 1 y 100 años
El sexo podrá ser: F, M, O*/

#include <iostream>
#include <fstream>

using namespace std;

struct PERSONAS
{
    char apellido[30];
    char nombre[30];
    int edad;
    char sexo;
};

int main()
{
    struct PERSONAS persona;
    int opcion;

    ofstream archivo;
    archivo.open("personas.bin", ios::app | ios::binary);
    if (!archivo.is_open())
    {
        cout << "archivo erroneo" << endl;
    }

    cout << "***************************" << endl;
    cout << "   BIENVENIDO AL SISTEMA   " << endl;
    cout << "***************************" << endl
         << endl;
    cout << "Pulse la opcion deseada. . . " << endl
         << endl;
    cout << "1. Cargar persona.\t 2. Salir.\t" << endl
         << endl;
    cin >> opcion;

    if (opcion <= 0 || opcion >= 3)
    {
        cout << "Opcion invalida . . ." << endl
             << endl;
    }

    while (opcion != 2)
    {
        switch (opcion)
        {
        case 1:
            cout << "Ingrese su Apellido: " << endl;
            cin >> persona.apellido;            
            cin.getline(persona.apellido, 30, '\n');
        

            cout << "Ingrese su Nombre: " << endl;
            cin >> persona.nombre;
            cin.getline(persona.nombre, 30, '\n');

            cout << "Ingrese su edad: " << endl;
            cin >> persona.edad;

            if (persona.edad < 1 || persona.edad > 100)
            {
                cout << "Imposible realizar la carga. . . " << endl;
                cout << "Igrese una Edad valida: Entre 1 y 100.." << endl;
                cin >> persona.edad;
            }

            cout << "Ingrese su sexo. Indicando M,F,O " << endl;
            cin >> persona.sexo;
            if (toupper(persona.sexo) == 'M' || toupper(persona.sexo) == 'F' || toupper(persona.sexo) == 'O')
            {

                cout << "1. Cargar persona.\t 2. Salir.\t" << endl
                     << endl;
                cin >> opcion;
            }
            else
            {
                cout << "Opcion incorrecta. . . " << endl
                     << endl;
                cout << "Igrese una opcion valida: m, f, o " << endl;
                cin >> persona.edad;

                break;
            }
            archivo.write((char *)&persona, sizeof(persona));
            break;

        default:
            cout << "El programa finalizo con exito. . .\n"
                 << endl;
            system("pause");
            break;
        }
    }

    archivo.close();
    return 0;
}