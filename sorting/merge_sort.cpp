#include<bits/stdc++.h>
using namespace std;

int iteration=0,d_and_c=0;

void take_input(int *a,int n){

    for (int i =0; i<n; i++)
        cin>>a[i];

}

void display(int a[], int n){

    for (int i=0;i < n; i++)
        cout<<a[i]<<" ";
}

int merge_array(int a[], int l_index, int mid,int r_end, int n){

    int temp[n];
    int r_index=mid+1;
    int temp_index=l_index;
    int i=l_index;
    int counter=0;
    while( l_index <= mid && r_index <= r_end ){

        if(a[l_index] < a[r_index])
            temp[temp_index++]=a[l_index++];

        else
            temp[temp_index++]=a[r_index++];

        counter++;
    }

    while(l_index <= mid){
        temp[temp_index++]=a[l_index++];
        counter++;
    }

    while(r_index <= r_end){
        temp[temp_index++]=a[r_index++];
        counter++;
    }

    for(int k=i;k<=r_end;k++)
        a[k]=temp[k];
        
    cout<<"\nARRAY AT MERGING STEP "<<iteration++<<" IS: ";
    display(a,n);
  
}

 void merge_sort(int a[],int l_index, int r_index, int n){

    int mid= (r_index + l_index)/2;
    if (l_index < r_index){
        d_and_c++;
        merge_sort(a,l_index,mid,n);
        d_and_c++;
        merge_sort(a,mid+1,r_index,n);
        merge_array(a,l_index,mid,r_index,n);
    }
}

int main(){

    int n;
    cout<<"ENTER NO OF ELEMENT: ";
    cin>>n;
    int arr[n];
    cout<<"ENTER ARRAY: \n";
    take_input(arr,n);
    cout<<"ENTERED ARRAY IS: ";
    display(arr,n);
    int left_end=0,right_end=n-1;
    merge_sort(arr,left_end,right_end,n);
    cout<<"\nTOTAL STEPS INVOLVED IS: "<<d_and_c+iteration+2;
    cout<<"\nTHE SORTED ARRAY IS: ";
    display(arr,n);
    cout << endl;
    return 0;

}
