#include<iostream>
#include<stdlib.h>
using namespace std;

int catalan_num(int n){
     int table[n+1];
     table[0]=1;
     table[1]=1;

     for (int i = 2; i <= n; i++) {
        table[i]=0;
        for (int j = 1; j <= i; j++) {
            table[i] +=table[i - j] * table[j - 1];
        }
    }
    return table[n];
}
int main(){
    int n;
    cout<<"Enter no of nodes: ";
    cin>>n;
    cout<<"\nTotal Binary Search Tree possible are: "<<catalan_num(n);
    return 0;
}

