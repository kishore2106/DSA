// Tower of Hanoi using Recursion

#include<iostream>
using namespace std;

void TowerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n > 0) {
        TowerOfHanoi(n-1, source, destination, auxiliary);
        cout << "Move disk " << n << " from source " << source << " to destination "<< destination <<endl;
        TowerOfHanoi(n-1, auxiliary, source, destination);
    }
}

int main() {
    int n;
    cout<<"Enter the number of disks: ";
    cin>>n;
    TowerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}