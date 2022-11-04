#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

/* 8. Se desea procesar el archivo MATRIZ.TXT. Mostrar la matriz de N filas x M columnas. Verificar
que el archivo no esté modificado validando que la suma de los elementos coincida con el último
dato leído */

int main(int argc, char const *argv[])
{

    ifstream archivo;
    archivo.open("./MATRIZ.txt");
    int suma;

    if (archivo.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error
    
    
    int nn;
    archivo >> nn;
    int mm;
    archivo >> mm;

    int matriz[nn][mm];
    while (!archivo.eof())
    {
        for (int i = 0; i < nn; i++)
        {
            for (int j = 0; j < mm; j++)
            {
                archivo >> matriz[i][j];
            }
        }
        archivo >> suma;
    }

    for (int i = 0; i < nn; i++)
    {
        for (int j = 0; j < mm; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << suma << endl;

    archivo.close();

    return 0;
}