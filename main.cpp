#include <iostream>
#include "pila.h"
using namespace std;
bool shuffle (const string );
int main()
{
    string X="abc&cba#asd&dsa";
    cout<<shuffle(X);
    return 0;
}
bool shuffle (const string X)
{
bool valido=true;
    int i,j,cont,almohadilla;
    cont=0;
    Pila<char> P(X.length());
    for(i=0;i<X.length();i++)
    {
        if(X[i]=='#')
        {
            cont++;
            almohadilla = i;
        }
    }
    if(cont==0)
    {
        valido= false;
    }
    else
    {
    for(i=0;i<cont;i++)
    {
        string Y;
        for(j=0;X[j]!='#';i++)
        {
            Y[j]=X[j];
        }
        Pila<char> Pi(Y.length());
        for(j=0;Y[i]!='&'&&i<Y.length();j++)
        {
            Pi.push(Y[j]);
        }
        if(Pi.llena())
        {
            valido=false;
            i=cont;
        }
        else
        {
            Pi.push('&');
            for(j=j+1;j<Y.length();j++)
            {
                Pi.push(Y[j]);
            }
            for(j=0;j<Y.length();j++)
            {
                if(Pi.tope()!=Y[j])
                {
                    valido=false;
                    i=cont;
                }
                Pi.pop();
            }
        }
    }
    }

    return valido;
}

