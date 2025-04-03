// Example Head Recursion

#include<iostream>
using namespace std;

void func(int n) {
    if (n > 0){ // base condition
        func(n - 1);
        cout << n << endl; // Returning phase
    }
}

int main() {
    int x = 3;
    func(x);

    return 0;
}