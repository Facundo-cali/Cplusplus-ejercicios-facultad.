#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;
/* 6. Se desea realizar un informe con las cantidades de multas por exceso de velocidad que se labran en el país durante un mes.
Se cuenta con la información que envían todos los municipios: código de provincia y cantidad demultas. Un código de provincia igual a 99 indica el fin de datos.
Informe:
 Nombre de la Provincia Cantidad de multas
 xxxxxxxxxxxxxxxxxxxx xxxxx
 xxxxxxxxxxxxxxxxxxxx xxxxx
 Total de multas: xxxxx
Utilice el archivo creado en el ejercicio anterior para obtener los nombres de las provincias. */

int main(int argc, char const *argv[])
{
    
    ifstream archivo;//creamos el archivo de lectura
    string prov[24];
    int codProvPedido;
    int multas[24];
    int cantMultas;
    int basura;
    int aux = 0;
    archivo.open("./guia8_5.txt");
    int totalMultas = 0;

    for (int i = 0; i < 24; i++)
    {
        multas[i] = 0;
    }

    if (archivo.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error

    
    while (!archivo.eof()){
        archivo >> basura;
        archivo.ignore();
        getline(archivo,prov[aux]);
        aux++;
    }
    

    cout << "Ingresar codigo de provincia donde se cometio la multa: " << endl;
    cin >>codProvPedido;
    while (codProvPedido != 99)
    {
        cout << "Ingresar cantidad de multas: " << endl;
        cin >>cantMultas;
        totalMultas += cantMultas;
        multas[codProvPedido] = cantMultas;
        cout << "Ingresar codigo de provincia donde se cometio la multa: " << endl;
        cin >>codProvPedido;

    }
    
    for (int i = 0; i < 24; i++)
    {
        cout << "nombre prov: "<< prov[i] << "|| Cantidad de multas: "<<multas[i] << endl;
    }

    cout << "Total multas: "<< totalMultas << endl;
    
    


    archivo.close();//cerramos archivo



    return 0;
}
