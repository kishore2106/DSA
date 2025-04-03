// Example Tail Recursion

#include<iostream>
using namespace std;

void func(int n) {
    if (n > 0){ // base condition
        cout << n << endl; // Calling phase
        func(n - 1);
    }
}

int main() {
    int x = 3;
    func(x);

    return 0;
}