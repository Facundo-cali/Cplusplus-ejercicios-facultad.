#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;
/* 
17. Se desea procesar la información contenida en el archivo “CENSO.TXT”.
A - Un listado ordenado de mayor a menor por cantidad de hectáreas cosechas en un año.
B - El rendimiento promedio obtenido por hectárea por cada productor
C - Generar un archivo “RENDIMIENTOS.TXT” con la información de los productores que hayan
obtenido rendimientos mayores al promedio */

int main(int argc, char const *argv[])
{
    ifstream archivo;
    ofstream archivo2;

    archivo.open("./CENSO.txt");
    archivo2.open("./RENDIMIENTOS.txt");

    if (archivo.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error
    float prod[999][3];
    float auxprod[999][3];
    int totH = 0;
    int cant = 0;
    int cod,hec,tone;
    while (!archivo.eof())
    {
        archivo >> cod;
        archivo >> hec;
        archivo >> tone;
        
        prod[cant][0] = cod;
        prod[cant][1] = hec;
        prod[cant][2] = tone;

        totH += hec;

        cant++;
    }
    
    for (int i=0; i < (cant-1); i++){
        for (int j=i+1; j<cant; j++){
            if (prod[i][1] < prod[j][1]){
                auxprod[i][0] = prod[i][0];
                auxprod[i][1] = prod[i][1];
                auxprod[i][2] = prod[i][2];
    
                prod[i][0] = prod[j][0];
                prod[i][1] = prod[j][1];
                prod[i][2] = prod[j][2];
    
                prod[j][0] = auxprod[i][0];
                prod[j][1] = auxprod[i][1];
                prod[j][2] = auxprod[i][2];
            }
        }
    }

    float promH; 
    float totProm = 0;
    float promProd;

    for (int i = 0; i < cant; i++)
    {
        promH = prod[i][2] / prod[i][1];
        for (int j = 0; j < 3; j++)
        {
            cout << prod[i][j] << " ";
        }
        cout << "Prom por hectarea: " << promH;
        totProm += promH;
        cout << endl;
    }
    
    promProd = totProm / cant;

    for (int i = 0; i < cant; i++)
    {
        promH = prod[i][2] / prod[i][1];
        if (promH > promProd)
        {
            archivo2 << prod[i][0] << " " << prod[i][1] << " " << prod[i][2] << endl;
        }
    }
    
    archivo2.close();
    archivo.close();

    return 0;
}