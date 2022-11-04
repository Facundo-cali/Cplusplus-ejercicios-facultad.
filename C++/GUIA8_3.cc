#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

/* 3. Se necesita generar un archivo con la cantidad de detenciones de los integrantes de las barras
bravas de un club. El archivo debe contener la información: apodo y la cantidad de veces que estuvo
detenido.
El final de datos se determina con apodo igual a ‘ZZZ’.
Nombre al archivo “BARRAS.TXT”.
En el archivo se almacena, por renglón, apodo y cantidad de detenciones separados por ‘|’. */

int main(int argc, char const *argv[])
{
    int cant;
    string apodo;

    ofstream archivo;//creamos el archivo de escritura
    archivo.open("./guia8_3.txt");//lo abrimos
    if (archivo.fail()){
        cout << "Error!" << endl;
        exit(1);
    }
    cout << "Ingresar apodo: " << endl;
    getline(cin,apodo);
    while (apodo != "zzz")
    {
        cout << "Ingresar cantidad de veces detenido: " << endl;
        cin >>cant;
        archivo << apodo << " | " << cant << endl;
        cout << "Ingresar apodo: " << endl;
        cin.ignore();
        getline(cin,apodo);
    }
    
    archivo.close();//cerramos archivo

    return 0;
}