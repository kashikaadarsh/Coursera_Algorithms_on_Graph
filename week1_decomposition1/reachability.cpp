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
int isRechable(vector<int>adj[],int u,int v,int V)
{
    if(u==v)
    return 1;
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
    visited[i]=false;
    vector <int>::iterator i;
    visited[u]=true;
    queue <int> q;
    q.push(u);
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        for(i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(*i==v)
            return 1;
            else
            {
                if(!visited[*i])
                {
                     visited[*i] = true; 
                      q.push(*i); 
                }
            }
        }
        
    }
    return 0;
    
}
void printGraph(vector<int> adj[], int V) 
{ 
    for (int v = 0; v < V; ++v) 
    { 
        cout << "\n Adjacency list of vertex "
             << v << "\n head "; 
        for (auto x : adj[v]) 
           cout << "-> " << x; 
        printf("\n"); 
    } 
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
	 int u,v;
	 cin>>u>>v;
	  if(isRechable(adj,u-1, v-1,V))
	  cout<<1;
	  else
	  cout<<0;
	  //printGraph(adj,V);
	return 0; 
} 
