#include <iostream>
#include "pila.h"
using namespace std;
bool shuffle (const string );
int main()
{
    string X="abc&cba";
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
}