#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

/* 5. Se necesita generar un archivo con los nombres de las 24 provincias. De acuerdo al orden de
ingreso se les asigna un código (entre 0 y 23).
En el archivo PROVINCIAS.TXT se almacena, por renglón, código y nombre separados por espacio
en blanco. */


int main(int argc, char const *argv[])
{
    ofstream archivo;
    string prov;
    archivo.open("./guia8_5.txt");

    if (archivo.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error


    for (int i = 0; i < 24; i++)
    {
        cout << "Ingresar nombre de provincia: " << endl;
        getline(cin,prov);
        archivo << i << " " << prov << endl;
    }

    archivo.close();//cerramos archivo

    return 0;
}