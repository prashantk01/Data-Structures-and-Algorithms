//SHORTEST PATH FROM SOURCE TO ALL VERTEX IN DIRECTED ACYCLIC GRAPH (DAG)
//TOPOLOGICAL SORT USING EXTRA STACK SIMILAR ON DFS
//IN DAG SHORTEST ALGO: 
//............1. FOR EVERY VERTEX IN TOPOLOGICAL ORDER
//............2. FOR ALL ADJACENT VERTEX OF PICKED ONE...RELAX EACH EDGE
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
    int u,x,w;
    cout<<"Reading edge with weight: ";
    cin>>u>>x>>w;
    //for directed graph
    graph->Adj[u][x]=w;
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
void display_distance(int distance[],struct Graph *graph){
    cout<<"\nVertex \t\t Distance from Source\n";
    for (int i = 0; i < graph->v; i++)
        cout<<i<<" \t\t "<<distance[i]<<endl;
}

void TPL(struct Graph *graph, int u, stack<int>& sp){
    visited[u]=1;
    for(int i=0;i<graph->v;i++){
        if(graph->Adj[u][i]!=0 && visited[i]==0){
            TPL(graph,i,sp);
        }

    }
    sp.push(u);
}

void TOPOLOGICAL_SORT(struct Graph *graph){
    int distance[graph->v];
    for(int i=0;i<graph->v;i++){
        visited[i]=0;
        distance[i]=INT32_MAX;
    }
    stack<int>sp;
    //in case there are unconnected components
    for(int i=0;i<graph->v;i++){
        if(visited[i]==0)
            TPL(graph,i,sp);
    }
    int src;
    cout<<"\nEnter source: ";
    cin>>src;
    distance[src]=0;
    cout<<"Topological sort: ";
    //NOW GRAPH IS SORTED ACCORDING TO TOPOLIGICAL SORT AND PUSHED INTO STACK
    //PICK A VERTEX AND RELAX ALL OUTGOING EDGES TO THE FRONT VERTEX
    while(!sp.empty()){
        int u=sp.top();
        cout<<" "<<u;

        //here relaxation will work for each vertex as graph is topological sorted
        for(int i=0;i<graph->v;i++){
        	if(graph->Adj[u][i] !=0 && distance[u]+graph->Adj[u][i] < distance[i]){
        		distance[i]=distance[u]+graph->Adj[u][i];
        	}
        }
        sp.pop();
    }
    display_distance(distance,graph);
    cout<<endl;
}

//WHEN GRAPH IS TOPOLOGICALLY SORTED THEN PICK SOURCE AND RELAXE EACH ADJACENT VERTEX
//IT ALSO WORK FOR NEGATIVE EDGE GRAPH
int main(){
    Graph *graph;
    graph=createGraphAM(graph);
    display(graph);
    TOPOLOGICAL_SORT(graph);

return 0;
}
