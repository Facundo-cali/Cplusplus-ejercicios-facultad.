#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

/* 16. En un censo agropecuario se ha obtenido información sobre la producción agrícola de distintos
productores.
Entre otros datos se han registrado los siguientes: Código de productor, Cantidad de hectáreas
sembradas en un año, Total de Toneladas cosechadas en un año.
La cantidad de productores censados se lee como primer dato.
Genere un archivo “CENSO.TXT” con la información ingresada, La información de cada productor se
guarda en un mismo renglón, separada por espacios. */

int main(int argc, char const *argv[])
{
    ofstream archivo;//creamos el archivo de escritura
    archivo.open("./CENSO.txt");//lo abrimos

    if (archivo.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error

    int n;
    cout << "Ingresar cantidad de productores censados: " << endl;
    cin >>n;
    int cod;
    float cantH,cantT;
    for (int i = 0; i < n; i++)
    {
        cout << "Ingresar codigo de productor: " << endl;
        cin >>cod;
        cout << "Ingresar cantidad de hectareas sembradas en un año: " << endl;
        cin >>cantH;
        cout << "Ingresar cantidad de toneladas cosechadas en un año: " << endl;
        cin >>cantT;
        archivo << cod << " " << cantH << " " << cantT << endl;
    }
    

    archivo.close();//cerramos archivo


    return 0;
}