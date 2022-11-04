#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

/* 15. Se desea generar un archivo “FUPRO_3.TXT”, actualizando la información del archivo
“FUPRO_2.TXT” luego de rendido el tercer parcial. Por cada alumno que rindió el parcial se ingresa:
nro de documento y nota. Un nro de documento igual a 0 indica el fin de datos. La carga de datos
se realiza sin orden. En el archivo se guardará nro de documento y apellido y nombre en un renglón,
y las notas de los tres parciales en otro.
Realizar una función llamada busqueda_binaria para encontrar el registro correspondiente al
documento ingresado. */

void busqueda_binaria(int alum[][4],int dniBus,int i, string alumNom[]);

int main(int argc, char const *argv[])
{

    ifstream archivo1;
    ofstream archivo2;

    archivo1.open("./FUPRO_2.txt");
    archivo2.open("./FUPRO_3.txt");

    if (archivo1.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error
    if (archivo2.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error

    string nya;
    int i = 0;
    int dni,nota1,nota2,nota3,dniBus;
    int alum[999][4]; //[0 - nroDoc] [1-nota primer] [2 - nota seg] [3 - nota seg]
    string alumNom[999]; // nom alum
    for (int i = 0; i < 999; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            alum[i][j]=0;
        }
        
    }
    
    while (!archivo1.eof())
    {
        archivo1 >> dni;
        getline(archivo1,nya);
        archivo1 >> nota1;
        archivo1 >> nota2;

        alum[i][0] = dni;
        alum[i][1] = nota1;
        alum[i][2] = nota2;
        alumNom[i] = nya;

        i++;
    }

    int band=0, pos;
    cout << "Ingresar dni a buscar: " << endl;
    cin >>dniBus;
    while (dniBus != 0){
        cout << "Ingresar nota 3: " << endl;
        cin >> nota3;
        int j=0; 
        while (j < i){
            if (alum[j][0] == dniBus){
                band=1;
                pos=j;
                j=i;
            }
            j++;
        }
        
        if (band == 0){
            cout<<"El dato no fue hallado";
        }else{
            alum[pos][3] = nota3;
        };

        cout << "Ingresar numero de documento: " << endl;
        cin >>dniBus;   
    }
    
    for (int y = 0; y < i; y++)
    {
        archivo2 << alum[y][0] << " " << alumNom[y] << endl;
        archivo2 << alum[y][1] << " " << alum[y][2] << " " << alum[y][3] << endl; 
    }
    
    cout << "Ingresar numero de documento: " << endl;
    cin >>dniBus;
    busqueda_binaria(alum,dniBus,i,alumNom);

    archivo1.close();
    archivo2.close();
    
    return 0;
   
}

void busqueda_binaria(int alum[][4],int dniBus,int i, string alumNom[]){
    int j = 0;
    int band = 0;
    int pos;
    while (j < i){
        if (alum[j][0] == dniBus){
            band=1;
            pos=j;
            j=i;
        }
        j++;
    }
    
    if (band == 0){
        cout<<"El dato no fue hallado";
    }else{
        cout << "dni alumno: "<< alum[pos][0]<< " nombre alumno: " << alumNom[pos] << " nota1: " <<  alum[pos][1] << " nota2: " << alum[pos][2] << " nota3: " << alum[pos][3] << endl;
    };
}
