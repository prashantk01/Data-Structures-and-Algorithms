#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

//return left child or root
int left_child(int i, int n){
    return (2*i+1);
}

//return right child or root
int right_child(int i, int n){
    return (2*i+2);
}

// make sure given heap is max heap  from last non leaf node to the root
void heapify(int *arr, int n, int i)
{
    int lc=left_child(i,n);
    int rc=right_child(i,n);
    int largest=i;
    if( lc < n  && arr[lc] > arr[largest])
        largest=lc;
    if (rc <n && arr[rc] > arr[largest])
        largest=rc;
    if (largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

void build_max_heap(int *arr, int n){
    //finding last non-leaf node
    int lf=(n-1)/2;  // as n/2 to n are leaf nodes
    for(int i=lf ; i>=0 ;i-- ){
        heapify(arr,n,i);
    }
}

void heap_sort(int *a, int n){
    //build heap or rearrange array
    build_max_heap(a,n);

    //now start deleting last element after swapping first and last followed by swapping
    for (int i=n-1;i>=0;i--){
        swap(a[i],a[0]);
        heapify(a,i,0);
    }
}

void display(int *a, int n){
    for(int i=0; i<n ; i++)
        cout<<" "<<a[i];
    cout<<endl;
}

int main(){

    int n;
    cout<<"Enter no of elements in array : ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter array: ";
    for (int i=0; i<n;i++)
        cin>>arr[i];
    cout<<"\nEntered array is: ";
    display(arr,n);
    heap_sort(arr,n);
    cout<<"\nSorted array is: ";
    display(arr,n);

return 0;
}
