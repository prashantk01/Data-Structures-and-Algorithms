// dijkstra algorithm for finding shortest path
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

void take_input(int **graph,int n){
    cout<<"\nENTER TOTAL EDGES: ";
    int edge;
    cin>>edge;
    int u,v,dis;
    cout<<"\nENTER EDGE WITH WEIGHT: \n";
    for(int i=0;i<edge;i++){
            cin>>u>>v>>dis;
            graph[u][v]=dis;
            graph[v][u]=dis;
    }
}

void display(int distance[], int n){
    cout<<"Vertex \t\t Distance from Source\n";
    for (int i = 0; i < n; i++)
        cout<<i<<" \t\t "<<distance[i]<<endl;
}

int mimimum_distance(int n,int distance[],bool visited[]){
    int min_dist=INT_MAX;
    int min_idx=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && distance[i]<min_dist){
            min_idx=i;
            min_dist=distance[i];
        }
    }
    return min_idx;
}

int relax_graph(int min_dist_index,int distance[],bool visited[],int **graph,int n){
    for(int i=0;i<n;i++){
        if(graph[min_dist_index][i] && distance[i]>distance[min_dist_index]+graph[min_dist_index][i] && !visited[i] && distance[min_dist_index]!=INT_MAX)
            distance[i]=distance[min_dist_index]+graph[min_dist_index][i];
    }
}

void dijkstra(int **graph,int distance[],bool visited[], int n){
    int s;
    cout<<"\nEnter SOURCE: ";
    cin>>s;
    distance[s]=0;
    for(int i=0;i<n-1;i++){
        int min_dist=mimimum_distance(n,distance,visited);
        //cout<<"minimum ele "<<min_dist<<endl;
        visited[min_dist]=true;
        relax_graph(min_dist,distance,visited,graph,n);
        //display(distance,n);
    }
    display(distance,n);
}

int main(){
    int n;
    cout<<"ENTER NUMBER OF NODES IN GRAPH: ";
    cin>>n;
    int distance[n];
    bool visited[n];
    int **graph=new int*[n];
    for(int i=0;i<n;i++){
        graph[i]=new int[n];
        for(int j=0;j<n;j++){
            graph[i][j]=0;
        }
        distance[i]=INT_MAX;
        visited[i]=false;
    }
    take_input(graph,n);
    dijkstra(graph,distance,visited,n);
    return 0;
}
