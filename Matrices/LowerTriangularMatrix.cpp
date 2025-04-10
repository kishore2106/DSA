// Lower Triangular Matrix (Row Major Representation)

#include<iostream>
using namespace std;

struct Matrix{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x){
    if(i>=j){
        // row major
        m->A[(i*(i-1)/2)+j-1]=x;
        // column major
        // m->A[m->n*(j-1)-(j-2)*(j-1)/2+i-j]=x;
    }
}

int Get(struct Matrix m, int i, int j){
    if(i>=j){
        // row major
        return m.A[i*(i-1)/2+j-1];
        // column major
        // return m.A[m.n*(j-1)-(j-2)*(j-1)/2+i-j];
    } else {
        return 0;
    }   
}

void Display(struct Matrix m){
    for(int i=1;i<=m.n;i++){
        for(int j=1;j<=m.n;j++){
            if(i>=j){
                cout<<m.A[(i*(i-1)/2)+j-1]<<" ";
            } else {
                cout<<0<<" ";
            }
        }
        cout<<"\n";
    }
}

int main(){
    struct Matrix m;
    int i,j,x;

    cout<<"Enter Dimension";
    cin>>m.n;
    m.A=new int[m.n*(m.n+1)/2];

    cout<<"Enter all elements";
    for(i=1;i<=m.n;i++){
        for(j=1;j<=m.n;j++){
            cin>>x;
            Set(&m,i,j,x);
        }
    }

    cout<<"\n\n";
    Display(m);
    return 0;
}