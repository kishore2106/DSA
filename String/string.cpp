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

// Counting Number of vowerls and consonants
void countVowelCons(char *s){
    int i;
    int vcount=0, ccount=0;
    for(i=0; s[i]!='\0';i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ) {
            vcount++;
        } else if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)) {
            ccount++;
        }
    }
    cout<<"Number of vowels: "<<vcount<<"\n Number of consonants: "<<ccount;
}

// counting number of words 
int countWords(char *s){
    int i, word=1;
    for(i=0; s[i]!='\0'; i++){
        if(s[i]==' ' && s[i]!=s[i-1]){
            word++;
        }
    }
    return word;
}

int main() {
    char name[] = "welcome";
    char name1[] = "WELCOME";
    char name2[] = "WeLcOmE";
    char vowelCons[] = "How are you"; 
    // cout<<length(name);
    // toLower(name1);
    // toUpper(name);
    // toggleCase(name2);
    // cout<<name2;
    // countVowelCons(vowelCons);
    cout<<countWords(vowelCons);

    return 0;
}