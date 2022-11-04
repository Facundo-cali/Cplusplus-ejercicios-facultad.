#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
/* 7. Se desea llenar una matriz de N x M con números al azar menores a 1000. Los valores de N y M
se ingresan como primeros datos. Luego generar un archivo MATRIZ.TXT donde se guarde: N, M,
luego los valores de cada una de las celdas recorriendo la matriz por filas y columnas. Por último la
suma de todos los valores. Todos los valores se escriben separados por espacios en blanco */

int main(int argc, char const *argv[])
{
    ofstream archivo;
    archivo.open("./MATRIZ.txt");

    int n,m,sumaTotal;
    srand(time(NULL));
    
    cout << "Ingresar valor n: " << endl;
    cin >>n;
    cout << "Ingresar valor m:" << endl;
    cin >>m;

    int matriz[n][m];

   
    if (archivo.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error
    
    archivo << n << " " << m << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matriz[i][j] = rand() % 1000;
            sumaTotal += matriz[i][j];
            archivo << matriz[i][j] << " ";
        }
        archivo << endl;
    }
    archivo << sumaTotal;
    archivo.close();


    return 0;
}