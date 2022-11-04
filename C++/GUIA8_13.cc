#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;
/* 
13. Se desea a partir de los archivos NATACION.TXT, CARRETA.TXT y BICICLETA.TXT obtener el
código del participante ganador del triatlón (participante que realizó menor tiempo). */

int main(int argc, char const *argv[])
{

    ifstream archivo1;
    ifstream archivo2;
    ifstream archivo3;

    archivo1.open("./NATACION.txt");
    archivo2.open("./CARRERA.txt");
    archivo3.open("./BICICLETA.txt");

    int compet[999][2];//[0-codigo][1-tiempo total]
    int menorTiempo = 9999;
    int codMenorTiempo;

    for (int i = 0; i < 999; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            compet[i][j] = 0;
        }
    }
    
    int nroCompet = 0;
    int codigo,tiempo;
    while (!archivo1.eof())
    {
        archivo1 >> codigo;
        archivo1 >> tiempo;
        compet[nroCompet][0] = codigo;
        compet[nroCompet][1] += tiempo;

        nroCompet++;
    }

    nroCompet = 0;
    while (!archivo2.eof())
    {
        archivo2 >> codigo;
        archivo2 >> tiempo;
        compet[nroCompet][0] = codigo;
        compet[nroCompet][1] += tiempo;

        nroCompet++;
    }
    nroCompet = 0;

    while (!archivo3.eof())
    {
        archivo3 >> codigo;
        archivo3 >> tiempo;
        compet[nroCompet][0] = codigo;
        compet[nroCompet][1] += tiempo;

        nroCompet++;
    }

    for (int i = 0; i < nroCompet; i++)
    {
        if (compet[i][1] < menorTiempo)
        {
            menorTiempo = compet[i][1];
            codMenorTiempo = compet[i][0];
        }
    }
    
    cout << "GANADOR CODIGO: " << codMenorTiempo << " CON TIEMPO: " << menorTiempo << endl;


    return 0;
}