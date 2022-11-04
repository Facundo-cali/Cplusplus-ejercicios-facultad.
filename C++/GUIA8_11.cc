#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

/* 11. Se dispone del archivo PRODUCTOS_EN_DOLARES.TXT que tiene la información: cod de
producto, descripción y precio en dólares (provisto por la cátedra). Cada uno de los datos se
encuentra en un renglón (los datos de 1 producto ocupan 3 renglones).
Se solicita generar un archivo PRODUCTOS_EN_PESOS.TXT, que posea la misma estructura que
el archivo anterior pero con el precio transformado a pesos.
La cotización del dólar se ingresa al principio. */

int main(int argc, char const *argv[])
{

    ifstream archivo1;
    ofstream archivo2;

    archivo1.open("./PRODUCTOS_EN_DOLARES.txt");
    archivo2.open("./PRODUCTOS_EN_PESOS.txt");
    if (archivo2.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error
    if (archivo1.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error
    int coti,cod,precio;
    string des;
    cout << "Ingresar cotizacion del dolar en pesos: " << endl;
    cin >>coti;

    while (!archivo1.eof())
    {
        archivo1 >> cod;
        archivo1 >> des;
        archivo1 >> precio;
        archivo2 << cod << endl;
        archivo2 << des << endl;
        archivo2 << precio * coti << endl;
    }

    archivo1.close();
    archivo2.close();



    return 0;
}