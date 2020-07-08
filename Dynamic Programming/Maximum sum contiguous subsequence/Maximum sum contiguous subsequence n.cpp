// Using the above recurrence relation, we can compute the sum of the optimal subsequence for array A, which would just be the maximum over S[i] for 0 \leq i \leq n-1.
// hence complexity is improved to O(n^1)
#include<iostream>
#include<stdlib.h>
using namespace std;

void take_input(int *a,int n){
    cout<<"Enter array: \n";
    for(int i=0;i<n;i++)
        cin>>a[i];
}

void max_sum(int *a,int n){
    int s[n];
    int max_sm=a[0];
    s[0]=a[0];
    for (int i=1;i<n;i++){
    s[i]=max(s[i-1]+a[i],a[i]);
    if (s[i] > max_sm)
        max_sm=s[i];
    }
    cout<<"\nMaximum contiguous sum is: "<<max_sm;
   // cout<<"\nThe starting index is: "<<starting_index;
    //cout<<"\nThe ending index is: "<<ending_index;
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
