#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

/* 14. Se desea generar un archivo con la información de los alumnos de Fundamentos de
Programación. Para ello se ingresa por cada alumno: documento, apellido y nombre, nota del primer
parcial, nota del segundo parcial. El ingreso se realiza sin ningún tipo de orden. Un nro de
documento igual a 0 indica el fin de datos. La información en el archivo “FUPRO_2.TXT” se quiere
guardar ordenada por nro de documento. En el archivo se guardará nro de documento y apellido y
nombre en un renglón, y las notas de los parciales en otro.
Obs: Si un alumno no rindió un parcial, se ingresó un 0 como nota. */


int main(int argc, char const *argv[])
{
    ofstream archivo1;
    

    archivo1.open("./FUPRO_2.txt");
    

    if (archivo1.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error
    int dni,nota1,nota2;
    string nya;
    int i = 0;
    int alum[999][3]; //[0 - nroDoc] [1 - nota primer] [ 2 - nota seg]
    string alumNom[999]; // nom alum
    int auxAlum[999][3]; //[0 - nroDoc] [1 - nota primer] [ 2 - nota seg]
    string auxAlumNom[999]; // nom alum
    cout << "Ingresar numero de documento: " << endl;
    cin >>dni;
    while (dni != 0)
    {
        cout << "Ingresar apellido y nombre: " << endl;
        cin.ignore();
        getline(cin,nya);
        cout << "Ingresar nota primer parcial: " << endl;
        cin >> nota1;
        cout << "Ingresar nota segundo parcial: " << endl;
        cin >> nota2;
        alum[i][0] = dni;
        alum[i][1] = nota1;
        alum[i][2] = nota2;
        alumNom[i] = nya;
        i++;
        cout << "Ingresar numero de documento: " << endl;
        cin >>dni;
    }

    for (int t=0; t < (i-1); t++){
        for (int j=t+1; j<i; j++){
            if (alum[t][0] < alum[j][0]){
                auxAlum[t][0] = alum[t][0];
                auxAlum[t][1] = alum[t][1];
                auxAlum[t][2] = alum[t][2];
                auxAlumNom[t] =  alumNom[t];
    
                alum[t][0] = alum[j][0];
                alum[t][1] = alum[j][1];
                alum[t][2] = alum[j][2];
                alumNom[t] =  alumNom[j];
    
                alum[j][0] = auxAlum[t][0];
                alum[j][1] = auxAlum[t][1];
                alum[j][2] = auxAlum[t][2];
                alumNom[j] =  auxAlumNom[t];
            }
        }
    }

    for (int y = 0; y < i; y++)
    {
        archivo1 << alum[y][0] << " " << alumNom[y] << endl;
        archivo1 << alum[y][1] << " " << alum[y][2] << endl; 
    }
    

    archivo1.close();//cerramos archivo
    
    



    


    
   
    return 0;
}

