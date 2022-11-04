#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

/* 19. Se dispone de los 12 archivos mensuales de los proveedores de la empresa textil. Informar el
total anual que proveyó por cada tipo de lana cada uno de los criaderos.
Tip: Use concatenación de string para formar el nombre del archivo. */

int main(int argc, char const *argv[])
{
    ifstream archivo;

    for (int i = 1; i < 5; i++)
    {
        archivo.open("./PROVEEDORES_" + to_string(i) + ".txt");

        if (archivo.fail()){
            cout << "Error!" << endl;
            exit(1);
        }//preguntamos por error
        string cod;
        string lana1;
        string lana2;
        string lana3;
        int vec[3]; // [0 lana 1]  [1 lana 2] [2 lana 3];
        for (int i = 0; i < 3; i++)
        {
            vec[i] = 0;
        }
        while (!archivo.eof())
        {
            getline(archivo,cod, '|');
            getline(archivo,lana1, '|');
            getline(archivo,lana2, '|');
            getline(archivo,lana3);
            int l1 = stoi(lana1);
            int l2 = stoi(lana2);
            int l3 = stoi(lana3);
            vec[0] += l1;
            vec[1] += l2;
            vec[2] += l3;
        }
        cout << "Proveedor " << i << ":" << endl;
        cout << "Total lana 1: " << vec[0] << " " <<endl;
        cout << "Total lana 2: " << vec[1] << " "<<endl;
        cout << "Total lana 3: " << vec[2] << " "<<endl;
        cout << endl <<endl;
        
        archivo.close();
    }

    return 0;
}