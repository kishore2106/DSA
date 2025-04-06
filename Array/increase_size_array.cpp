// Increase size of an Array

#include<iostream>
#include<stdlib.h>
using namespace std;

int main() {

    int *p, *q;
    p = new int[5];
    p[0]=3;p[1]=5;p[2]=7;p[3]=9;p[4]=11;

    q = (int *) malloc(10*sizeof(int));

    for(int i=0; i<5; i++) {
        q[i] = p[i];
    }
    cout<<endl;

    cout<<"Address of P: "<<p<<endl;
    cout<<"Address of Q: "<<q<<endl;

    delete []p;
    p = q;
    q = NULL;

    cout<<"Address of P: "<<p<<endl;
    cout<<"Address of Q: "<<q<<endl;

    for (int i=0; i<5; i++) {
        cout<<"p["<<i<<"] :"<<p[i]<<" ";
    }

    return 0;
}