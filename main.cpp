#include <iostream>
#include "pila.h"
using namespace std;
bool equate(string);
bool shape(string);

int main() {
    string X="ABC&CBA";
    string Y="AC&CA#CBA&ABC#ABC&CBA#CBDA&ADBC";
    //cout<<equate(X)<<endl;
    cout<<shape(Y)<<endl;

    return 0;
}
bool equate(const string X){
    Pila <char> P1(X.length());

    int i;

    for(i=0;X[i]!='&';i++)
        P1.push(X[i]);

    for(i+=1;i<X.length()&&X[i]==P1.tope();i++)
        P1.pop();

    return (X.length()==i) ;
}
bool shape(const string X)
{   unsigned int cont=0;
    int k=0;
    bool sts=true;
    //Cuenta apariciones de #
    for (char i : X) {
        if(i =='#') cont++;
    }
    //Creamos pilas con el numero de # +1
    Pila<string> P(cont+1);
    //Metemos cada cadena en la pila
    for(int j=0;j<cont;j++)
    {
        string AUX;

        while(X[k]!='#')
        {
            AUX+=X[k];
            k++;
        }
        P.push(AUX);
        k+=1;
    }
    //Debido a un fallo no se me ocurre otra forma de metar la ultima cadena a la pila
    string AUX = X.substr (k);
    P.push(AUX);
    //Comprobamos si la pila es de la forma pedida
    for(int i=0;i<cont+1 && sts;i++)
    {
        if(equate(P.tope()))
            P.pop();

        else sts = false;
    }

    return sts;
}
