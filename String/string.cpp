// String

#include<iostream>
using namespace std;

// Length of String
int length(char s[]){
    int i;
    for(i=0;s[i]!='\0';i++){}
    return i;
}

// Upper case to Lower case
void toLower(char *s){
    int i;
    for(i=0;s[i]!='\0';i++){
        if(s[i]>=65 && s[i]<=90){
            s[i]+=32;
        }
    }
}

// Lower case to Upper case
void toUpper(char *s){
    int i;
    for(i=0;s[i]!='\0';i++){
        if(s[i]>=97 && s[i]<=122){
            s[i]-=32;
        }
    }
}

// Toggle case
void toggleCase(char *s){
    int i;
    for(i=0; s[i]!='\0'; i++){
        if(s[i]>=65 && s[i]<=90){
            s[i]+=32;
        } else if(s[i]>='a' && s[i]<='z'){
            s[i]-=32;
        }
    }
}

int main() {
    char name[] = "welcome";
    char name1[] = "WELCOME";
    char name2[] = "WeLcOmE";
    // cout<<length(name);
    // toLower(name1);
    // toUpper(name);
    toggleCase(name2);
    cout<<name2;

    return 0;
}