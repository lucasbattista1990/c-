#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct MANTENIMIENTO
{
    long documento;
    char apellido[20];
    char nombre[20];
    char marca[30];
    int modelo;
    char mantenimiento[100];
    int costo;
    int pago;
};

struct INDICE
{
    long documento;
    int posicion;
};

int menu();
int alta();
int validar(MANTENIMIENTO);
void historico(MANTENIMIENTO);
void principal(MANTENIMIENTO, int);
void genera_indice(int);
void buscar();
void reporte();
int salir();

int main()
{
    char opcion;
    do
    {
        opcion = toupper(menu());
        switch (opcion)
        {
        case 'A':
            alta();
            break;
        case 'B':
            buscar();
            break;
        case 'R':
            reporte();
            break;
        case 'S':
            salir();
            break;
        default:
            break;
        }
    } while (1 < 2);
}

int menu()
{
    char opcion;

    cout << "*****************************************************************************" << endl;
    cout << "*****************************************************************************" << endl;
    cout << "--------------------------- BIENVENIDO AL SISTEMA ---------------------------" << endl;
    cout << "*****************************************************************************" << endl;
    cout << "*****************************************************************************" << endl
         << endl;
    cout << "Pulse la opcion deseada. . . " << endl
         << endl;
    cout << "[A] alta reparaciones" << endl;
    cout << "[B] buscar por documento de la persona" << endl;
    cout << "[R] reporte de reparaciones impagas" << endl;
    cout << "[S] Salir" << endl;

    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    while (toupper(opcion) != 'A' && toupper(opcion) != 'B' && toupper(opcion) != 'R' && toupper(opcion) != 'S')
        ;
    return opcion;
}

int alta()
{
    ifstream Aprincipal;
    Aprincipal.open("principal.dat", ios::binary);

    MANTENIMIENTO mantenimiento;

    char opcion;
    int posicion = 0;

    do
    {
        system("cls");

        cout << "Ingrese su numero de documento : " << endl;
        cin >> mantenimiento.documento;
        posicion = validar(mantenimiento);
        if (posicion > 0)
        {

            Aprincipal.seekg(posicion - sizeof(mantenimiento));
            Aprincipal.read((char *)&mantenimiento, sizeof(mantenimiento));

            if (mantenimiento.pago != 1)
            {
                cout << endl
                     << "Cliente con Deuda" << endl;
                cout << "DNI: " << mantenimiento.documento << endl;
                cout << "Apellido: " << mantenimiento.apellido << endl;
                cout << "Nombre: " << mantenimiento.nombre << endl;
                cout << "Marca: " << mantenimiento.marca << endl;
                cout << "Modelo: " << mantenimiento.modelo << endl;
                cout << "Descripcion del Mantenimiento: " << mantenimiento.mantenimiento << endl;
                cout << "Costo: " << mantenimiento.costo << endl;
                system("pause");
                break;
            }
            else
            {
                historico(mantenimiento);
                principal(mantenimiento, posicion);
            }
        }
        else
        {
            principal(mantenimiento, 0);
        }
        cout << "Realizo otro tipo de mantenimiento (S/N)?";
        cin >> opcion;

    } while (toupper(opcion) != 'N');
    Aprincipal.close();
}

int validar(MANTENIMIENTO mantenimiento)
{
    ifstream inx;
    // me fijo si el documento es par o inpar buscando en la estructura
    if (mantenimiento.documento % 2 == 0)
    {
        inx.open("indicepar.inx", ios::binary);
    }
    else
    {
        inx.open("indiceinpar.inx", ios::binary);
    }
    INDICE indice;

    // busqueda binaria
    int inicio = 0;
    int medio;
    int fin;

    inx.seekg(0, ios::end);
    fin = inx.tellg() / sizeof(indice);
    while (inicio <= fin)
    {
        medio = (inicio + fin) / 2;                // calculo el medio sumando el incio con el fin y dividiendo en la mitad
        inx.seekg(medio * sizeof(indice));         // me posiciono en la mitad de los elementos
        inx.read((char *)&indice, sizeof(indice)); // leo desde el indice

        if (indice.documento == mantenimiento.documento)
        {

            inx.close();
            return indice.posicion;
        }
        else if (indice.documento > mantenimiento.documento)
        {
            fin = medio - 1;
        }
        else
        {
            fin = medio + 1;
        }
    }
    inx.close();
    return -1;
}

void historico(MANTENIMIENTO mantenimiento)
{
    ofstream historico("historico.dat", ios::app | ios::ate | ios::binary);
    historico.write((char *)&mantenimiento, sizeof(mantenimiento));
    historico.close();
}

