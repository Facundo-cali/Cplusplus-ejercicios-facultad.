#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

/* 9. Una empresa posee N empleados y de cada uno de ellos los siguientes datos: Código de
empleado (numérico), cantidad de horas normales trabajadas, cantidad de horas extras trabajadas.
La cantidad de empleados y el valor de la hora normal de trabajo se leen como primeros datos
Se pide:
- Generar un archivo SUELDOS.TXT donde figure Cod de empleado, sueldo a cobrar.
Tenga en cuenta que las horas extras se pagan el doble que las horas normales de trabajo.
 */
int main(int argc, char const *argv[])
{
    int n,valorHora;
    int codEmpleado,horasT,horasEx;

    ofstream archivo;//creamos el archivo de escritura
    archivo.open("./SUELDOS.txt");//lo abrimos

    if (archivo.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error
    

    cout << "Ingresar cantidad de empleados: " << endl;
    cin >>n;
    cout << "Ingresar valor de la hora normal de trabajo: " << endl;
    cin >>valorHora;

    for (int i = 0; i < n; i++)
    {
        cout << "Ingresar codigo de empleado: " << endl;
        cin >> codEmpleado;
        cout << "Ingresar cantidad de horas normales trabajadas: " << endl;
        cin >>horasT;
        cout << "Ingresar cantidad de horas extras trabajadas:" << endl;
        cin >>horasEx;
        archivo << codEmpleado << " " << (horasT * valorHora) + (horasEx * (valorHora*2)) << endl;//ingresamos cosas en el archivo
    }
    

    
    archivo.close();//cerramos archivo


    return 0;
}