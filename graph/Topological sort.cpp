//TOPOLOGICAL SORT USING EXTRA STACK SIMILAR ON DFS
#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stack>
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
    //for directed graph
    graph->Adj[u][v]=1;
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


void TPL(struct Graph *graph, int u, stack<int>& sp){
    visited[u]=1;
    for(int i=0;i<graph->v;i++){
        if(graph->Adj[u][i]==1 && visited[i]==0){
            TPL(graph,i,sp);
        }

    }
    sp.push(u);
}

void TOPOLOGICAL_SORT(struct Graph *graph){
    for(int i=0;i<graph->v;i++){
        visited[i]=0;
    }
    stack<int>sp;
    //in case there are unconnected components
    for(int i=0;i<graph->v;i++){
        if(visited[i]==0)
            TPL(graph,i,sp);
    }
    while(!sp.empty()){
        cout<<" "<<sp.top();
        sp.pop();
    }
}


//GFG
//We can modify DFS to find Topological Sorting of a graph.
//In DFS, we start from a vertex, we first print it and then recursively call DFS for its adjacent vertices. In topological sorting,
// we use a temporary stack. We don’t print the vertex immediately, we first recursively call topological sorting for all its adjacent vertices, then push it to a stack. Finally, print contents of stack
int main(){
    Graph *graph;
    graph=createGraphAM(graph);
    display(graph);
    cout<<"Topological sort: ";
    TOPOLOGICAL_SORT(graph);

return 0;
}
