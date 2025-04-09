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

// validate string
int validateString(char *s){
    int i;
    for(i=0; s[i]!='\0'; i++){
        if(!(s[i]>=65 && s[i]<=90) && !(s[i]>=97 && s[i]<=122) && !(s[i]>=48 && s[i]<=57)) {
            return 0;
        }
    }
    return 1;
}

// Reversing a string using new array
char* reverseString(char *s){
    int i,j;
    static char s1[100];
    for(i=0; s[i]!='\0'; i++){}
    i=i-1;
    for(j=0; i>=0; i--,j++){
        s1[j]=s[i];
    }
    s1[j]='\0';
    return s1;
}

// Reversing a string using 2 pointers
void reverseString1(char *s){
    int i, j;
    char t;
    
    for(j = 0; s[j] != '\0'; j++) {}  
    j = j - 1;  
    
    for(i = 0; i < j; i++, j--){
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

// comparing two strings
void compareStrings(char *s1, char *s2){
    int i,j;
    for(i=0, j=0; s1[i]!='\0' && s2[j]!='\0'; i++,j++){
        if(s1[i]!=s2[j]) break;
    }
    if(s1[i]==s2[j]){
        cout<<"Strings are equal"<<endl;
    } else if(s1[i] > s2[j]){
        cout<<"String s1 is greater";
    } else {
        cout<<"String s1 is lesser";
    }
}

int main() {
    // char name[] = "welcome";
    // char name1[] = "WELCOME";
    // char name2[] = "WeLcOmE";
    // char vowelCons[] = "How are you";
    // char name3[] = "kishore@123";
    // char *s1;
    // cout<<length(name);
    // toLower(name1);
    // toUpper(name);
    // toggleCase(name2);
    // cout<<name2;
    // countVowelCons(vowelCons);
    // cout<<countWords(vowelCons);

    // if(validateString(name3)){
    //     cout<<"Valid String"<<endl;
    // } else {
    //     cout<<"Invalid String"<<endl;
    // }
    // reverseString(name);
    // reverseString1(name);
    // cout<<name;
    char s1[] = "Painter";
    char s2[] = "Painting";
    compareStrings(s1, s2);

    return 0;
}