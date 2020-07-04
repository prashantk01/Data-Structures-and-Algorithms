#include<iostream>
#include<stdlib.h>
using namespace std;

unsigned long long int factorial(int n){
    unsigned long long int z=1;
    for(int i=2;i<=n;++i)
        z*=i;
    return z;
}

unsigned long int catalan_num(int n){

    //here x= (2n)!
    unsigned long long int x=factorial(2*n);
    //cout<<"x: "<<x;

    //here y=(n)!
    unsigned long long int y=factorial(n);
    //cout<<"\ny: "<<y;

    x/=y;
    x/=y;
    x/=(n+1);
    return x;
}
int main(){
    int n;
    cout<<"Enter no of nodes: ";
    cin>>n;
    cout<<"\nToal Binary Search Tree possible are: "<<catalan_num(n);
    return 0;
    //16796
}
