#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

/* 2. Tome el archivo generado en el ejercicio anterior, páselo a una matriz de 2 columnas y ordene la
matriz por la columna donde estén los valores de y.
Utilice un función para ordenar la matriz; */

int main(int argc, char const *argv[])
{
   
    ifstream archivo;//creamos el archivo de lectura
    long matriz[1000][2]; // [0 - x] [1 - y]



    archivo.open("./guia8_1.txt",ios::in);//lo abrimos en modo lectura\

    if (archivo.fail()){
        cout << "Error!" << endl;
        exit(1);
    }

    //llenamos la matriz
    for(int f = 0; f < 1000; f++ ){
        for( int c=0; c<2; c++ ){
            archivo >> matriz[f][c];
        }
    }

    //mostramos
    for(int f = 0; f<1000; f++ ){
        for( int c=0; c<2; c++ ){
            cout << matriz[f][c] << ' ';
        }
        cout << endl;
    }
    
    archivo.close();//cerramos archivo

    return 0;
}

