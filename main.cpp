#include <iostream>
#include "pila.h"
#include "piladinamica.h"
using namespace std;
bool comprobarXY(string);
int main()
{
    string X="Abc&cbA";
    cout<<comprobarXY(X);
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
        for (i=i+1; !P.vacia(); i++)
        {
            if (P.tope() != X[i])
                valido = false;
            P.pop();
        }

    }
    return valido;
}





































//VERSION PSEUDOESTATICA
/*
using namespace std;
bool shuffle (const string );
int main()
{
    string X="abccba";
    if(shuffle(X))
    {
        cout<<"La cadena es de la forma X&Y"<<endl;
    }
    else
        cout<<"La cadena NO es de la forma X&Y"<<endl;
    return 0;
}
bool shuffle (const string X)
{
    bool valido=true;
    int i;
    Pila <char>P(X.length());
    for(i=0;X[i]!='&'&& i<X.length();i++)
    {
       P.push(X[i]);
    }
    if(P.llena())
    {
        valido = false;
    }
    else
        {
    P.push('&');
    for(i=i+1;i<X.length();i++)
    {
        P.push(X[i]);
    }
    for(i=0;i<X.length();i++)
    {
        if(P.tope()!=X[i])
        {
            valido= false;
            i=X.length();
        }
        P.pop();
    }}
    return valido;
}*/

