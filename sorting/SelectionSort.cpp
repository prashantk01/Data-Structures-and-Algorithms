#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

void display(int a[], int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

void selection_sort(int a[], int n){
    for (int i=0;i< n;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if( a[j] < a[min_idx])
                min_idx=j;
        }
        if(min_idx != i){
            int temp=a[i];
            a[i]=a[min_idx];
            a[min_idx]=temp;
        }
    }
}

int main(){
    int n;
    cout<<"Enter no of element: ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\nEntered array is: ";
    display(arr,n);
    selection_sort(arr,n);
    cout<<"\n Sorted array is: ";
    display(arr,n);
    return 0;
}
