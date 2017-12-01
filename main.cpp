#include <iostream>
#include <string>
#include "piladinamica.h"
using namespace std;
bool comprobarXY(string );
bool shuffle (string );
int main()
{
    string Z="abc&cba#asd&ds";
    cout<<shuffle(Z);
    return 0;
}

bool shuffle (string Z)
{
    long j=0;
    bool valido=true;
    while(j<Z.length())
    {
        string S;
        int g=0;
        while(Z[j]!='#' && j<Z.length())
        {
            S= S + Z[j];
            g++;
            j++;
        }
        if(!comprobarXY(S))
        {
            j=Z.length()-1;
            valido= false;
        }
        j++;
    }
    return valido;
}

bool comprobarXY(string X)
{
    bool valido=true;
    int i=0;
    Pila<char> P;
    while(X[i]!='&')
    {
        P.push(X[i]);
        i++;
    }
    if((i>=(X.length()/2)+1)||i<X.length()/2)
    {
        valido=false;
    }
    else
    {
        for (i=i+1; i < X.length(); i++)
        {
            if (P.tope() != X[i])
                valido = false;
            P.pop();
        }

    }
    return valido;
}