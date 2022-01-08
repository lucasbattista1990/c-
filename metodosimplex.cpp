// crear calculadora metodo simplex

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cout <<"*****************************************" << endl;
    cout <<"*                                       *" << endl;
    cout <<"*             CALCULADORA               *" << endl;
    cout <<"*            METODO SIMPLEX             *" << endl;
    cout <<"*                                       *" << endl;
    cout <<"*****************************************" << endl;
    cout <<"\n";
    int n;
    cout << "Ingrese el numero de variables: ";
    cin >> n;

    int m;
    cout << "Ingrese el numero de restricciones: ";
    cin >> m;

    int k;
    cout << "Ingrese el numero de funciones objetivo: ";
    cin >> k;

    vector<vector<double>> A(m, vector<double>(n + 1));
    vector<double> b(m);
    vector<double> c(n);
    vector<double> x(n);
    vector<double> z(k);


    cout << "Ingrese los valores de las restricciones: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
        cout << "b[" << i << "] = ";
        cin >> b[i];
    }

    cout << "Ingrese los valores de las funciones objetivo: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "c[" << i << "] = ";
        cin >> c[i];
    }

    cout << "Ingrese los valores de las variables: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    }

    cout << "Los valores ingresados son: " << endl;
    cout << "A: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "b: " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    cout << "c: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    cout << "x: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
    cout << "z: " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << z[i] << " ";
    }
    cout << endl;

    // maximizar
    double max = 0;
    for (int i = 0; i < k; i++)
    {
        if (z[i] > max)
        {
            max = z[i];
        }
    }

    cout << "El valor maximo de las funciones objetivo es: " << max << endl;

    // minimizar
    double min = 0;

    for (int i = 0; i < k; i++)
    {
        if (z[i] < min)
        {
            min = z[i];
        }
    }

    cout << "El valor minimo de las funciones objetivo es: " << min << endl;

    // calcular el valor de la funcion objetivo
    double f = 0;
    for (int i = 0; i < n; i++)
    {
        f = f + c[i] * x[i];
    }

    cout << "El valor de la funcion objetivo es: " << f << endl;

    return 0;
}
