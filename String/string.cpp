// String

#include<iostream>
using namespace std;

// Length of String
int length(char s[]){
    int i;
    for(i=0;s[i]!='\0';i++){}
    return i;
}

int main() {
    char name[] = "welcome";
    cout<<length(name);

    return 0;
}