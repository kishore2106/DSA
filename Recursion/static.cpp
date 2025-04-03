// static variables using Recursion

#include<iostream>
using namespace std;

int sum(int n) {
    static int count = 0;
    if (n > 0) {
        count++;
        return sum(n-1) + count;
    }
    return 0;
}

int main() {

    int n = 5;
    cout<<sum(n)<<endl;
    return 0;
}