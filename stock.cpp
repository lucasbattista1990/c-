
/*Gestión de Stock de productos
Se desea desarrollar un programa para gestionar un stock de productos.
 
De cada artículo se cuenta con la siguiente información: código (Alpha), Descripcion (Alpha), stock (Entero), PuntoReposicion (Entero)
 
El programa deberá permitir manejar los artículos desde un menú de aplicación.
 
Se deberán utiliza un archivo de índices que será generado a demanda por el usuario o bien cuando se agreguen 5 
artículos al archivo de productos.
 
Desarrollar un menú que permita: Alta Producto, Buscar Producto, Listar Reposición, Alta stock, Generar 
índice y Salir del programa según el usuario lo desee.
 
Opción Alta Producto: Registrar los datos del artículo y lo almacena en el archivo productos.dat. 
Debe validarse que NO exista el código de producto previamente.
 
Opción Buscar Producto: Mostrar por pantalla los datos del artículo ingresando su Código.
Opción Listar Reposición: Listar TODOS los productos cuyo que alcancen el punto de reposición (stock <= PuntoReposición).
 
Opción Alta Stock: Permitir el ingreso de productos al Stock solicitando el Código de producto y la cantidad a ingresar. 
Mostrar los datos del producto con el stock actualizado. Se deberá validar la existencia del Producto.  
 
Opción Generar Índice: se deberá regenerar el índice de artículos.
	
Opción Salir: consultar al usuario si está seguro de querer finalizar el programa.
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace  std;

void AltaProducto();
void BuscarProducto();
void ListarRepo();
void AltaStock();
void GenerarIndice();
bool ValidarArticulo(struct Producto);         //True/False --> Existe el producto

void ListarIndice();
void ListarDatos();

struct Producto
{
    char codigo[10];
    char descripcion[50];
    int stock;
    int PuntoRepo;

};

struct Indice
{
    char codigo[10];
    int posicion;
};

int cantAltas = 0;


int main()
{


int opcion=-1;


do
{
    cout << endl;
    cout << "Ingrese la opcion del Menu" << endl;
    cout << "1 Alta Producto" << endl;
    cout << "2 Buscar" << endl;
    cout << "3 Listar Repo" << endl;
    cout << "4 Alta Stock" << endl;
    cout << "5 Generar Indice" << endl;
    cout << "7 Listar Indice" << endl;
    cout << "8 Listar Datos" << endl;
    cout << "6 Salir" ;

    

    cin >> opcion;


    switch (opcion)
    {
    case 1:            //alta producto
        AltaProducto();
        break;

    case 2:         //buscar
        BuscarProducto();
        break;

    case 3:         //Repo
            ListarRepo();
            break;


    case 4:     // alta stock
            AltaStock();
            break;

    case 5:      //Generar Indice
            GenerarIndice();
            break   ;

    case 6:         //SALIR
            break;

     case 7:         //SALIR
            ListarIndice();
            break;


     case 8:         //SALIR
            ListarDatos();
            break;

    default:
        cout << "Opcion invalida" << endl;
        break;
    }

} while (opcion!=6);

}

void AltaProducto()
{
    struct Producto articulo;
    cout << endl << "Ingrese codigo" ;
    cin >> articulo.codigo;

    //VALIDO EXISTENCIA DEL CODIGO

    if (ValidarArticulo( articulo  ))
    {
        cout << endl;  "El codigo ingresado YA existe" ;
    }
    else
    {
        cout << endl << "Ingrese Descripcion" ;
        cin >> articulo.descripcion;

        cout << endl << "Ingrese Stock" ;
        cin >> articulo.stock;

        cout << endl << "Ingrese P. Repo" ;
        cin >> articulo.PuntoRepo;

        ofstream AProductos;
        AProductos.open("Productos.dat", ios::binary | ios::app | ios::ate);

        //GENERA DATOS DEL INDICE
        struct Indice inx;
        strcpy(inx.codigo,articulo.codigo);
        

        //GUARDO DATOS
        AProductos.write((char*) &articulo, sizeof(articulo));
        inx.posicion = AProductos.tellp() ;
        inx.posicion = inx.posicion - sizeof(articulo);
        AProductos.close();

        //GUARDO INDICE
        ofstream IProductos;
        IProductos.open("Productos.inx", ios::binary | ios:: app | ios::ate);
        IProductos.write((char*) &inx, sizeof(inx));
        IProductos.close();


        //incremento contador de altas
        cantAltas++;

        if (cantAltas >= 5)
        {
            //GENERAR INDICE
            GenerarIndice();        //LLamo a la funcion encargada de generar indice
            //reiniciar contador
            cantAltas=0;

        }

    }

}

bool ValidarArticulo(struct Producto prod)
{
    //VALIDAR CONTRA ARCHIVO DE INDICE --> OPTIMO
    struct Indice inx;
    ifstream IProductos;
    IProductos.open("Productos.inx", ios::binary);

    while (IProductos.read((char*) &inx, sizeof(inx) ))
    {
        if ( strcmp(inx.codigo, prod.codigo)==0)
        {
            IProductos.close();
            return true;
        }
    }
    IProductos.close();
    return false;
}

void BuscarProducto()
{
    char codigoBuscado[10];
    cout <<endl <<"Ingrese el codigo de producto a buscar:";
    cin >> codigoBuscado;

    //BUSCAR EN EL INDICE
    ifstream IProducto;
    IProducto.open("Productos.inx", ios::binary);

    struct Indice inx;
    struct Producto articulo;

    //*************** BUSQUEDA BINARIA  ***********

        //Buscar clave o dato deseado. 
        int n;
        int medio;
        int inicio = 0;
        int fin = (sizeof(IProducto)/sizeof(Producto)) - 1;        //n : cantidad de elementos
        int encontrado = 0;
        while (inicio <= fin)
        {
            //Medio será igual a la mitad de la dimensión delarreglo.
            medio = (fin + inicio) / 2;
            

            //POSICIONO EN EL MEDIO DEL ARCHIVO
            IProducto.seekg(medio * sizeof(Producto));
            IProducto.read((char*) &inx, sizeof(inx));

            //Si variable medio es similar a la clave de búsqueda despliega mensaje de encontrado.
            if (strcmp(inx.codigo,codigoBuscado) ==0)
            {
                //MOSTAR DATOS DEL PRODUCTO
                ifstream AProductos;
                AProductos.open("Productos.dat", ios::binary);
                AProductos.seekg(inx.posicion);
                AProductos.read((char*) &articulo , sizeof(Producto));

                cout << endl << "Codigo:" << articulo.codigo;
                cout << endl << "Descrip:" << articulo.descripcion;
                cout << endl << "Stock:" << articulo.stock;
                cout << endl << "PRepo:" << articulo.PuntoRepo;
                cout << endl;

                AProductos.close();

                encontrado = 1;
                fin = -1;
            }
            //De lo contrario verifica si la posición del valor medio actual 
            //es menor que la clave de  búsqueda. 
            else
            {
                if ( strcmp(codigoBuscado,inx.codigo)==-1)
                    fin = medio - 1;
                else 
                    inicio = medio + 1;
            }
        }
        //Si no se encontró la clave despliega el mensaje de noencontrado. 
        if (encontrado != 1)
            cout<< "No se encontro el codigo buscado" << endl;


    //*********************************************



    IProducto.close();
}

void ListarRepo()
{

    struct Producto articulo;

    ifstream AProductos;
    AProductos.open("Productos.dat", ios::binary);

    while (AProductos.read((char*) &articulo, sizeof(articulo)))
    {
        if (articulo.stock <= articulo.PuntoRepo)
        {
                cout << endl << "Codigo:" << articulo.codigo;
                cout << endl << "Descrip:" << articulo.descripcion;
                cout << endl << "Stock:" << articulo.stock;
                cout << endl << "PRepo:" << articulo.PuntoRepo;
        }
    }
    AProductos.close();

}

void AltaStock()
{

    // SOLICITAR PRODUCTO + CANTIDAD
    // VALIRDAR PRODUCTO
    struct Producto articulo;

    cout << endl << "Ingrese codigo producto:";
    cin >> articulo.codigo;

    if (ValidarArticulo(articulo))
    {
        cout << endl << "ingrese la cantidad:";
        cin >> articulo.stock ;      //Utilizo el miembro para guardar la nueva cantidad a agregar

        ofstream AProductos;
        ifstream IProductos;
        //BUSCAR PRODUCTO
          //BUSCAR EN EL INDICE
    ifstream IProducto;
    IProducto.open("Productos.inx", ios::binary);

    struct Indice inx;
    struct Producto articulo;
    struct Producto articuloOriginal;

    //*************** BUSQUEDA BINARIA  ***********

        //Buscar clave o dato deseado. 
        int n;
        int medio;
        int inicio = 0;
        int fin = (sizeof(IProducto)/sizeof(Producto)) - 1;        //n : cantidad de elementos
        int encontrado = 0;
        while (inicio <= fin)
        {
            //Medio será igual a la mitad de la dimensión delarreglo.
            medio = (fin + inicio) / 2;
            

            //POSICIONO EN EL MEDIO DEL ARCHIVO
            IProducto.seekg(medio * sizeof(Producto));
            IProducto.read((char*) &inx, sizeof(inx));

            //Si variable medio es similar a la clave de búsqueda despliega mensaje de encontrado.
            if (strcmp(inx.codigo,articulo.codigo) ==0)
            {
                //LEO DATOS ACTUALES    
                ifstream AProductosLee;
                AProductosLee.open("Productos.dat", ios::binary);
                AProductosLee.seekg(inx.posicion);
                AProductosLee.read((char*) &articuloOriginal, sizeof(articulo));

                strcpy(articulo.descripcion, articuloOriginal.descripcion);
                articulo.stock = articulo.stock + articuloOriginal.stock;
                articulo.PuntoRepo = articuloOriginal.PuntoRepo;


                //ACTUALIZA CANTIDAD
                ofstream AProductosAct;
                AProductos.open("Productos.dat", ios::binary | ios::app | ios::ate);
                AProductos.seekp(inx.posicion);
                AProductos.write((char*) &articulo, sizeof(articulo) );
                AProductos.close();

                encontrado = 1;
                fin = -1;
            }
            //De lo contrario verifica si la posición del valor medio actual 
            //es menor que la clave de  búsqueda. 
            else
            {
                if ( strcmp(articulo.codigo,inx.codigo)==-1)
                    fin = medio - 1;
                else 
                    inicio = medio + 1;
            }
        }
        //Si no se encontró la clave despliega el mensaje de noencontrado. 
        if (encontrado != 1)
            cout<< "No se encontro el codigo buscado" << endl;


    //*********************************************



    IProducto.close();
        //ACTUALIZAR STOCK


    }
    else
    {
        cout << endl <<" el codigo ingresado es inexistente";
    }
    

}

void GenerarIndice()
{
    struct Indice inx;
    struct Indice aux;
    
    //ORDENAR INDICE


        fstream IProductos;
        IProductos.open("Productos.inx", ios::in | ios::out |  ios::binary | ios::app | ios::ate);


        //******** BURBUJA  *******
            int i,j;                //Variables contadoras del ciclo.
            int ielementos= IProductos.tellg()  /sizeof(Indice);

            cout << endl << sizeof(Indice) << " " << IProductos.tellg() << " ** " << ielementos;

            for (i=1;i<ielementos;i++)
            {
                for (j=0; j < ielementos-i ;j++) // for(j=0; j < Nelementos-i; j++) es menor y no menor igual
                {

                    cout <<endl << j*sizeof(Indice);

                    IProductos.seekg(j*sizeof(Indice));
                    IProductos.read((char*) &aux, sizeof(Indice));
                    IProductos.read((char*) &inx, sizeof(Indice));

                    if (strcmp( aux.codigo , inx.codigo) == -1)//Condicion mayor-menor
                    {
                        IProductos.seekp(j*sizeof(Indice));

                        IProductos.write((char*) &inx, sizeof(Indice));
                        IProductos.write((char*) &aux, sizeof(Indice) );
                    }
                }
            }


        //*************************

        IProductos.close();

}




void ListarIndice()
{
    ifstream IProducto;
    IProducto.open("Productos.inx", ios::binary);

    struct Indice inx;
    while (IProducto.read((char*) &inx, sizeof(inx)))
    {
        cout << endl << inx.codigo << " " << inx.posicion;
    }
    
    IProducto.close();
}

void ListarDatos()
{
 ifstream IProducto;
    IProducto.open("Productos.dat", ios::binary);

    struct Producto art;
    while (IProducto.read((char*) &art, sizeof(art)))
    {
        cout << endl << art.codigo << " " << art.descripcion << " " << art.stock << " " << art.PuntoRepo;
    }

    IProducto.close();
    
}


/*
void InsertarIndice()
{

    //buscar posicion anterior
    //generar espacio
    //cargar nuevo valor en el espacio generado

}
*/