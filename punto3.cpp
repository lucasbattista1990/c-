/*Utilizando el operador de flujo “<<” para escribir en archivo: 
Ejercicio 3: 
Utilizando los operadores cout/cin solicitar al usuario la cantidad de números a leer.
Solicitar al usuario el ingreso uno a uno de los números para ir registrando los mismos en un archivo de tipo texto. 
Deberá almacenarse un número por fila.
Utilizando el operador de flujo “>>” para leer un archivo: 
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int opcion;
    int numero;
    ofstream archivo;
    archivo.open("archivo.bin", ios::app | ios::binary );
    if (!archivo.is_open())
    {
        cout << "archivo erroneo" << endl;
    }

    cout << "1. Entrar al programa\t 2. salir" << endl;
    cin >> opcion;
    archivo << numero << endl;
    while (!archivo.eof())
    {
        switch (opcion)
        {
        case 1:
            cout << "ingrese un numero: \n" << endl;
            cin >> numero;
            archivo << numero << endl;
            cout << "1. seguir\t 2. salir" << endl;
            cin >> opcion;
            break;
        default:
            cout<< "El programa finalizo con exito. . .\n"<<endl;
            system("pause");
            break;
        }
        
    }
    
    archivo.close();
    return 0;
}