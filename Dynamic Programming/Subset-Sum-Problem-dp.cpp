#include<iostream>
#include<stdlib.h>
using namespace std;

bool subset_sum(int weight[],int n,int sum){
	
	//RECURSIVE CODE 
	/*if(sum==0)
		return true;
	if(n==0 && sum!=0)
		return false;
	if(weight[n-1] <= sum)
		return (subset_sum(weight,n-1,sum-weight[n-1]) || subset_sum(weight,n-1,sum));
	else
		return subset_sum(weight,n-1,sum);
	*/
	
	bool table[n+1][sum+1];
	for (int i = 0; i <= n; i++)
        	table[i][0] = true; 
    	for (int i = 1; i <= sum; i++) 
        	table[0][i] = false; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(weight[i-1] <= j)
				table[i][j]=(table[i-1][j-weight[i-1]] || table[i-1][j]);
			else
				table[i][j]=table[i-1][j];
		}
	}
	return table[n][sum];
}

int main(){
	int n,sum;
	cout<<"Enter No. element in weight array: ";
	cin>>n;
	cout<<"Enter value for sum: ";
	cin>>sum;
	int weight[n+1];
	cout<<"Enter weight array: ";
	for(int i=0;i<n;i++)
		cin>>weight[i];
	if(subset_sum(weight,n,sum)==true)
		cout<<"YES!!..SUBSET EXIST";
	else
		cout<<"NO!!..SUBSET DOESNT EXIST";
	cout<<endl;
	return 0;
}
