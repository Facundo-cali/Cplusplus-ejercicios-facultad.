#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;

int devuelveMes(string fecha);
int busqueda(string matCod[][2],int tam,string cod);
void ordenamiento(string matCod[][2], int totalInv[],int tam);

int main(int argc, char const *argv[])
{

    ifstream archivoSuc;
    ifstream archivoPort;
    ifstream archivoInv;

    
    archivoPort.open("./PORTFOLIO.TXT");
     
    if (archivoPort.fail()){
        cout << "Error!" << endl;
        exit(1);
    }
    string matCod[10][2],cod,des; //matriz de codigos de inversion [0-cod][1-des]
    int totalInv[10];//vector donde guardo el total de ventas de cada codigo de inversion
    for (int i = 0; i < 10; i++)
    {
        totalInv[i] = 0;
    }
    
    int filaCod = 0;
    archivoPort >> cod;
    while (!archivoPort.eof()) {
        archivoPort.ignore();
        getline(archivoPort,des);
        matCod[filaCod][0] = cod;
        matCod[filaCod][1] = des;
        filaCod++;
        archivoPort >> cod; //vuelvo a preguntar lo q pregunte arriba del while
    } 
    archivoPort.close();
    
    archivoInv.open("./INVERSIONES.TXT");
     
    if (archivoInv.fail()){
        cout << "Error!" << endl;
        exit(1);
    }
    int mat1[10][12];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            mat1[i][j] = 0;
        }
    }
    
    int suc;
    string codInv;
    string fecha;
    long monto;

    archivoInv >> suc;
    while (!archivoInv.eof()) {
        archivoInv >> codInv;
        archivoInv >> monto;
        int acumularEnFila = busqueda(matCod,10,codInv);
        totalInv[acumularEnFila - 1] += monto;
        archivoInv.ignore();
        getline(archivoInv,fecha);
        int mes = devuelveMes(fecha);
        mat1[suc - 1][mes - 1]++;
        archivoInv >> suc; //vuelvo a preguntar lo q pregunte arriba del while
    } 
    cout << "SUC. ENE  FEB  MAR  ABR   MAY   JUN    JUL   AGO    SEP     OCT         NOV      DIC" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1<< " ";
        for (int j = 0; j < 12; j++)
        {
            cout << "   " << mat1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "COD INV                       DESCRIPCION                                 MONTO" << endl;
    ordenamiento(matCod,totalInv,10);
    for (int i = 0; i < 10; i++)
    {
        cout << setw(10) <<matCod[i][0] <<setw(40)<< matCod[i][1] << setw(15)<<setprecision(2)<<totalInv[i]<<endl;
    }
    archivoInv.close();
    


    return 0;
}

int devuelveMes(string fecha){
    string mess;
    mess = fecha.substr(3,2);
    int mes = stoi(mess);
    return mes;
}

int busqueda(string matCod[][2],int tam,string cod){
    int band=0, pos;

    int i = 0; 
    while (i < tam){
        if (matCod[i][0] == cod){
            band=1;
            pos=i+1;
            i=tam;
        }
        i++;
    }

    return pos;
}

void ordenamiento(string matCod[][2], int totalInv[],int tam){
    string auxmatCod[tam][2];
    int auxtotalInv[tam];
    for (int i=0; i < (tam-1); i++){
        for (int j=i+1; j<tam; j++){
            if (totalInv[i] < totalInv[j]){
                auxmatCod[i][0] = matCod[i][0];
                auxmatCod[i][1] = matCod[i][1];
                auxtotalInv[i] = totalInv[i];
                
                matCod[i][0] = matCod[j][0];
                matCod[i][1] = matCod[j][1];
                totalInv[i] = totalInv[j];

                matCod[j][0] = auxmatCod[i][0];
                matCod[j][1] = auxmatCod[i][1];
                totalInv[j] = auxtotalInv[i];
            }
        }
    }
}