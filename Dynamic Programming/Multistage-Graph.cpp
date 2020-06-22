/*A Multistage graph is a directed graph in which the nodes can be divided into a set of stages such that all edges are from a stage to next stage only (In other words there is no edge between vertices of same stage and from a vertex of current stage to previous stage). */
// Solved with Dynamic Programming
// 1.Initialize from last vertex and make dis =0
// 2. then for every i(vertex )in decreasing order.... visit all vrtex(conditionally...for value greater than i and in not same //stage as definitaion of problem) and find min distance among  all alloutgoing edge distance and assign that to vertex

#include<iostream>
#include<stdlib.h>
using namespace std;

void take_input(int **graph,int n,int e){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			graph[i][j]=0;
		}
	}	
	cout<<"Enter edges with weight: ";
	int u,v,w;
	for(int i=0;i<e;i++){
	cin>>u>>v>>w;
	graph[u][v]=w;
	}
}

int Multistage_Graph(int **graph, int n){
	int distance[n];
	for(int i=0;i<n;i++){
		distance[i]=INT32_MAX;
	}
	distance[n-1]=0;
	for(int i=n-2;i>=0;i--){
		int min_dis=INT32_MAX;
		for(int j=i;j<n;j++){
			if(graph[i][j]){
				distance[i]=graph[i][j]+distance[j];
				if (distance[i] < min_dis){
					min_dis=distance[i];
				}
				else
					distance[i]=min_dis;
			}
		}	
	}
	return distance[0];
}

int main(){
	int n;
	cout<<"Enter No. of vertex in graph: ";
	cin>>n;
	cout<<"Enter No. of edges in graph: ";
	int e;
	cin>>e;
	int **graph;
	graph=new int*[n];
	for(int i=0;i<n;i++)
		graph[i]=new int [n];
	take_input(graph,n,e);
	int val=Multistage_Graph(graph,n);
	cout<<"\nMin distance is: "<<val;
	cout<<endl;
	return 0;
}
