/*Gestión de insumos informáticos
Se desea desarrollar un programa para gestionar la entrega de insumos informáticos al personal de la empresa.

Por cada entrega se registran los siguientes datos:
Legajo del empleado [10]
Código insumo
Nombre insumo
Cantidad entregada

Se desea desarrollar un menú que permita registrar la [E]ntrega de insumos, [B] buscar entrega por legajo, [R] reporte de entregas ordenado
por Legajo y [S] Salir.

Para el desarrollo de las acciones, cada opción del Menú deberá estar desarrollada en una función independiente.

Funciones que deben existir, el tipo de dato devuelto y los parámetros quedan a criterio del programador:
Entrega()
Validar()
Mostrar()
Buscar()
Listar()
Indexar()


Funcionamiento del programa:

El sistema deberá operar con un inx de entregas y su correspondiente índice el cual será generado al momento del alta.
La generación del índice NO implica ordenamiento.

La función Indexar() estará disponible desde el Menú permitiendo al usuario ordenar el índice en el momento que lo desee.


Opción Entregas: Para recibir una nueva entrega de insumos deberá validarse que NO exista una entrega previa para dicho legajo.
De existir, debe cancelar la entrega y utilizando la función Mostrar(),  mostrar por pantalla los datos de la entrega existente.

La validación de entregas anteriores debe realizar utilizando la función validar() sobre el índice de entrega de insumos.


Opción Buscar: haciendo uso de la funciones Buscar() el usuario podrá verificar si existen alguna entrega para un legajo. Las búsquedas
DEBERAN realizarse sobre el inx de índices utilizando el METODO BINARIO.
Si no existe, informar al usuario, sino mostrar usando la función mostrar() los datos de la entrega buscada.

Opción Listar: Listar por pantalla TODAS las entregas realizadas en orden ascendente por legajo. Deberá utilizar la función Mostrar() para mostrar cada una de las entregas.
Opción Salir: consultar al usuario si está seguro de querer finalizar el programa.

IMPORTANTE
El desarrollo debe “COMPILAR” para considerarlo aprobable

La existencia de código no utilizado descuenta puntos.

Deben respetarse las funciones sugeridas: Entrega(), Validar(),  Mostrar(),
Buscar(), Listar() y Indexar()

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct EMPLEADOS
{
    char legajo[10];
    int codigoinsumo;
    char nombreinsumo[30];
    int cant;
} empleado;

struct INDICE
{
    char legajo[10];
    int posicion;
} indice;

void listar();
void entrega();
void mostrar(int);
void buscar();
void indexar();
int validar(char[10]);
void salir();

int main()
{
    char opcion;
    do
    {
        cout << "Bienvenido al programa de gestion de insumos informaticos" << endl;
        cout << "[E] Entrega de insumos" << endl;
        cout << "[B] Buscar entrega" << endl;
        cout << "[R] Reporte de entregas" << endl;
        cout << "[O] Ordenar indice: " << endl;
        cout << "[S] Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (toupper(opcion))
        {
        case 'E':
            cout << "Entrega de insumos" << endl;
            entrega();
            break;
        case 'B':
            cout << "Buscar entrega" << endl;
            buscar();
            break;
        case 'R':
            cout << "Listar entregas" << endl;
            listar();
            break;
        case 'O':
            cout << "Ordenar indice de entregas para poder realizar busqueda" << endl;
            indexar();
            break;
        case 'S':
            cout << "Salir" << endl;
            salir();
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (1 < 2);

    return 0;
}

void entrega()
{
    ofstream inx;
    inx.open("entregas.dat", ios::app | ios::binary);
    fstream Aindice;
    Aindice.open("indice.inx", ios::in | ios::out | ios::app | ios::binary);

    cout << "Ingrese el legajo del empleado   " << endl;
    cin >> empleado.legajo;
    if (validar(empleado.legajo) == -1)
    {
        cout << "El legajo ya existe" << endl<< endl;
        
        return;
    }
    cout << "Ingrese el codigo del insumo   " << endl;
    cin >> empleado.codigoinsumo;
    cout << "Ingrese el nombre del insumo   " << endl;
    cin.ignore();
    cin.getline(empleado.nombreinsumo, 30);
    cout << "Ingrese la cantidad entregada   " << endl;
    cin >> empleado.cant;
    inx.write((char *)&empleado, sizeof(empleado));
    strcpy(indice.legajo, empleado.legajo);
    inx.seekp(0, ios::end);
    indice.posicion = (inx.tellp() / sizeof(empleado)) - 1;
    Aindice.write((char *)&indice, sizeof(indice));
    Aindice.close();
    inx.close();
}

int validar(char legajo[10])
{
    ifstream Aindice;
    Aindice.open("indice.inx", ios::binary);
    while (Aindice.read((char *)&indice, sizeof(indice)))
    {
        if (strcmp(indice.legajo, legajo) == 0)
        {   
            mostrar(indice.posicion);
            cout << endl;
            Aindice.close();
            return -1;
        }
    }

    return 0;
}

void mostrar(int posicion)
{
    ifstream inx;
    inx.open("entregas.dat", ios::binary);
    inx.seekg(posicion * sizeof(empleado));
    inx.read((char *)&empleado, sizeof(empleado));
    cout << "Legajo: " << empleado.legajo << endl;
    cout << "Codigo del insumo: " << empleado.codigoinsumo << endl;
    cout << "Nombre del insumo: " << empleado.nombreinsumo << endl;
    cout << "Cantidad entregada: " << empleado.cant << endl;
    inx.close();
    
}

void buscar()
{
    ifstream inx;
    char legajo[10];
    inx.open("indice.inx", ios::binary | ios::ate);

    cout << "Ingrese legajo a buscar" << endl;
    cin >> legajo;

    // Buscar clave o dato deseado.
    int posicion;
    int medio;
    int inicio = 0;
    int fin = inx.tellg() / sizeof(indice);
    while (inicio <= fin)
    {
        // Medio ser igual a la mitad de la dimension delarreglo.
        medio = (fin + inicio) / 2;

        // POSICIONO EN EL MEDIO DEL inx
        inx.seekg(medio * sizeof(indice));
        inx.read((char *)&indice, sizeof(indice));

       
        // Si variable medio es similar a la clave de busqueda despliega mensaje de encontrado.
        if (strcmp(indice.legajo, legajo) == 0)
        {
            posicion = indice.posicion;
            mostrar(posicion);
            return;
        }
        // De lo contrario verifica si la posicion del medio
        // es menor que la clave de busqueda
        else
        {
            if (strcmp(legajo, indice.legajo) == -1)
                fin = medio - 1;
            else
                inicio = medio + 1;
        }
    }

}

void indexar()
{
    INDICE indice_aux;
    fstream inx;

    inx.open("indice.inx", ios::in | ios::out | ios::binary);

    int i, j;                                      // Variables contadoras del ciclo.
    inx.seekg(0, ios::end);                        // me posiciono en el final del inx
    int ielementos = inx.tellg() / sizeof(indice); // ielementos contiene la cantidad de elementos del indice
   
    for (i = 1; i < ielementos; i++)               // primer bucle burbuja
    {
        
        for (j = 0; j < ielementos - i; j++){ //segundo bucle burbuja
            inx.seekg(j * sizeof(indice));
            inx.read((char *)&indice, sizeof(indice));
            inx.read((char*)&indice_aux, sizeof(indice_aux));   // lee el elemento nro j+1 y guarda en struct indice

          

            if (strcmp( indice.legajo, indice_aux.legajo) > 0) // Compara claves, si el segundo elemento es menor, invierte posiciones
            {
                inx.seekg(j * sizeof(indice)); // se posiciona el elemento nro j
                inx.write((char *)&indice_aux, sizeof(indice)); // escribe el elemento nro j+1
                inx.write((char *)&indice, sizeof(indice));
            }
        }
    }
    inx.close();
}

void listar()
{
    ifstream Aindice;
    Aindice.open("indice.inx", ios::binary);

    do
    {
        cout << "Recuerde que para listar debera ordenar los datos del indice previamente" << endl;
        cout << "Esto evita errores en el programa  " << endl;
        cout << "Desea continuar [S]i / [N]o  " << endl;
        char opcion;
        cin >> opcion;

        if (toupper(opcion) == 'N')
        {
            return;
        }
        else if (toupper(opcion) != 'S' && toupper(opcion) != 'N')
        {
            cout << "Opcion no valida" << endl;
        }
        else
        {
            while (Aindice.read((char *)&indice, sizeof(indice)))
            {
                mostrar(indice.posicion);
            }
            return;
        }
    } while (1 < 2);
}

void salir(){
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

