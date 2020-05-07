#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

//creation of graph using adjacency matrix
struct Graph{
    int v;
    int e;
    int  **Adj;
};

int visited[10];
struct Graph *createGraphAM(struct Graph *graph){
    graph=new Graph;
    cout<<"Enter number of vertices: ";
    cin>>graph->v;
    cout<<"Enter number of edges: ";
    cin>>graph->e;
    graph->Adj=new int*[graph->v];
    for(int i=0;i<graph->v;i++){
        graph->Adj[i]=new int [graph->v];
    }
    for(int i=0;i<graph->v;i++){
        for(int j=0;j<graph->v;j++){
        graph->Adj[i][j]=0;
        }
    }
    for(int i=0;i<graph->e;i++){
    int u,v;
    cout<<"Reading edge: ";
    cin>>u>>v;
    //for undirected graph
    graph->Adj[u][v]=1;
    graph->Adj[v][u]=1;
    }
    return graph;
}


void display(struct Graph *graph){
    cout<<"The adjacency matrix corresponding to graph entered is: \n";
    for(int i=0;i<graph->v;i++){
        for(int j=0;j<graph->v;j++){
            cout<<" "<<graph->Adj[i][j];
        }
        cout<<"\n";
    }
}


void BFS_TRAVERSAL(struct Graph *graph,int v)
{

    queue<int>q;
    int u;
    q.push(v);
    visited[v]=1;
    while(!q.empty()){
        u=q.front();
        q.pop();
        cout<<" "<<u;
        for(int i=0;i<graph->v;i++){
            if(graph->Adj[u][i]==1 && visited[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}


struct Graph *BFS(struct Graph *graph){
    for(int i=0;i<graph->v;i++)
        visited[i]=0;

    //or you can ask user to enter starting node
    int n;
    cout<<"\nEnter starting node: ";
    cin>>n;
    BFS_TRAVERSAL(graph,n);

    //in case there are unconnected components
    for(int i=0;i<graph->v;i++){
        if(visited[i]==0)
            BFS_TRAVERSAL(graph,i);
    }
}

void DFS_TRAVERSAL(struct Graph *graph, int v){
    visited[v]=1;
    cout<<" "<<v;
    for(int i=0;i<graph->v;i++){
        if(graph->Adj[v][i]==1 && visited[i]==0)
            DFS_TRAVERSAL(graph,i);
    }
}

void DFS(struct Graph *graph){
    for(int i=0;i<graph->v;i++){
        visited[i]=0;
    }

    //or you can ask user to enter starting node
    int n;
    cout<<"\nEnter starting node: ";
    cin>>n;
    DFS_TRAVERSAL(graph,n);

    //in case there are unconnected components
    for(int i=0;i<graph->v;i++){
        if(visited[i]==0)
            DFS_TRAVERSAL(graph,i);
    }
}


int main(){
    Graph *graph;
    graph=createGraphAM(graph);
    display(graph);
    cout<<"\nBFS traversal is : ";
    BFS(graph);
    cout<<"\nDFS traversal is : ";
    DFS(graph);
return 0;
}
