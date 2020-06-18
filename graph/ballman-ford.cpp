#include<stdio.h>
#include<iostream>
#include<stdlib.h>
//#include<conio.h>
using namespace std;

void take_input(int source[],int destination[],int weight[],int edge){
    int u,v,dis;
    cout<<"\nENTER EDGE WITH WEIGHT: \n";
    for(int i=0;i<edge;i++){
            cin>>u>>v>>dis;
            source[i]=u;
            destination[i]=v;
            weight[i]=dis;
    }
}

void display(int distance[], int n){
    cout<<"Vertex \t\t Distance from Source\n";
    for (int i = 0; i < n; i++)
        cout<<i<<" \t\t "<<distance[i]<<endl;
}

void bellman_ford(int source[],int destination[],int weight[],int distance[],int edge, int n){
    int s;
    cout<<"\nEnter SOURCE: ";
    cin>>s;
    distance[s]=0;
    for(int i=0;i<n-1;i++){
    	for(int j=0;j<edge;j++){
    		int src=source[j];
    		int des=destination[j];
    		int wght=weight[j];
    		if( distance[src]+wght < distance[des])
    			distance[des]=distance[src]+wght;
    	}
    	//display(distance,n);
    }
    
    for(int j=0;j<edge;j++){
    	int src=source[j];
    	int des=destination[j];
    	int wght=weight[j];
    	if( distance[src]+wght < distance[des]){
    		cout<<"NEGATIVE EDGE FOUND...CANT LOOK SHORTEST PATH FOR ALL";
    		return;
    	}
    }
    display(distance,n);
} 

int main(){
    int n;
    cout<<"ENTER NUMBER OF NODES IN GRAPH: ";
    cin>>n;
    cout<<"\nENTER TOTAL EDGES: ";
    int edge;
    cin>>edge;
    int destination[edge];
    int source[edge];
    int distance[n];
    int weight[edge];
    for(int j=0;j<edge;j++){
        weight[j]=0;
        source[j]=-1;
        destination[j]=-1;
    }
    for(int i=0;i<n;i++){
    	distance[i]=INT8_MAX;
    }
    take_input(source,destination,weight,edge);
    bellman_ford(source,destination,weight,distance,edge,n);
    return 0;
}

