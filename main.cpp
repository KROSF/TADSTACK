#include <iostream>
#include "pila.h"
using namespace std;
bool shuffle (const string );
int main()
{
    string X="abc&ca";
    cout<<shuffle(X);
    return 0;
}
bool shuffle (const string X)
{
    int i;
    Pila <char>P(X.length());
    for(i=0;i<X.length();i++)
    {
       P.push(X[i]);
    }
    for(i=0;i<X.length();i++)
    {
        if(P.tope()!=X[i])
        {
            cout<<"tu ere tonto"<<endl;
            return false;
        }
        P.pop();
    }
    return true;
}