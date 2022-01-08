/*la empresa de transporte " las mejores rutas " cuenta con N choferes, de los cuales se conoce su nombre y los km que conducen
durante cada dia de la semana, esa informacion se guarda en un arreglo de N x 7. se requiere un programa que capture esa informacion
y genere un vector con el total de km que recorrio cada chofer durante la semana. al final se debe presentar
un reporte donde se muestre el nombre del chofer, que recorrio mas kilometros, al igual que el nombre del chofer, que recorrio
menos kilometros en la semana. */

#include <iostream>

using namespace std;

int main()
{
    int km[7];
    int opcion=0;
    int chofer[opcion];
    int mayor = 0, menor = 9999999;
    int i, j;
    char nombre[20];
    int total = 0;

    cout << "*******************************"<<endl;
    cout << "*******************************"<<endl;
    cout << "*********LAS MEJORES RUTAS****"<<endl;
    cout << "*******************************"<<endl;
    cout << "*******************************"<<endl;
    cout << endl;

    cout << "Ingrese el numero de choferes: "<<endl;
    cin >> opcion;

    for (i = 0; i < 5; i++)
    {
        cout << "ingrese el nombre del chofer: ";
        cin >> nombre;
        
        for (j = 0; j < 7; j++)
        {
            cout << "ingrese los km que recorrio el chofer el dia " << j + 1 << ": ";
            cin >> km[j];
            total = total + km[j];
        }
        //mostrar choferes con sus nombre y total de km recorridos
        cout << "el chofer " << nombre << " recorrio " << total << " km" << endl;
        chofer[i] = total;
        total = 0;
    }

    

    for (i = 0; i < 5; i++)
    {
        if (chofer[i] > mayor)
        {
            mayor = chofer[i];
        }
    }
    cout << "el chofer que recorrio mas km es: " << mayor << endl;

    for (i = 0; i < 5; i++)
    {
        if (chofer[i] < menor)
        {
            menor = chofer[i];
        }
    }
    cout << "el chofer que recorrio menos km es: " << menor << endl;




    return 0;
}