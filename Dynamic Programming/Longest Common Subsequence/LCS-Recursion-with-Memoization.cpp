//problem of Overlapping Substructure property and recomputation of same subproblems can be avoided by either using Memoization or //Tabulation
//Time Complexity: O(N * M), where N and M is length of the first and second string respectively.
#include<iostream>
#include<stdlib.h>
using namespace std;
const int maximum = 1000; 
int LCS_Recursion_with_Memoization(int table[][maximum],string X, string Y, int m, int n){
		if(m==0 || n==0)
			return 0;
		if(table[m-1][n-1]!= -1)
			return table[m-1][n-1];
		if(X[m-1] == Y[n-1]){
			table[m-1][n-1]= 1+ LCS_Recursion_with_Memoization(table,X,Y,m-1,n-1);
			return table[m-1][n-1];
		}
		else{	
			int p=LCS_Recursion_with_Memoization(table,X,Y,m-1,n);
			int q=LCS_Recursion_with_Memoization(table,X,Y,m,n-1);
			table[m-1][n-1]=max(p,q);
			return table[m-1][n-1];
		}
}
int main(){
	    string X = "AGGTAB"; 
	    string Y = "GXTXAYB"; 
	    int m = X.length(); 
	    int n = Y.length(); 
            int table[m][maximum];
            for(int i=0;i<m;i++){
            		for(int j=0;j<n;j++){
            				table[i][j]=-1;
            		}
            }
            cout<<"Length of LCS is: "<<LCS_Recursion_with_Memoization(table,X,Y,m,n)<<endl;
            
	return 0;
}
