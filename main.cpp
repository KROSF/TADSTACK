#include <iostream>
#include "pila.h"
using namespace std;
void stck(Pila<int>&,int,int);
int main()
{
    int vec[13]={3,4,1,3,4,1,3,4,2,4,2,2,3};
    int a=1,b=2;
    bool sts = true;
    for(int i=0;i<13&&sts;i++)
    {
        if(vec[i]==a )
        {
            a=i;
            sts = false;

            while(vec[i]!=b)
             i++;

            b=i;
        }
    }

    for(int i=a;i<b;i++,b--)
        swap(vec[i],vec[b]);

    for (int i : vec)
        cout<< i <<" ";

    return 0;
}
void stck(Pila<int>& P,int a,int b){
    Pila<int>AUX(19);
    while(!P.vacia())
    {
        cout<<P.tope()<<" ";
        AUX.push(P.tope());
        P.pop();
    }
    cout<<endl;
    while(!AUX.vacia()){
        cout<<AUX.tope()<<" ";
        AUX.pop();
    }
}
