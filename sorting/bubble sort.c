//modified version of bubble sort
//o(n) for best case by using flag


/*
* 
Algo: 
*Repeatedly swap 2 adjacent elements if arr[j] > arr[j+1] .
*The maximum element of the unsorted array reaches the end of the unsorted array after each iteration.
*After (N-1) iterations , we get a sorted array.
*/

#include<stdlib.h>
#include<stdio.h>
void bubble_sort(int a[],int n){
    for (int i=0;i<n;i++){
        int flag=0;
        for(int j=0;j<n-i;j++){
                if(a[j] > a[j+1])
                {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    flag=1;
                }
        }
        if(flag==0)
            return;
    }
}

void display(int a[], int n){
    printf("\nEntered array is: ");
    for (int i=0;i<n;i++){
        printf("  %d",a[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Array: ");
    for(int i=0;i< n;i++){
        scanf("%d",&arr[i]);
    }
    display(arr,n);
    bubble_sort(arr,n);
    printf("Sorted array is: \n");
    display(arr,n);
    return 0;
}
