/*determinar el diametro de la tuberia necesaria para transportar agua a una velocidad de 5 m/s, 
sabiendo que la presion de descarga debe manterse en 160 kPa y que la presion de suministro es de 240 kPa.
La longitud de la tuberia es de 250 m. considere un flujo laminar.
Calcular el diametro de la tuberia necesario, para que la presion de descarga se mantenga en 160 kpa.

se utiliza la 1ª ecuación de Karmann-Prandtl
*/


#include <iostream>
#include <math.h>


using namespace std;


int main()
{
    double presion_descarga = 160;
    double presion_suministro = 240;
    double longitud = 250;
    double velocidad = 5;
    double diametro;
    double reynolds;
    double friccion;
    double coeficiente_friccion;
    

    reynolds = presion_suministro * longitud / velocidad;
    friccion = 0.074 * pow(reynolds, 0.2);
    coeficiente_friccion = friccion / presion_descarga;
    diametro = pow(coeficiente_friccion, 2) * longitud / (8 * M_PI);

    cout << "el diametro de la tuberia es: " << diametro << endl;
    cout << "el reynolds es: " << reynolds << endl;
    cout << "la friccion es: " << friccion << endl;
    cout << "el coeficiente de friccion es: " << coeficiente_friccion << endl;
    

    return 0;
}