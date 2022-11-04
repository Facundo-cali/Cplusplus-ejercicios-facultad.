#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;
/* 12. En un triatlón participaron N competidores y por cada uno de ellos se tienen: el número de
competidor y los 3 pares de datos con la siguiente información:
 Código de Deporte (1= natación, 2=carrera, 3=bicicleta)
 Tiempo que hizo en ese deporte (en minutos)
Los pares de datos no vienen ordenados por código de deporte.
La cantidad N de participantes se ingresa como primer dato.
Se desea generar 3 archivos: NATACION.TXT, CARRETA.TXT y BICICLETA.TXT. Los archivos
tienen la misma estructura: Cod de competidor (0..N-1), espacio en blanco y Tiempo (en minutos).
Nota: Todos los competidores completaron las 3 pruebas */

int main(int argc, char const *argv[])
{

    ofstream archivo1;
    ofstream archivo2;
    ofstream archivo3;

    int n,cod;
    float tiempo;

    cout << "Ingresar cantidad de competidores: " << endl;
    cin >>n;

    archivo1.open("./NATACION.txt");
    archivo2.open("./CARRERA.txt");
    archivo3.open("./BICICLETA.txt");
    if (archivo1.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error
    if (archivo2.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error
    if (archivo3.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error
                            
    int anotados = 0;
    while (anotados != n)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "Ingresar codigo de deporte (1= natación, 2=carrera, 3=bicicleta): " << endl;
            cin >>cod;
            cout << "Ingresar tiempo en minutos: " << endl;
            cin >>tiempo;
            switch (cod){
            case 1:
                archivo1 << anotados << " " << tiempo << endl;
                break;
            case 2:
                archivo2 << anotados << " " << tiempo << endl;  
                break;
            case 3:
                archivo3 << anotados << " " << tiempo << endl;
                break;
            }
        }
        anotados++;
    }
    archivo1.close();
    archivo2.close();
    archivo3.close();

    return 0;
}
    


    
