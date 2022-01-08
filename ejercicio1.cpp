/*haga un programa que simule un juego de bindo, utilice unicamente un solo carton para jugar. por lo tanto, se sabe que un bingo tiene 75
numeros, partiendo de 01 al 75, los cuales van saliendo de manera aleatoria cada turno y el carton
que se juega tiene una capacidad de 25 numeros repartidos en 5 filas 5 columnas, entonces, con las datos anteriormente estipulados
realice un programa que se ejecute y compile en c++, donde se requiere:
1. verificar que los numeros que van saliendo, se encuentran en la fila y columna de carton,
si, el numero que sale coincide con uno del carton, se necesita mostrar en pantalla y asignarle una marca.

2. realizar las comprobaciones para que los numeros que salgan cada turno, no se repitan, y estos sigan saliendo
hasta que el jugador alla completado una columna o una fila del carton o que la misma esfera se quede sin numero que mostrat

3. se requiere verificar cuando el jugardor complete una sola columna o una fila para que cante y muestre en pantalla que es el ganador.  */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void salir()
{
    cout << "Esta seguro que desea salir? [S]i / [N]o  " << endl;
    char opcion;
    cin >> opcion;
    if (toupper(opcion) == 'S')
    {
        exit(0);
    }
    else if (toupper(opcion) != 'S' && toupper(opcion) != 'N')
    {
        cout << "Opcion no valida" << endl;
    }
    else
    {
        return;
    }
}



int main()
{
    int carton[5][5];
    int numero;
    int fila;
    int columna;
    int contador = 0;

    srand(time(NULL));

    cout << "el carton es: " << endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            carton[i][j] = rand() % 75 + 1;
            cout << carton[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "*****************" << endl;
    cout << "Comienza el juego" << endl;
    cout << "*****************" << endl;
    cout << endl;

    cout << "Presione 1. para continuar" << endl;
    cout << "Presione 2. para salir" << endl;
    int opcion;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        do
        {
            numero = rand() % 75 + 1;
            cout << "El numero que sale es: " << numero << endl;
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (numero == carton[i][j])
                    {
                        cout << "El numero " << numero << " esta en la fila " << i + 1 << " y la columna " << j + 1 << endl;
                        carton[i][j] = 0;
                        contador++;
                    }
                }
            }

            if (contador == 0)
            {
                cout << "El numero " << numero << " no esta en el carton" << endl;
            }
            cout << endl;

            cout << "Presione 1. para jugar" << endl << endl;
            cout << "Presione 2. para salir" << endl << endl;
            cin >> opcion;
        } while (opcion == 1);
        break;

    case 2:
        salir();
        break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }
}
