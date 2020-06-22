// Time Complexity of the implementation is O(mn) 
// Dynamic Programming implementation of LCS problem 
#include<iostream>
#include<stdlib.h>
using namespace std;
void LCS_DP(string X,string Y,int m,int n){
	int table[m+1][n+1];
	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++){
			if(i==0 || j==0)
				table[i][j]=0;
			else if(X[i-1] == Y[j-1])
				table[i][j]=1+table[i-1][j-1];
			else
				table[i][j]=max(table[i][j-1],table[i-1][j]);
		}
	}
	cout<<"\nThe Length of LCS:  "<<table[m][n]<<endl;
	cout<<"The LCS of "<<X<<" and "<<Y<<" is :  ";
	int i=m,j=n;
	int idx = table[m][n]; 
   	char print_lcs[idx+1]; 
	print_lcs[idx] = '\0';
	while(i >0 & j>0){
		if(X[i-1] == Y[j-1]){
		print_lcs[idx-1]=X[i-1];
		i--;
		j--;
		idx--;
		}
		else if(table[i-1][j] > table[i][j-1])
			i--;
		else
			j--;
	}
	cout<<print_lcs;	
}


int main(){
	string X = "PRASHANT"; 
	string Y = "PRINCE"; 
	int m = X.length(); 
	int n = Y.length();
	LCS_DP(X,Y,m,n);
	cout<<endl;
	return 0;
}
