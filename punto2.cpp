#include <iostream>
#include <string.h>


using namespace std;

int main(){
    int numero;
    char letra,oracion[100];


    cout<<"ingrese un numero: \n";
    cin>>numero;
    cout<<"su numero es: "<<numero<<endl<<endl;

    cout<<"ingrese una letra: \n";
    cin>>letra;
    cout<<"su letra es : "<<letra<<endl<<endl;
    cout<<"escriba una frase: "<<endl;
    cin.ignore();
    cin.getline(oracion,100);
    cout<<"su frase es: \n"<<oracion<<endl<<endl;
    

    return 0;
}
