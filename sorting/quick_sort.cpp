#include<bits/stdc++.h>
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
    // update below two variables [pivot_ele, pivot_idx] as per your pivot last or first
    int pivot_ele=a[re]; // left most value is considered as pivot element  now place this element inplace
    int pivot_idx = re;  // pivot element current index
    int left_iterator=le;
    int right_iterator=re;
    while( left_iterator < right_iterator ){
        while( pivot_ele >= a[left_iterator]  && left_iterator < re)
            left_iterator++;
        while( pivot_ele <= a[right_iterator] && right_iterator > le)
            right_iterator--;
        if( left_iterator < right_iterator )
            swap(a[left_iterator],a[right_iterator]);  //swapping with inbuilt function
    }
    int swap_idx;
    if(pivot_idx == re) swap_idx = left_iterator;
    else swap_idx = right_iterator;
    swap(a[pivot_idx], a[swap_idx]);
    return swap_idx;
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
    cout << endl;
    return 0;
}
