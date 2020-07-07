#include<iostream>
#include<stdlib.h>
using namespace std;

void power_set(string  str,int index,string curr){
    int n = str.length();
    if (index == n) {
        cout << curr << endl;
        return;
    }
    power_set(str, index + 1, curr + str[index]);
    power_set(str, index + 1, curr);
}
int main(){
    string s;
    cout<<"Enter string : ";
    cin>>s;
    power_set(s,0,"");
}
