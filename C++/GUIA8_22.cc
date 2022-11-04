#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

/* 22. Se dispone del archivo EMPLEADOS.CSV. Se requiere:
a) Verificar que la información guardada de cuil sea la correcta. Se sabe que el cuil esta formado por
PP-DDDDDDDD-V, donde PP es un prefijo que vale 20 si el sexo es ‘M’ y 27 si el sexo es ‘F’;
DDDDDDDD es el documento y V es un dígito verificador. Informar por pantalla, el cuil incorrecto.
b) Informar los sueldos promedio de mujeres y varones.  */

/* 
21423545;f;3423;22265346324
43114238;f;3534;27226222211
47647443;m;8786;21522272211
47647442;m;1386;21222252211
47647441;m;5786;20223222211
47647442;f;9786;27221227211 
*/

int main(int argc, char const *argv[])
{

    ifstream archivo;
    archivo.open("./EMPLEADOS.txt");

    if (archivo.fail()){
        cout << "Error!" << endl;
        exit(1);
    }
    long dni;
    string sexo;
    long suel;
    string cuil;
    int cant=0;
    int suelVarones = 0;
    int suelMujeres = 0;
    int cantM = 0;
    int cantV = 0;
    string mat[999][1];
    archivo >> dni;
    while (!archivo.eof())
    {
        archivo.ignore();
        getline(archivo,sexo,';');
        archivo >> suel;
        archivo.ignore();
        getline(archivo,cuil);
        if (sexo == "m")
        {
            suelVarones += suel;
            cantV++;
        }
        if (sexo == "f")
        {
            suelMujeres += suel;
            cantM++;
        }
        
        if (sexo == "f" && cuil.substr(0,2) != "27") // .find devuelve -1 cuando no se encuentra
        {
            cout << "CUIL INCORRECTO: "<< cuil << endl;
        }
        if (sexo == "m" && cuil.substr(0,2) != "20") // .find devuelve -1 cuando no se encuentra
        {
            cout << "CUIL INCORRECTO: "<< cuil << endl;
        }
        cant++;
        archivo >> dni;
    }

    cout << "Sueldo promedio hombres: "<< suelVarones / cantV << endl;
    cout << "Sueldo promedio mujeres: "<< suelMujeres / cantM << endl;

    archivo.close();
    return 0;
}