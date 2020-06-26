#include<iostream>
#include<stdlib.h>
using namespace std;

void take_input(int **graph,int edge){
	cout<<"Enter edge with weight: \n";
	int u,v,wt;
	for(int i=0;i<edge;i++){
		cin>>u>>v>>wt;
		graph[u][v]=wt;
		graph[v][u]=wt;
	}				
}
void display(int **graph,int n) {  
    cout<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";  
    for (int i = 0; i < n; i++)  
    {  
        for (int j = 0; j < n; j++)  
        {  
            if (graph[i][j] == 0)  
                cout<<"INF"<<"     ";  
            else
                cout<<graph[i][j]<<"     ";  
        }  
        cout<<endl;  
    }  
}  

void floyd_warshall(int **graph,int n){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
			if(k !=j && graph[j][k] > graph[j][i] + graph[i][k])
				graph[j][k] = graph[j][i] + graph[i][k];
			
		
	display(graph,n);
}

int main(){

	int n;
	cout<<"Enter No. of vertex: ";
	cin>>n;
	cout<<"Enter no of edges: ";
	int edge;
	cin>>edge;
	int **graph=new int*[n];
	for(int i=0;i<n;i++){
		graph[i]=new int[n];
		for(int j=0;j<n;j++)
			graph[i][j]=0;
	}	
	take_input(graph,edge);
	floyd_warshall(graph,n);
	return 0;
}

