#include <iostream>
#include "piladinamica.h"
#define N 13
void invertirpila(Pila<int>&,int ,int );
using namespace std;
int main()
{
    Pila<int> P;
    int original[N]={3,2,2,4,2,4,3,1,4,3,1,4,3};int i,a,b;
    for(i=0;i<N;i++)
    {
        P.push(original[i]);
    }
    Pila<int> H;
    H=P;
    for(int i=0;!H.vacia();i++)
    {
        cout<<H.tope()<<" ";
        H.pop();
    }
    cout<<endl;
    a=1;b=2;
    invertirpila(P,a,b);
    for(int i=0;!P.vacia();i++)
    {
        cout<< P.tope() <<" ";
        P.pop();
    }
    return 0;
}

void invertirpila(Pila<int>& W,int a,int b)
{
    Pila<int> AUX,INV;
    while( !W.vacia() && W.tope()!=a)
    {
        AUX.push(W.tope());
        W.pop();
    }
    while(!W.vacia() && W.tope()!=b)
    {
        INV.push(W.tope());
        W.pop();
    }
    if(!W.vacia())
    {
        INV.push(W.tope());
        W.pop();
        while (!INV.vacia() && !W.vacia()) {
            AUX.push(INV.tope());
            INV.pop();
        }
        while (!W.vacia() && !W.vacia()) {
            AUX.push(W.tope());
            W.pop();
        }
        while (!AUX.vacia()) {
            W.push(AUX.tope());
            AUX.pop();
        }
    } else
        while (!INV.vacia())
        {
            W.push(INV.tope());
            INV.pop();
        }
        while (!AUX.vacia())
        {
            W.push(AUX.tope());
            AUX.pop();
        }
}