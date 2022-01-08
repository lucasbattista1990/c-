/*elaborar un programa que permita estructurar el siguente menu

1. pilas
    introducir
    listar
    eliminar

2. colas
    introducir
    listar
    eliminar

la informacion a almacenar es escuelas, las estructuras seran trabajadas de forma dinamica */


#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>


using namespace std;

//Estructura de datos pilas
struct nodo{
    string nombre;
    string apellido;
    int edad;
    nodo *sig;
};
//Estructura de datos colas
struct nodo2{
    string nombre;
    string apellido;
    int edad;
    nodo2 *sig;
};

struct pila{
    nodo *cima;
};

struct cola{
    nodo2 *frente;
    nodo2 *final;
};

char nombre[100];
char apellido[100];
int edad;

//funciones de pilas
void crearPila(pila &p){
    p.cima = NULL;
}


void insertarPila(pila &p, string nombre, string apellido, int edad){
    nodo *nuevo = new nodo;
    nuevo->nombre = nombre;
    nuevo->apellido = apellido;
    nuevo->edad = edad;
    nuevo->sig = NULL;
    if(p.cima == NULL){
        p.cima = nuevo;
    }else{
        nuevo->sig = p.cima;
        p.cima = nuevo;
    }
}


void listarPila(pila p){
    if(p.cima == NULL){
        cout << "La pila esta vacia" << endl;
    }else{
        nodo *aux = p.cima;
        while(aux != NULL){
            cout << "Nombre: " << aux->nombre << endl;
            cout << "Apellido: " << aux->apellido << endl;
            cout << "Edad: " << aux->edad << endl;
            aux = aux->sig;
        }
    }
}


void eliminarPila(pila &p){
    if(p.cima == NULL){
        cout << "La pila esta vacia" << endl;
    }else{
        nodo *aux = p.cima;
        p.cima = p.cima->sig;
        delete aux;
    }
}


//funciones de colas


void crearCola(cola &c){
    c.frente = NULL;
    c.final = NULL;
}


void insertarCola(cola &c, string nombre, string apellido, int edad){
    nodo2 *nuevo = new nodo2;
    nuevo->nombre = nombre;
    nuevo->apellido = apellido;
    nuevo->edad = edad;
    nuevo->sig = NULL;
    if(c.frente == NULL){
        c.frente = nuevo;
        c.final = nuevo;
    }else{
        c.final->sig = nuevo;
        c.final = nuevo;
    }
}


void listarCola(cola c){
    if(c.frente == NULL){
        cout << "La cola esta vacia" << endl;
    }else{
        nodo2 *aux = c.frente;
        while(aux != NULL){
            cout << "Nombre: " << aux->nombre << endl;
            cout << "Apellido: " << aux->apellido << endl;
            cout << "Edad: " << aux->edad << endl;
            aux = aux->sig;
        }
    }
}


void eliminarCola(cola &c){
    if(c.frente == NULL){
        cout << "La cola esta vacia" << endl;
    }else{
        nodo2 *aux = c.frente;
        c.frente = c.frente->sig;
        delete aux;
    }
}

int main(){
    pila p;
    cola c;
    crearPila(p);
    crearCola(c);
    int opcion;
    //genero un menu
    do{
        cout << "1. Pila" << endl;
        cout << "2. Cola" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                cout << "1. Insertar" << endl;
                cout << "2. Listar" << endl;
                cout << "3. Eliminar" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opcion;
                switch(opcion){
                    case 1:
                        cout << "Ingrese el nombre: ";
                        cin >> nombre;
                        cout << "Ingrese el apellido: ";
                        cin >> apellido;
                        cout << "Ingrese la edad: ";
                        cin >> edad;
                        insertarPila(p, nombre, apellido, edad);
                        break;
                    case 2:
                        listarPila(p);
                        break;
                    case 3:
                        eliminarPila(p);
                        break;
                    default:
                        cout << "Opcion no valida" << endl;
                }
                break;
            case 2:
                cout << "1. Insertar" << endl;
                cout << "2. Listar" << endl;
                cout << "3. Eliminar" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opcion;
                switch(opcion){
                    case 1:
                        cout << "Ingrese el nombre: ";
                        cin >> nombre;
                        cout << "Ingrese el apellido: ";
                        cin >> apellido;
                        cout << "Ingrese la edad: ";
                        cin >> edad;
                        insertarCola(c, nombre, apellido, edad);
                        break;
                    case 2:
                        listarCola(c);
                        break;

                    case 3:
                        eliminarCola(c);
                        break;
                    default:
                        cout << "Opcion no valida" << endl;
                }
                break;
            case 3:
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
    }while(opcion != 3);

    return 0;
}


/* ************************************ Este programa fue elaborado por Alexis Nieto ************************************** */
