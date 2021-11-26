/*Archivos C++ - Índices
Ejercicio 1) Alumnos
Se desea desarrollar un programa para gestionar las materias de los alumnos en la universidad.
De cada materia se cuenta con los siguientes datos: Código (int), Descripcion (50).
De cada alumno se cuenta con los siguientes datos: Documento (float), Apellido (50), Nombre (50).
 
El programa deberá permitir manejar los archivos de alumnos y alumnos-materias desde un menú de aplicación 
teniendo en cuenta que 1 (un) alumno puede estar inscripto en más de una materia y que estas no pueden estar repetidas.
 
Se deberán utilizar índices en ambos archivos, defina el criterio de actualización.
 
Desarrollar un menú que permita: Cargar Alumno, Cargar Materia-Alumno, Listar, Buscar 
un alumno y Salir del programa según el usuario lo desee.
 
Opción Cargar Alumno: registrar los datos de alumnos
Opción Cargar Materia: Solicitar el Documento del alumno para asociarlo a los datos de la materia a registrar.
Opción Buscar: poder buscar un alumno por Documento, mostrar sus datos y las materias inscriptas.
Opción Listar: Generar un listado de Alumnos por pantalla con sus respectivas materias. Si el alumno 
NO posee materias deberá mostrarse la leyenda “Sin materias”.
 
Ej:
Alumno:	Documento: xxxx	
	Apellido: zzzzzz		Nombre: vvvvvv
	Materias:
		Cód: xxxx		Descrip: zzzzzz
		Cód: bbbb		Descrip: ooooo
Alumno:	Documento: ggggg	
	Apellido: ssdss		Nombre: sdsds
	Materias:
		Sin materias
	
 
Opción Salir: consultar al usuario si está seguro de querer finalizar el programa.*/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct ALUMNO
{
    char documento[10];
    char apellido[50];
    char nombre[50];
};
struct indice
{
    char documento[10];
    int posicion;
};
struct MATERIA
{
    char documento[10];
    int codigo;
    char descripcion[50];
};

int cargar_alumno(ALUMNO, MATERIA, indice);
int cargar_materia();
int listar();
void buscar();

int main()
{
    int opcion;
    struct MATERIA materias;
    struct ALUMNO alumunos;
    struct indice indices;
    cout << "*****************************************************************************" << endl;
    cout << "*****************************************************************************" << endl;
    cout << "--------------------------- BIENVENIDO AL SISTEMA ---------------------------" << endl;
    cout << "*****************************************************************************" << endl;
    cout << "*****************************************************************************" << endl
         << endl;
    cout << "Pulse la opcion deseada. . . " << endl
         << endl;
    cout << "1. Cargar Alumno\t2. Cargar Materia-Alumno\t3. Listar\t4. Buscar un alumno\t0. Salir del programa" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
    {

        cargar_alumno(alumunos, materias, indices);

        break;
    }
    case 2:
    {

        cargar_materia();

        break;
    }
    case 3:
    {
        listar();
        break;
    }
    default:
    {
        break;
    }
    }
    return 0;
}

