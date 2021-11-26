/*Gestión de insumos informáticos
Se desea desarrollar un programa para gestionar la entrega de insumos informáticos al personal de la empresa.

Por cada entrega se registran los siguientes datos:
Legajo del empleado [A10]
Código insumo
Nombre insumo
Cantidad entregada

Se desea desarrollar un menú que permita registrar la [E]ntrega de insumos, [B] buscar entrega por legajo,
[R] reporte de entregas ordenado por Legajo y [S] Salir.

Para el desarrollo de las acciones, cada opción del Menú deberá estar desarrollada en una función independiente.

Funciones que deben existir, el tipo de dato devuelto y los parámetros quedan a criterio del programador:
Entrega()
Validar()
Mostrar()
Buscar()
Listar()
Indexar()


Funcionamiento del programa:

El sistema deberá operar con un archivo de entregas y su correspondiente índice el cual será generado al momento del alta.
La generación del índice NO implica ordenamiento.

La función Indexar() estará disponible desde el Menú permitiendo al usuario ordenar el índice en el momento que lo desee.


Opción Entregas: Para recibir una nueva entrega de insumos deberá validarse que NO exista una entrega previa para dicho legajo.
De existir, debe cancelar la entrega y utilizando la función Mostrar(),  mostrar por pantalla los datos de la entrega existente.

La validación de entregas anteriores debe realizar utilizando la función validar() sobre el índice de entrega de insumos.


Opción Buscar: haciendo uso de la funciones Buscar() el usuario podrá verificar si existen alguna entrega para un legajo.
Las búsquedas DEBERAN realizarse sobre el archivo de índices utilizando el METODO BINARIO.
Si no existe, informar al usuario, sino mostrar usando la función mostrar() los datos de la entrega buscada.

Opción Listar: Listar por pantalla TODAS las entregas realizadas en orden ascendente por legajo.
Deberá utilizar la función Mostrar() para mostrar cada una de las entregas.
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
    int entregado;
}empleado;

struct INDICE{
    char legajo[10];
    int posicion;
}indice;


void buscar(char[10]);
void entrega();
bool validar(EMPLEADOS);
void mostrar(int);

int main(){
    char opcion;

    cout << "Bienvenido al programa de gestion de insumos informaticos" << endl;
    cout << "[E] Entrega de insumos" << endl;
    cout << "[B] Buscar entrega" << endl;
    cout << "[R] Reporte de entregas" << endl;
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
        buscar(indice.legajo);
        break;
    case 'R':
        cout << "Listar entregas" << endl;
        break;
    case 'S':
        cout << "Salir" << endl;
        break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }
    return 0;

}
   
void entrega(){
    

    ofstream archivo;
    ofstream indice;
    archivo.open("entregas.dat", ios::binary| ios::app | ios::in | ios::out);
    indice.open("indice.inx", ios::binary | ios::app | ios::ate );

    if(!archivo && !indice){
        cout << "Error al abrir el archivo" << endl;

    }
    cout << endl << "Ingrese el legajo del empleado: ";
    cin >> empleado.legajo;
    validar(empleado);
    cout << endl << "Ingrese el codigo del insumo: ";
    cin >> empleado.codigoinsumo; 
    cout << endl << "Ingrese el nombre del insumo: ";
    cin >> empleado.nombreinsumo;
    cout << endl << "Ingrese la cantidad entregada: ";
    cin >> empleado.entregado;
    cout << endl;
    archivo.write((char*)&empleado, sizeof(empleado));

    

}


bool validar(EMPLEADOS empleado)
{

    INDICE indice;
    ifstream Iclientes;
    Iclientes.open("indice.inx", ios::binary);

    while (Iclientes.read((char *)&indice, sizeof(indice)))
    {
        if (strcmp(indice.legajo, empleado.legajo) == 0)
        {
            Iclientes.close();
            return true;
        }
    }
    Iclientes.close();
    return false;
}

void buscar(char legajo[10])
{
    ifstream archivo;
    INDICE indice;
    archivo.open("indice.inx", ios::binary);
   
   cout<<"Ingrese legajo a buscar"<<endl;
   cin>>legajo;
//*************** BUSQUEDA BINARIA  ***********

        //Buscar clave o dato deseado. 
        int posicion;
        int medio;
        int inicio = 0;
        int fin = archivo.tellg()/sizeof(indice);        
        int encontrado = 0;
        while (inicio <= fin)
        {
            //Medio ser� igual a la mitad de la dimensi�n delarreglo.
            medio = (fin + inicio) / 2;
            

            //POSICIONO EN EL MEDIO DEL ARCHIVO
             archivo.seekg(medio*sizeof(indice));            //me posiciono en lamitad de los elementos
             archivo.read((char*) &indice, sizeof(indice));

            //Si variable medio es similar a la clave de b�squeda despliega mensaje de encontrado.
            if (strcmp(indice.legajo , legajo) ==0)
            {
                mostrar(posicion);
            }
            //De lo contrario verifica si la posici�n del valor medio actual 
            //es menor que la clave de  b�squeda. 
            else
            {
                if ( strcmp(legajo,indice.legajo)==-1)
                    fin = medio - 1;
                else 
                    inicio = medio + 1;
            }
        }
        //Si no se encontr� la clave despliega el mensaje de noencontrado. 
        if (encontrado!= 1){
          cout<<"no se encontro el codigo buscado"<<endl;	
          
        }
      //*********************************************   

}
    
void mostrar(int posicion){
   
    EMPLEADOS empleado;
    ifstream archivo;
    archivo.open("entregas.dat", ios::binary);
    archivo.seekg(posicion);
    archivo.read((char *)&empleado , sizeof(empleado));

    cout << "Su coso ya existe asi que cancelado\n";
    cout << empleado.legajo << endl;
    cout << empleado.codigoinsumo << endl;
    cout << empleado.entregado << endl;
    cout << empleado.nombreinsumo << endl;
    archivo.close();
    
}