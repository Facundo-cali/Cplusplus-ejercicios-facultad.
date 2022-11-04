#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

/* 21. Se dispone de la información de un grupo de empleados de una empresa. Se desea generar un
archivo de texto que contenga: dni ; sexo (‘M’ o ‘F’) ; sueldo ; cuil. Los datos se ingresan sin orden.
Un DNI igual a 0 indica el fin de datos.
El archivo se debe llamar EMPLEADOS.CSV. La información de cada empleado se graba en un
mismo renglón, separado por */
int main(int argc, char const *argv[])
{

    ofstream archivo;
    archivo.open("./EMPLEADOS.csv");
    
    if (archivo.fail()){
        cout << "Error!" << endl;
        exit(1);
    }
    long long dni,cuil;
    int sueldo;
    char sex;
    cout << "Ingresar dni: " << endl;
    cin >>dni;
    while (dni != 0)
    {
        cout << "Ingresar sexo (m o f): " << endl;
        cin >>sex;
        cout << "Ingresar sueldo: " << endl;
        cin >>sueldo;
        cout << "Ingresar cuil: " << endl;
        cin >>cuil;

        archivo<<dni<<";"<<sex<<";"<<sueldo<<";"<<cuil<<endl; 
        cout << "Ingresar dni: " << endl;
        cin >>dni;
    }
    
    archivo.close();

    return 0;
}