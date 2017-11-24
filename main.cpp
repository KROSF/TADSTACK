#include <iostream>
#include "pila.h"
using namespace std;
bool shuffle(string);
int main() {
    string X="abc&cba";
    cout<<shuffle(X)<<endl;
    return 0;
}
bool shuffle(const string X){
    Pila <char> P1(X.length());
    int i;
    for(i=0;X[i]!='&';i++){
        P1.push(X[i]);
    }
    for(i+=1;i<X.length()&&X[i]==P1.tope();i++){
        P1.pop();
    }
    return (X.length()==i) ;
}