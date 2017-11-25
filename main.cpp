#include <iostream>
#include "pila.h"
using namespace std;
bool equate(string);
bool shape(string);
int main() {
    string X="ABC&CBA";
    string Y="AC&CA#CBA&ABC#ABC&CBA#CBDA&ADBC";
    cout<<equate(X)<<endl;
    cout<<shape(Y)<<" Real"<<endl;
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

    for (char i : X) {
        if(i =='#') cont++;
    }

    Pila<string>P(cont+1);

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

    string AUX = X.substr (k);
    P.push(AUX);

    for(int i=0;i<cont+1 && sts;i++)
    {
        if(equate(P.tope()))
        {
            sts = true;
            P.pop();
        }
        else sts = false;
    }

    return sts;
}