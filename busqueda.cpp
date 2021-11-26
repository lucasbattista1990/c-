/*desarrollar la opcion de busqueda de repuestos por codigo y rubro -(indiceA) Y SOLO POR CODIGO (indiceB)
ultilizar metodo binario indicando el resultado de la busqueda*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct REPUESTOS
{
    char codigo[10];
    char descripcion[50];
    char marca[10];
}repuestos;

struct INDICE
{
    char codigo[10];
    int posicion;
}indice;

int main()
{
    int opcion;
    char codigoBuscado[10];
    char descripcionBuscada;
    cout << endl
         << "[1] Buscar por codigo y rubro> ";
    cout << endl
         << "[2] Buscar solo por codigo> ";
    cout << endl;

    cin >> opcion;

    switch (opcion)
    {
    case 1:
    {

        cout << endl
             << "Ingrese el codigo del repuesto a buscar: ";
        cin >> codigoBuscado;
        do
        {
            cout << endl
                 << "Ingrese rubro del repuesto a buscar: ";
            cout << endl
                 << "[A] Automotor.";
            cout << endl
                 << "[M] Moto.";
            cout << endl
                 << "[N] Nautica.";
            cout << endl
                 << "[V] Varios.";
            cout << endl;
            cin >> descripcionBuscada;
        } while (toupper(descripcionBuscada) != 'A'); // completar demas letras
        ifstream inx;
        ifstream DPrincipal;
        switch (descripcionBuscada)
        {
        case 'A':
            inx.open("automor.inx", ios::binary);
            DPrincipal.open("automotor.dat", ios::binary);
            break;
        case 'M':
            inx.open("motos.inx", ios::binary);
            DPrincipal.open("motos.dat", ios::binary);
            break;
        case 'N':
            inx.open("nautica.inx", ios::binary);
            DPrincipal.open("nautica.dat", ios::binary);
            break;
        case 'V':
            inx.open("varios.inx", ios::binary);
            DPrincipal.open("varios.dat", ios::binary);
            break;
        default:
            break;
        } // completar con los demas archivos
        int medio;
        int inicio = 0;
        inx.seekg(0, ios::end);
        int fin = inx.tellg() / sizeof(indice);
        bool encontrado = false;
        while (inicio <= fin)
        {
            medio = (fin + inicio) / 2;
            inx.seekg(medio * sizeof(indice));
            inx.read((char *)&indice, sizeof(indice));

            // Si variable medio es similar a la clave de búsqueda despliega mensaje de encontrado.
            if (strcmp(indice.codigo, codigoBuscado) == 0)
            {
                // MOSTAR DATOS DEL PRODUCTO

                DPrincipal.seekg(indice.posicion - sizeof(repuestos));
                DPrincipal.read((char *)&repuestos, sizeof(repuestos));
                cout << endl
                     << "Codigo: " << indice.codigo;
                cout << endl
                     << "Posicion: " << indice.posicion;
                cout << endl
                     << "Descripcion: " << repuestos.descripcion;
                cout << endl
                     << "Marca: " << repuestos.marca << endl;

                encontrado = true;
                break;
            }
            // De lo contrario verifica si la posición del valor medio actual
            // es menor que la clave de  búsqueda.
            else
            {
                if (strcmp(codigoBuscado, indice.codigo) == -1)
                    fin = medio - 1;
                else
                    inicio = medio + 1;
            }
        }
        // Si no se encontró la clave despliega el mensaje de noencontrado.
        if (!encontrado)
        {
            cout << endl
                 << "No se encontro " << endl;
        }

        system("pause");
        inx.close();
        DPrincipal.close();
    }
    break;

    case 2:
        cout << endl
             << "Ingrese el codigo a buscar:";
        cin >> codigoBuscado;

        // BUSCAR EN EL INDICE
        ifstream indiceA;
        indiceA.open("repuestosindicecompleto.inx", ios::binary);
       


        //*************** BUSQUEDA BINARIA  ***********

        // Buscar clave o dato deseado.

        int medio;
        int inicio = 0;
        int fin = (sizeof(indiceA) / sizeof(repuestos)) - 1; // n : cantidad de elementos
        int encontrado = 0;
        while (inicio <= fin)
        {
            // Medio será igual a la mitad de la dimensión delarreglo.
            medio = (fin + inicio) / 2;

            // POSICIONO EN EL MEDIO DEL ARCHIVO
            indiceA.seekg(medio * sizeof(repuestos));
            indiceA.read((char *)&indice, sizeof(indice));

            // Si variable medio es similar a la clave de búsqueda despliega mensaje de encontrado.
            if (strcmp(indice.codigo, codigoBuscado) == 0)
            {
                // MOSTAR DATOS DEL PRODUCTO
                indiceA.seekg(indice.posicion);
                indiceA.read((char *)&repuestos, sizeof(repuestos));

                cout << endl
                     << "Codigo:" << repuestos.codigo;
                cout << endl
                     << "Descripcion:" << repuestos.descripcion;
                cout << endl
                     << "Marca:" << repuestos.marca;
                cout << endl;

                indiceA.close();

                encontrado = 1;
                fin = -1;
            }
            // De lo contrario verifica si la posición del valor medio actual
            // es menor que la clave de  búsqueda.
            else
            {
                if (strcmp(codigoBuscado, indice.codigo) == -1)
                    fin = medio - 1;
                else
                    inicio = medio + 1;
            }
        }
        // Si no se encontró la clave despliega el mensaje de noencontrado.
        if (encontrado != 1)
            cout << "No se encontro el codigo buscado" << endl;

        //*********************************************

        indiceA.close();
    }
}
