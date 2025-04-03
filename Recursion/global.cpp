// global variables using Recursion

#include<iostream>
using namespace std;

int count = 0;

int sum(int n) {
    if (n > 0) {
        count++;
        return sum(n-1) + count;
    }
    return 0;
}

int main() {

    int n = 5;
    cout<<sum(n)<<endl;
    cout<<"count: "<<count<<endl;
    cout<<sum(n)<<endl;
    cout<<"count: "<<count<<endl;
    return 0;
}