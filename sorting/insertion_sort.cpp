/*
Approach: 
Take an element from the unsorted array.
Place it in its corresponding position in the sorted part.
Shift the remaining elements accordingly.
In this approach, start iterating the “outer for loop”  from the 2nd position of the array.
The “inner while loop” shifts the elements using swapping.
*/
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
       int  val=a[i]; // current element
       int  j=i-1;
        while(a[j] > val && j>=0 ){  // keep checking current element with left sorted array
            a[j+1]=a[j];
            j--;
        }
        // once location is found, replace with current picked element from unsorted array
        a[j+1]=val;
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
