#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;
/* 10. Se desea realizar un informe ordenado por el sueldo a percibir por cada empleado de mayor a
menor con la información existente en el archivo SUELDOS.TXT. */

int main(int argc, char const *argv[])
{

    ifstream archivo;//creamos el archivo de lectura
    archivo.open("./SUELDOS.txt");//lo abrimos


    if (archivo.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error

    int mat[999][2];// [0-cod][1-sueldo]
    int matAux[999][2];// [0-cod][1-sueldo]

    for (int i = 0; i < 999; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matAux[i][j] = 0;
            mat[i][j] = 0;
        }
    }
    
    
    int cont = 0;

    while (!archivo.eof())
    {
        archivo >> mat[cont][0];//Lee desde el archivo
        archivo >> mat[cont][1];
        cont++;
    }
    
    

    for (int i=0; i < (cont-1); i++){
        for (int j=i+1; j<cont; j++){
            if (mat[i][1] < mat[j][1]){
                matAux[i][0] = mat[i][0];
                matAux[i][1] = mat[i][1];
    
                mat[i][0] = mat[j][0];
                mat[i][1] = mat[j][1];
    
                mat[j][0] = matAux[i][0];
                mat[j][1] = matAux[i][1];
            }
        }
    }

    for (int i = 0; i < cont - 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    archivo.close();//cerramos archivo


    return 0;
}