int cargar_alumno(struct ALUMNO alumnos, struct MATERIA materias, struct indice indices)
{
    int opcion;

    ofstream archivo;
    ofstream archivo2;
    ofstream archivoindice;
    ofstream archivo2indice;
    archivo2.open("alumno-materia.dat", ios::app | ios::ate | ios::binary);
    archivo.open("alumno.dat", ios::app | ios::binary | ios::ate);
    archivoindice.open("indice-alumnos.dat", ios::app | ios::ate | ios::binary);
    archivo2indice.open("indice-materias.dat", ios::app | ios::ate | ios::binary);

    if (!archivo.is_open())
    {
        if (!archivo2.is_open())
        {
            if (!archivoindice.is_open())
            {
                if (!archivo2indice.is_open())
                {
                    cout << "Archivo erroneo" << endl;
                }
            }
        }
        
    }
    cout << "Para continuar pulse 1: " << endl;
    cin >> opcion;


    while (opcion==1)
    {
        cout << "Ingrese el numero de DNI: ";
        cin >> alumnos.documento;
        strcmp(materias.documento, alumnos.documento);
        cout << "Ingrese el Apellido: " << endl;
        cin >> alumnos.apellido;
        cout << "Ingrese el Nombre: " << endl;
        cin >> alumnos.nombre;
        cout << "Ingrese el codigo de la materia en la que desea registrarse: " << endl;
        cin >> materias.codigo;
        cout << "Ingrese el nombre de la materia: " << endl;
        cin >> materias.descripcion;

        archivo.write((char *)&alumnos, sizeof(alumnos));
        strcmp(indices.documento , alumnos.documento);
        indices.posicion = archivo.tellp();

        archivoindice.write((char *)&indices, sizeof(indices));

        archivo2.write((char *)&materias, sizeof(materias));

        strcmp(indices.documento, alumnos.documento);
        indices.posicion = archivo2.tellp();

        archivo2indice.write((char *)&indices, sizeof(indices));

        cout << "Guardado en posicion:" << archivo.tellp() << endl;
        cout << "Registro: " << archivo.tellp() / sizeof(alumnos) << endl;

        cout << "1. Continuar\t 0. Salir " << endl;
        cin >> opcion;
        if (opcion == 1)
        {
            cargar_materia();
        }
        else
        {
            cout << "El programa finalizo con exito. . ." << endl;
        }
    }

    archivo2.close();
    archivo.close();
    archivoindice.close();
    archivo2indice.close();
}

int cargar_materia()
{

    struct MATERIA materias;
    struct ALUMNO alumnos;

    struct ALUMNO aux;
    struct MATERIA aux2;
    int opcion;
    ifstream archivo;
    ofstream archivo2;
    archivo.open("alumno.dat", ios::binary);
    archivo2.open("alumno-materia.dat", ios::app | ios::binary);
    if (!archivo.is_open())
    {
        if (!archivo2.is_open())
        {
            cout << "Archivo erroneo" << endl;
        }
    }
    archivo.read((char *)&alumnos, sizeof(alumnos));
    cout << "Para continuar vuelva a ingresar su DNI: " << endl;
    cin >> aux.documento;
    while (strcmp(aux.documento, alumnos.documento))
    {
        cout << "Ingrese el codigo de la materia en la que desea registrarse: " << endl;
        cin >> aux2.codigo;
        if (aux2.codigo != materias.codigo)
        {
            cout << "Primero debe registrarse . . ." << endl;
        }
       
        if (aux2.codigo == materias.codigo)
        {
            cout << "Ya esta cursando esta materia. . . " << endl;
        }
        else
        {
            cout << "Ingrese el nombre de la materia: " << endl;
            cin >> aux2.descripcion;
        }
        aux2.codigo = archivo.tellg();
        archivo2.write((char *)&materias, sizeof(materias));
        cout << "1. Continuar\t 0. Salir " << endl;
        cin >> opcion;
        if (opcion == 0)
        {
            cout << "El programa finalizo con exito. . ." << endl;
            break;
        }
    }

    opcion = 0;
    archivo.close();
    archivo2.close();
}

