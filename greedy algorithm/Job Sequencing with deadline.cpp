// job sequencing with deadline greedy approach
// to sort profit array bubble sort is used
//time complexity is O(n*n)

#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct job{
    int id;
    int profit;
    int deadline;
};

void take_input(struct job a[], int n){
    for(int i=0;i<n;i++){
        a[i].id=i+1;
        cout<<"\nEnter job "<<i+1<<" profit  : ";
        cin>>a[i].profit;
        cout<<"Enter job "<<i+1<<" deadline: ";
        cin>>a[i].deadline;
    }
}

void display(struct job arr[],int n){
    cout<<"\njob profit   :   ";
    for(int i=0;i<n;i++)
        cout<<arr[i].profit<<"           ";
    cout<<"\njob deadline :   ";
    for(int i=0;i<n;i++)
        cout<<arr[i].deadline<<"           ";
}

int sequence_job(struct job arr[], int n){
    int result[n];
    int flag[n];
    int max_profit=0;
    for(int i=0;i<n;i++){
        result[i]=0;
        flag[i]=0;
    }
    for(int i=n-1;i>=0;i--){
            for(int j=min(n,arr[i].deadline)-1;j>=0;j--){
                    if(result[j]==0){
                        max_profit+=arr[i].profit;
                        result[j]=1;
                        flag[j]=arr[i].id;
                        break;
                    }
            }
    }
    cout<<"\nThe Job Sequence is: ";
    for(int i=0;i<n;i++){
        if(flag[i]!=0){
            cout<<" --> Job["<<flag[i]<<"]";
        }
    }
    return max_profit;
}

int main(){
    int n;
    cout<<"Enter total job: ";
    cin>> n;
    job arr[n];
    take_input(arr,n);
    //display(arr,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j].profit > arr[j+1].profit){

                int temp=arr[j].profit;
                arr[j].profit=arr[j+1].profit;
                arr[j+1].profit=temp;

                temp=arr[j].id;
                arr[j].id=arr[j+1].id;
                arr[j+1].id=temp;

                temp=arr[j].deadline;
                arr[j].deadline=arr[j+1].deadline;
                arr[j+1].deadline=temp;
            }
        }
    }
    //display(arr,n);
    cout<<"\nThe max profit can have is : "<<sequence_job(arr,n);
return 0;
}
