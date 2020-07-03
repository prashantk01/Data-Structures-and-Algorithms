//A simple brute-force method could be to compute the sums of all possible subseqnences in A.
//How many subsequences are there? There are n+ (n-1) + (n-2) + ... + 1 = O(n^2) possible subsequences.
//Computing the sum of a subsequence takes O(n) in the worst-case.
//Hence, the running time of this  algorithm would be O(n^3).
#include<iostream>
#include<stdio.h>
using namespace std;

void take_input(int *a,int n){
    cout<<"Enter array: \n";
    for(int i=0;i<n;i++)
        cin>>a[i];
}

void max_sum(int *a,int n){
    int maximum_sum=0;
    int starting_index;
    int ending_index;
    for (int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sm=0;
            for (int k=i;k<=j;k++){
                sm+=a[k];
            }
            if (sm > maximum_sum){
                maximum_sum=sm;
                starting_index=i;
                ending_index=j;
            }
        }

    }
    cout<<"\nMaximum contiguous sum is: "<<maximum_sum;
    cout<<"\nThe starting index is: "<<starting_index;
    cout<<"\nThe ending index is: "<<ending_index;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    take_input(arr,n);
    max_sum(arr,n);
    return 0;
}
