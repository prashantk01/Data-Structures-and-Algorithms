// by being a bit more clever in computing the sums of different subsequences.
// We observe that the sum of the subsequence A[i … j+1] = A[j+1] + sum of the subsequence A[i … j].
// hence complexity is improved to O(n^2)
#include<iostream>
#include<stdlib.h>
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
        int sm=0;
        for(int j=i;j<n;j++){
            sm+=a[j];
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
