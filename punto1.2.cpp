/*Ejercicio 1.1) Personas
Desarrollar en un nuevo programa la búsqueda de personas de tal manera que al iniciarse el programa nos permite 
ingresar el apellido de la persona a buscar y nos liste por pantalla todas las personas encontradas para dicho apellido. 
Condiciones:
Utilizar el Archivo binario: personas.bin
Leer archivo por Read()
*/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

struct PERSONAS
{
    char apellido[30];
    char nombre[30];
    int edad;
    char sexo;
};

using namespace std;

int main()
{
    struct PERSONAS persona;
    char buscar[30];

    cout << "Ingrese el apellido a buscar: " << endl;
    cin.getline( buscar,30,'\n');

    ifstream archivo;
    archivo.open("personas.bin", ios::binary);
    if(archivo.fail()){
        cout << "No se puede abrir el archivo. . ." << endl;
        
    }
    if (archivo.is_open())
    {
        
        while (!archivo.eof())
        {
            archivo.read((char *)&persona, sizeof(persona));
            if (!archivo.eof())
            {
                if (strcmp(persona.apellido, buscar) != 0)
                {
                    cout << "Apellido: " << persona.apellido << endl;
                    cout << "Nombre: " << persona.nombre << endl;
                    cout << "Edad: " << persona.edad << endl;
                    cout << "Sexo: " << persona.sexo << endl;
                }
                else
                {
                    cout << "Apellido invalido..." << endl;
                    break;
                }
            }
        }
    }
    else
    {
        cout << "opcion incorrecta" << endl;
    }
    archivo.close();
    return 0;
}