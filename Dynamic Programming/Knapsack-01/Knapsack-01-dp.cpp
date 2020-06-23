#include<iostream>
#include<stdlib.h>
using namespace std;

int Knapsack_dp(int weight[],int profit[],int n,int cap){
	int table[n+1][cap+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<cap+1;j++){
			if(i==0 || j==0)
				table[i][j]=0;
		}
	}	
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<cap+1;j++){
			if(weight[i-1] <= j){
				table[i][j]=max(profit[i-1]+table[i-1][j-weight[i-1]],table[i-1][j]);
			}
			else 
				table[i][j]=table[i-1][j];
		}
	}
	return table[n][cap];

}
int main(){
	int n,cap;
	cout<<"Enter no of objects: ";
	cin>>n;
	cout<<"Enter capacity of knapsack: ";
	cin>>cap;
	int weight[n],profit[n];
	int wt,pft;
	for(int i=0;i<n;i++){
		cin>>wt>>pft;
		weight[i]=wt;
		profit[i]=pft;
	}
	cout<<"The Max Profit is: "<<Knapsack_dp(weight,profit,n,cap)<<endl;
	return 0;
}
