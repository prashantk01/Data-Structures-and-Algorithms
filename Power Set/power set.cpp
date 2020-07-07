//Time Complexity: O(n2^n)
// bitwise and operator is used
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

void take_input(char *a,int n){
    cout<<"Enter set values: ";
    for(int i=0;i<n;i++)
        cin>>a[i];
}

void power_set(char *a,int n){
    int total_subset=pow(2,n);
    cout<<" { ";
    for(int i=0;i<total_subset;i++){
        cout<<" { ";
        for(int arr_idx=0;arr_idx<n;arr_idx++){
            if ( i & (1<<arr_idx))
                cout<<a[arr_idx];
        }
        if (i!=total_subset-1)
            cout<<" } ,";
        else
            cout<<" } ";
    }
    cout<<" }";
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    char arr[n];
    take_input(arr,n);
    cout<<"Power set is: ";
    power_set(arr,n);
    return 0;
}
