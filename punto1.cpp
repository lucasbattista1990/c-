/*Ejercicio 1: 
Listar los datos de los alumnos (Numero de libreta, código de materia y nota obtenida)
Sacar el promedio final (todas las notas de todos los alumnos) y el total de alumnos

*/
#include <stdio.h>
#include <iostream>


using namespace std;




int main(){
    int legajo;
    char variable;
    float valor = 245.234532;


    cout<<"Hola mundo"<<endl; 
    
    

    cout.precision(3);
    cout<< fixed << valor <<endl;
    
    cout<<"ingrese su numero de legajo: \n"; cin>>legajo;


    cout<<"el legajo es: "<<endl;

    cout.fill  ('0');    
    cout.width ( 10 );
    cout << legajo;
    cout<< "\ningrese una letra\n";  cin>>variable;
    cout<< "\nLa letra es"<< endl;
    cout.fill  (' ');    
    cout.width ( 20 );
    cout << variable;

   
    return 0;
}

