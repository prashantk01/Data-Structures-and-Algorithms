#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void take_input(int *a,int n){
    for (int i =0; i<n; i++)
        cin>>a[i];
}

void display(int a[], int n){
    for (int i=0;i < n; i++)
        cout<<a[i]<<" ";
}


void insertion_sort(int a[], int n){
    //left part is sorted
    for(int i=1;i<n;i++){
       int  val=a[i];
       int  j=i;
        while(a[j-1] > val &&j>=1 ){
            a[j]=a[j-1];
            j--;
        }
        a[j]=val;
    }
}

int main(){
    int n;
    cout<<"ENTER NO OF ELEMENT IN ARRAY: ";
    cin>>n;
    int arr[n];
    cout<<"ENTERED ARRAY: ";
    take_input(arr,n);
    cout<<"\nENTERED ARRAY IS: ";
    display(arr,n);
    insertion_sort(arr,n);
    cout<<"\nTHE SORTED ARRAY IS: ";
    display(arr,n);
    return 0;
}
