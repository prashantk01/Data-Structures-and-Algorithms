#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void take_input(int *a,int n){

    for (int i =0; i<n; i++)
        cin>>a[i];

}

void display(int a[], int n){

    for (int i=0;i < n; i++)
        cout<<a[i]<<" ";
}

int find_partition(int a[],int le,int re){

    int part_index=le;
    int pivot_ele=a[le]; // left most value is considered as pivot element
    int left_iterator=le;
    int right_iterator=re;
    while( left_iterator < right_iterator ){
        while( pivot_ele >= a[left_iterator] )
            left_iterator++;
        while( pivot_ele < a[right_iterator] )
            right_iterator--;
        if( left_iterator < right_iterator )
            swap(a[left_iterator],a[right_iterator]);  //swapping with inbuilt function
    }
    a[le]=a[right_iterator];
    a[right_iterator]=pivot_ele;
    return right_iterator;
}

 void quick_sort(int a[], int le, int re){
    int part_tion;
    if( le<re ){
        part_tion=find_partition(a,le,re); // function to find partition element
        quick_sort(a,le,part_tion-1);
        quick_sort(a,part_tion+1,re);
    }
 }

//driver code
int main(){
    int n;
    cout<<"ENTER NO OF ELEMENT IN ARRAY: ";
    cin>>n;
    int arr[n];
    cout<<"ENTERED ARRAY: ";
    take_input(arr,n);
    cout<<"\nENTERED ARRAY IS: ";
    display(arr,n);
    quick_sort(arr,0,n-1);
    cout<<"\nTHE SORTED ARRAY IS: ";
    display(arr,n);
    return 0;
}
