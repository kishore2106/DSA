// Sum of n natural numbers using Recursion

#include<iostream>
using namespace std;

int sum(int n) {
    if (n > 0) {
        return sum(n-1) + n;
    }
    return 0;
}

int main() {

    int n = 5;
    cout<<sum(n)<<endl;
    return 0;
}