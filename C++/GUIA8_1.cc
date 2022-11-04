/* Se desea generar un archivo de texto que guarde los valores de x e y donde y = a x2 + bx + c.
Los valores de a, b y c son ingresados por teclado. Los valores de x son números enteros desde 1
hasta 1000.
En cada renglón del archivo deben estar los valores de x e y separados por un espacio en blanco.
Utlizar una función llamada funcion_cuadratica que recibe de parámetros los coeficientes a, b, c y el
valor de x y devuelve el valor de y. */

#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

long funcion_cuadratica(int,int,int,int);

int main(int argc, char const *argv[])
{
    int a,b,c;
    ofstream archivo;//creamos el archivo
    archivo.open("./guia8_1.txt");//lo abrimos

    if (archivo.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error

    cout << "Ingresar valor a: " << endl;
    cin >>a;
    cout << "Ingresar valor b: " << endl;
    cin >>b;
    cout << "Ingresar valor c: " << endl;
    cin >>c;

    
    for (int x = 0; x < 1000; x++)
    {
        archivo << x << " " << funcion_cuadratica(a,b,c,x) << endl;//guardamos datos
    }
    archivo.close();//cerramos archivo


    return 0;
}

long funcion_cuadratica(int a, int b, int c, int x){

    long y = a * (pow(x,2)) + b * x + c;

    return y;  

}