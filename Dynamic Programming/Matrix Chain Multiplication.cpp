//MATRIX CHAIN MULTIPLICATION BY DP
#include<iostream>
#include<stdlib.h>
using namespace std;

void printParenthesis(int i, int j, int n,int *bracket, char &name) 
{ 
    if (i == j) 
    { 
        cout << name++; 
        return; 
    } 
  
    cout << "("; 
    printParenthesis(i, *((bracket+i*n)+j), n,bracket, name); 
    printParenthesis(*((bracket+i*n)+j) + 1, j,n, bracket, name); 
    cout << ")"; 
}
int matrix_chain_mult(int dimension[], int n){

	//0th row and column will not be used
	int cost[n+1][n+1];           //to store mult cost
	int track_bracket[n+1][n+1];  // to track the bracket  
	
	//cost for single matrix multiplication
	for(int i=0;i<=n;i++)
		cost[i][i]=0;
	/* m[i,j] = Minimum number of scalar multiplications 
        needed to compute the matrix A[i]A[i+1]...A[j] = 
        A[i..j] where dimension of A[i] is p[i-1] x p[i] */
	for (int len =2 ;len<n+1;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=len+i-1;
			cost[i][j]=INT32_MAX;
			for(int k=i;k<=j-1;k++){
               			int cst = cost[i][k] + cost[k+1][j] + dimension[i-1]*dimension[k]*dimension[j]; 
                		if (cst < cost[i][j]) 
                		{ 
                		    cost[i][j] = cst; 
                		    track_bracket[i][j] = k; 
				}
			}
		}
	}
    	char name = 'A';   
    	cout << "Optimal Parenthesization is : "; 
    	printParenthesis(1, n, n+1, (int *)track_bracket, name); 
        cout << "\nOptimal Cost is : " << cost[1][n];
}

int main(){
	int n;
	cout<<"Enter total matix to multiply: ";
	cin>>n;
	int dimension[n+1];
	cout<<"Enter dimension: ";
	for(int i=0;i<=n;i++)
		cin>>dimension[i];
	cout<<"dimension is: ";
	for(int i=0;i<=n;i++)
		cout<<dimension[i];
	cout<<endl;
	matrix_chain_mult(dimension,n);
	cout<<endl;
	return 0;
}
