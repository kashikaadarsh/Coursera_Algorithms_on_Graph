// A simple representation of graph using STL 
#include<bits/stdc++.h> 
using namespace std; 

// A utility function to add an edge in an 
// undirected graph. 
void addEdge(vector<int> adj[], int u, int v) 
{ 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 

// A utility function to print the adjacency list 
// representation of graph 

void isReachable(vector<int>adj[],bool visited[],int u,int V)
{
    visited[u]=true;
    vector<int>::iterator i;
    for( i=adj[u].begin();i!=adj[u].end();i++)
    {
        if(visited[*i]==false)
        {
            isReachable(adj,visited,*i,V);
        }
    }
}
int connectedComponents(vector<int>adj[],int V)
{
    bool *visited= new bool[V];
    for(int i=0;i<V;i++)
    visited[i]=false;
    int c=0;
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            isReachable(adj,visited,i,V);
            c++;
        }
    }
    return c;
}

// Driver code 
int main() 
{ 
	//int V = 5; 
	int V,e;
	cin>>V>>e;
	//cout<<V<<e;
	vector<int> adj[V];
	for(int i=0;i<e;i++)
	{
	    int a,b;
	    cin>>a>>b;
	    //cout<<a<<b;
	    addEdge(adj, a-1, b-1);
	}
	  cout<<connectedComponents(adj,V);
	  
	  //printGraph(adj,V);
	return 0; 
} 