void principal(MANTENIMIENTO mantenimiento, int posicion)
{
    ofstream principal("principal.dat", ios::app | ios::ate | ios::binary);
    if (posicion == 0)
    {
        cout << "Ingrese Apellido: " << endl;
        cin >> mantenimiento.apellido;
        cout << "Ingrese Nombre: " << endl;
        cin >> mantenimiento.nombre;
    }
    cout << "Ingrese Marca : " << endl;
    cin.ignore();
    cin.getline(mantenimiento.marca, 30);
    cout << "Ingrese Modelo: " << endl;
    cin >> mantenimiento.modelo;
    cout << "Ingrese Descripcion del Mantenimiento: " << endl;
    cin.ignore();
    cin.getline(mantenimiento.mantenimiento, 100);
    cout << "Ingrese Costo: " << endl;
    cin >> mantenimiento.costo;
    char opcion;

    do
    {
        cout << "Pago realizado? (S/N)?" << endl;
        cin >> opcion;

    } while ((toupper(opcion) != 'N') && (toupper(opcion) != 'S'));
    if (toupper(opcion == 'N'))
    {
        mantenimiento.pago = 0;
    }
    else
    {
        mantenimiento.pago = 1;
    }
    if (posicion > 0)
    { // si la posicion es maypr a 0, solo sobreescrivo el archivo principal
        principal.seekp(posicion - sizeof(mantenimiento));
    }
    else
    { // si la posicion es 0, agrego dni, posicion y genero el índice
        ofstream inx;
        int documento = 0;
        if (mantenimiento.documento % 2 == 0)
        {
            inx.open("indicepar.inx", ios::app | ios::ate | ios::binary);
            documento = 2;
        }
        else
        {
            inx.open("indiceinpar.inx", ios::app | ios::ate | ios::binary);
            documento = 1;
        }
        INDICE indice;
        indice.documento = mantenimiento.documento;
        indice.posicion = principal.tellp();
        if (inx.write((char *)&indice, sizeof(indice)))
        {
            cout << "escritura EXITOSA" << endl;
        }
        else
        {
            cout << " FAllIDO" << endl;
        }
        inx.close();
        genera_indice(documento);
    }
    principal.write((char *)&mantenimiento, sizeof(mantenimiento));
    principal.close();
}

void genera_indice(int documento)
{
    INDICE indice;
    INDICE indice_aux;
    fstream inx;
    if (documento == 1)
    {
        inx.open("indicepar.inx", ios::in | ios::out | ios::binary);
    }
    else
    {
        inx.open("indiceinpar.inx", ios::in | ios::out | ios::binary);
    }

    int i, j, elementos;
    inx.seekg(0, ios::end);
    elementos = inx.tellg() / sizeof(indice);

    for (i = 1; i < elementos; i++) // primer bucle piedra
    {
        for (j = 0; j < elementos - i; j++) // segundo bucle piedra
        {
            inx.seekg(j * sizeof(indice));                 // se posiciona el elemento nro j
            inx.read((char *)&indice_aux, sizeof(indice)); // guarda el elemento nro j en struct auxiliar
            inx.read((char *)&indice, sizeof(indice));     // lee el elemento nro j+1 y guarda en struct indice

            if (indice_aux.documento < indice.documento) // Compara claves, si el segundo elemento es mayor, invierte posiciones
            {
                inx.seekp(j * sizeof(indice)); // se posiciona el elemento nro j

                inx.write((char *)&indice, sizeof(indice));
                inx.write((char *)&indice_aux, sizeof(indice));
            }
        }
    }
    inx.close();
}

void buscar()
{
    system("cls");
    MANTENIMIENTO mantenimiento;
    cout << "Ingrese el documento a Buscar: ";
    cin >> mantenimiento.documento;
    int posicion = validar(mantenimiento); // guarda en posicion la posicion del DNI
    if (posicion > 0)
    { // si es mayor a cero, existe un registro con esa clave.
        ifstream DPrincipal;
        DPrincipal.open("principal.dat", ios::binary);
        DPrincipal.seekg(posicion - sizeof(mantenimiento));             // me posiciono en el elemento encontrado
        DPrincipal.read((char *)&mantenimiento, sizeof(mantenimiento)); // guardo elemnto en estruct
        cout << "DNI: " << mantenimiento.documento << endl;             // imprimo
        cout << "Apellido: " << mantenimiento.apellido << endl;
        cout << "Nombre: " << mantenimiento.nombre << endl;
        cout << "Marca: " << mantenimiento.marca << endl;
        cout << "Modelo: " << mantenimiento.modelo << endl;
        cout << "Costo: " << mantenimiento.costo << endl;

        if (mantenimiento.pago)
        {
            cout << endl
                 << "Pagado: SI" << endl;
        }
        else
        {
            cout << endl
                 << "Pagado: NO" << endl;
        }
        DPrincipal.close();
    }
    else
    {
        cout << endl
             << "No se encontro DNI buscado" << endl; // Si posicion es menor a 0, no existe elemento con ese DNI
    }
    system("pause");
}

void reporte()
{
    ifstream DPrincipal;
    DPrincipal.open("principal.dat", ios::binary);
    MANTENIMIENTO mantenimiento;
    system("cls");
    while (DPrincipal.read((char *)&mantenimiento, sizeof(mantenimiento)))
    {
        DPrincipal.read((char *)&mantenimiento, sizeof(mantenimiento));
        if (mantenimiento.pago == 0)
        {

            cout << "Documento: " << mantenimiento.documento << endl; // imprimo
            cout << "Apellido: " << mantenimiento.apellido << endl;
            cout << "Nombre: " << mantenimiento.nombre << endl;
            cout << "Marca: " << mantenimiento.marca << endl;
            cout << "Modelo: " << mantenimiento.modelo << endl;
            cout << "Costo: " << mantenimiento.costo << endl;
        }
    }
    DPrincipal.close();
    system("pause");
}

int salir()
{
    char opcion;

    do
    {
        cout << "Esta seguro que desea salir? (S/N)" << endl;
        cin >> opcion;

        if (toupper(opcion) == 'S')
        {
            cout << "Usted salio correctamente" << endl;
            break;
        }
        else if (toupper(opcion) == 'N')
        {
            system("cls");

            menu();
        }
    } while (toupper(opcion) != 'N');
    system("pause");
}