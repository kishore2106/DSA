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

// Palindrome using new Array
bool isPalindrome(char *s){
    int i,j;
    char s1[100];
    for(i=0;s[i]!='\0';i++){}
    i=i-1;
    for(j=0;i>=0;i--,j++){
        s1[j]=s[i];
    }
    s1[j]='\0';
    cout<<s1;
    for(i=0,j=0; s[i]!='\0' && s1[j]!='\0'; i++,j++){
        if(s[i]!=s1[j]) break;
    }
    if(s[i]==s1[j]){
        cout<<s[i]<<s[j];
        return true;
    } else {
        return false;
    }

}

// Palindrome using two pointers
bool isPalindrome1(char *s){
    int i,j;
    for(j=0;s[j]!='\0';j++){}
    j=j-1;
    for(i=0; i<j; i++,j--){
        if(s[i]!=s[j]) return false;
    }
    return true;
}

// Duplicate in a string using Hash table
void DuplicateHash(char *s){
    int i, h[26]={0,0};
    for(i=0; s[i]!='\0'; i++){
        h[s[i]-97] += 1;
    }
    for(i=0; i<26; i++){
        if(h[i]>1){
            cout<<(char)(i+97)<<endl;
        }
    }
}

// Duplicate in a string using bitwise
void DuplicateBitwise(char *s){
   long int h=0, x=0;
   for(int i=0; s[i]!='\0';i++){
    x=1;
    x=x<<(s[i]-97);
    if(x&h){
        cout<<s[i]<<" is Duplicate"<<endl;
    } else {
        h=(x|h);
    }
   }
}

// Check for Anagram using Hash table
void isAnagram(char *s1, char *s2){
    int i, h[26]={0};
    for(i=0; s1[i]!='\0'; i++){
        h[s1[i]-97]+=1;
    }

    for(i=0; s2[i]!='\0'; i++){
        h[s2[i]-97]-=1;
        if(h[s2[i]-97]<0){
            cout<<"Not an Anagram"<<endl;
            break;
        }
    }
    
    if(s2[i]=='\0'){
        cout<<"It is an Anagram"<<endl;
    }
}

// Permutation method1
void perm1(char s[], int k){
    static int A[10]={0};
    static char Res[10]={0};
    int i;
    if(s[k]=='\0'){
        Res[k]='\0';
        cout<<Res<<endl;
    } else{
        for(i=0; s[i]!='\0';i++){
            if(A[i]==0){
                Res[k]=s[i];
                A[i]=1;
                perm1(s, k+1);
                A[i]=0;
            }
        }
    }
}

void swap(char *s1, char *s2){
    char temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = *s1;

}

// Permutation method2
void perm2(char s[], int l, int h){
    int i;
    if(l==h){
        cout<<s<<endl;
    } else {
        for(i=l;i<=h;i++){
            swap(s[i], s[l]);
            perm2(s, l+1, h);
            swap(s[i], s[l]);
        }
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
    // char s1[] = "Painter";
    // char s2[] = "Painting";
    // compareStrings(s1, s2);
    // char s1[]="madam";
    // cout<<isPalindrome(s1);
    // cout<<isPalindrome1(s1);
    // char s[]="finding";
    // DuplicateHash(s);
    // DuplicateBitwise(s);
    // char s1[]="verbose";
    // char s2[]="observe";
    // isAnagram(s1, s2);
    char s[]="ABC";
    // perm1(s, 0);
    perm2(s, 0, 2);

    return 0;
}