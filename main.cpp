#include <iostream>
#include <fstream>
#include <string>
#include "piladinamica.h"
void sumafichero(fstream& );
using namespace std;

int main()
{
    string nombre_f="fichero.txt.txt";

    // TENGO QUE OBTENER EL NOMBRE DEL FICHERO QUE YA VOY A MODIFICAR

    fstream f(nombre_f);
    sumafichero(f);
    f.close();
    return 0;
}

void sumafichero(fstream& fichero)
{
    Pila<int> P,Q,R;
    fichero>>P>>Q;            //Extraer de f los numeros
    P.pop();
    Q.pop();
    int cont=0;
    while(!P.vacia()&&!Q.vacia())
    {
            R.push((P.tope() + Q.tope() + cont)%10);
            cont=(P.tope() + Q.tope())/10;
            P.pop();
            Q.pop();
    }
    if(!P.vacia()||!Q.vacia())
    {
        if (P.vacia()) {
            while (!Q.vacia()) {
                R.push(Q.tope());
                Q.pop();
            }
        } else
            while (!P.vacia())
            {
                R.push(P.tope());
                P.pop();
            }
    }
    fichero<<R;
}