int listar()
{

    struct MATERIA materias;
    struct ALUMNO alumnos;
    struct indice indiceAlumno;
    struct indice indiceMateria;

    ifstream archivo;
    ifstream archivo2;
    archivo2.open("alumno-materia.dat", ios::binary);
    archivo.open("alumno.dat", ios::binary);

    ifstream IArchivo;
    ifstream IMaterias;

    IArchivo.open("indice-alumnos.dat", ios::binary);

    int band;

    //RECORRE EL INDICE DE ALUMNOS
    while (IArchivo.read((char *)&indiceAlumno, sizeof(indiceAlumno)))
    {
        //POSICIONA EN ARCHIVO DE ALUMNOS SEGUN POS EN INDICE
        archivo.seekg(indiceAlumno.posicion - sizeof(alumnos));
        //LEO EL ALUMNO LUEGO DE POSICIONARME
        archivo.read((char *)&alumnos, sizeof(alumnos));

        cout << "Apellido:" << alumnos.apellido << endl;
        cout << "Nombre: " << alumnos.nombre << endl;
        cout << "DNI: " << alumnos.documento << endl;

        //Buscar EN INDICE DE MATERIAS EL DOC ALUMNO
        band = 0;

        //IMaterias.seekg(0); //--> ESTABLECE PRIMER REGISTRO DEL INDICE
        IMaterias.open("indice-materias.dat", ios::binary);

        while (IMaterias.read((char *)&indiceMateria, sizeof(indiceMateria)))
        {
            if (indiceMateria.documento == alumnos.documento)
            {
                //SE POSICIONA EN ARCHIVO DE MATERIAS
                archivo2.seekg(indiceMateria.posicion - sizeof(materias));
                //LEE MATERIA DEL ALUMNO
                archivo2.read((char *)&materias, sizeof(materias));

                cout << "Materia: " << materias.descripcion << endl;
                cout << "Codigo de materia: " << materias.codigo << endl;
                band = 1;
            }
        }
        if (band == 0)
        {
            cout << "No se encontraron materias para el Alumno";
        }

        IMaterias.close();
    }

    archivo.close();
    archivo2.close();
    IArchivo.close();
}

void buscar()
{
    char documento[10];
    cout <<endl <<"Ingrese el documento del alumno a buscar:";
    cin >> documento;

    //BUSCAR EN EL INDICE
    ifstream Ialumnos;
    ifstream Imaterias;
    Ialumnos.open("indice-alumnos.dat", ios::binary);
    Imaterias.open("indice-materias.dat", ios::binary);

    struct indice inx;
    struct ALUMNO alumnos;
    struct MATERIA materias;

    //*************** BUSQUEDA BINARIA  ***********

        //Buscar clave o dato deseado. 
        int n;
        int medio;
        int inicio = 0;
        int fin = (sizeof(Ialumnos)/sizeof(ALUMNO)) - 1;        //n : cantidad de elementos
        int encontrado = 0;
        while (inicio <= fin)
        {
            //Medio será igual a la mitad de la dimensión delarreglo.
            medio = (fin + inicio) / 2;
            

            //POSICIONO EN EL MEDIO DEL ARCHIVO
            Ialumnos.seekg(medio * sizeof(ALUMNO));
            Ialumnos.read((char*) &inx, sizeof(inx));
            Imaterias.seekg(medio * sizeof(MATERIA));
            Imaterias.read((char*)&inx, sizeof(inx));
            

            //Si variable medio es similar a la clave de búsqueda despliega mensaje de encontrado.
            if (strcmp(inx.documento,documento) ==0)
            {
                //MOSTAR DATOS DEL PRODUCTO
                fstream Alumnos;
                Alumnos.open("alumno.dat", ios::binary);
                fstream Materias;
                Materias.open("alumnos-materia.dat", ios::binary);
                Alumnos.seekg(inx.posicion);
                Alumnos.read((char*) &documento , sizeof(ALUMNO));
                Materias.seekg(inx.posicion);
                Materias.read((char*)&documento, sizeof(MATERIA));

                cout << endl << "Documento:" << alumnos.documento;
                cout << endl << "Apellido:" <<alumnos.apellido << ", " << alumnos.nombre;
                cout << endl << "Materia:" << materias.descripcion;
                cout << endl << "codigo:" << materias.codigo;
                cout << endl;

                Alumnos.close();
                Materias.close();

                encontrado = 1;
                fin = -1;
            }
            //De lo contrario verifica si la posición del valor medio actual 
            //es menor que la clave de  búsqueda. 
            else
            {
                if ( strcmp(inx.documento,documento)==-1)
                    fin = medio - 1;
                else 
                    inicio = medio + 1;
            }
        }
        //Si no se encontró la clave despliega el mensaje de noencontrado. 
        if (encontrado != 1)
            cout<< "No se encontro el codigo buscado" << endl;


    //*********************************************



    Ialumnos.close();
    Imaterias.close();
}
/* ______________******____________******______________
_________________******____________******______________
___________________**________________**________________
_______________________________________________________*/