 //The general recursive solution of the problem is to generate all subsequences of both given sequences
 // and find the longest matching subsequence. 
 //Total possible combinations will be 2n. Hence recursive solution will take O(2n).
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <bits/stdc++.h> 
using namespace std;


int LCS_Recursion(char *x,char *y, int m, int n){
	if(m==0|| n==0)
		return 0;
	if (x[m-1]==y[n-1])
		return 1+LCS_Recursion(x,y,m-1,n-1);
	else
		return max(LCS_Recursion(x,y,m-1,n),LCS_Recursion(x,y,m,n-1));
}

int main(){
	 char X[] = "AGGTAB";  
         char Y[] = "GXTXAYB";    
    	 int m = strlen(X);  
	 int n = strlen(Y);
	 cout<<"\nLength of LCS is: "<<LCS_Recursion(X,Y,m,n)<<endl;
	 return 0;
}
