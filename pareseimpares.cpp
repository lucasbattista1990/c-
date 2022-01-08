/*Elaborar un programa que determine cuantos dígitos pares y cuantos dígitos impares tienen un numero de “n” dígitos. */


#include <iostream>
#include <math.h>


using namespace std;


int main()
{
    int numero, pares, impares;

    cout << "ingrese un numero: " << endl;
    cin >> numero;

    while (numero != 0)
    {
        if (numero % 2 == 0)
        {
            pares++;
        }
        else
        {
            impares++;
        }
        numero /= 10;
    }

    cout << "el numero tiene " << pares << " digitos pares" << endl;
    cout << "el numero tiene " << impares << " digitos impares" << endl;

    return 0;
}