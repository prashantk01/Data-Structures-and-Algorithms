#include<iostream>
#include<stdlib.h>
using namespace std;

int Knapsack_Recursion(int weight[],int profit[],int n, int cap){
	if(n==0 || cap==0)
		return 0;
	if(weight[n-1] <= cap){
		return max(profit[n-1]+Knapsack_Recursion(weight,profit,n-1,cap-weight[n-1]),
				       Knapsack_Recursion(weight,profit,n-1,cap));
	}
	else
		return Knapsack_Recursion(weight,profit,n-1,cap);
}

int main(){
	int n;
	cout<<"Enter total objects: ";
	cin>>n;
	cout<<"Enter capacity of Knapsack: ";
	int cap;
	cin>>cap;
	int weight[n];
	int profit[n];
	cout<<"Enter weight and profit for objects: \n";
	int wt,pft;
	for(int i=0;i<n;i++){
		cin>>wt>>pft;
		weight[i]=wt;
		profit[i]=pft;
	}
	cout<<"\nMax Profit is: "<<Knapsack_Recursion(weight,profit,n,cap)<<endl;
}
