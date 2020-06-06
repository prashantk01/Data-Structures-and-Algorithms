#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct Object{
    int price;
    int weight;
    float rat;
};

float fractional_knapsack(struct Object arr[], int capacity,int n){
    int w=capacity;
    float profit=0;
    for(int i=n-1;i>=0;i--){
        if(arr[i].weight < w && w >=0){
            profit+=arr[i].price;
           // cout<<"\nprofit "<<profit;
            w-=arr[i].weight;
        }
        else{

            profit+=arr[i].rat*w;
           // cout<<"\nprofit "<<profit;
            break;
        }
    }
return profit;
}

int main(){
    int capacity=15;
    Object arr[]={{10,2,0},{5,3,0},{15,5,0},{7,7,0},{6,1,0},{18,4,0},{3,1,0}};
    int n=7;//size of array or total objects
    for(int i=0;i<n;i++){
        arr[i].rat=(float)(arr[i].price)/(arr[i].weight);
    }

    /* for(int i=0;i<n;i++){
        cout<<"price :   "<<arr[i].price<<endl;
        cout<<"weight:   "<<arr[i].weight<<endl;
        cout<<"ratio :   "<<arr[i].rat<<endl<<endl;

    }*/
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j].rat > arr[j+1].rat)
            {
                /*float tempp;
                int temp;
                temp=arr[j].price;
                arr[j].price=arr[j+1].price;
                arr[j+1].price=temp;

                temp=arr[j].weight;
                arr[j].weight=arr[j+1].weight;
                arr[j+1].weight=temp;

                tempp=arr[j].rat;
                arr[j].rat=arr[j+1].rat;
                arr[j+1].rat=tempp;*/
                swap(arr[j].price,arr[j+1].price);
                swap(arr[j].weight,arr[j+1].weight);
                swap(arr[j].rat,arr[j+1].rat);
            }
        }
    }
    /*for(int i=0;i<n;i++){
        cout<<"price :   "<<arr[i].price<<endl;
        cout<<"weight:   "<<arr[i].weight<<endl;
        cout<<"ratio :   "<<arr[i].rat<<endl<<endl;
    }*/
    cout<<"\nMaximum profit knapsack can have: "<<fractional_knapsack(arr,capacity,n);
}
