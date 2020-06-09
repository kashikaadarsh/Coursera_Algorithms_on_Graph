#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define test ll t;cin>>t;while(t--)
#define NIL -1

class Graph
{
    int v;
    vector<pair<ll,ll>> adj[100000];
    public:
    Graph(ll v);
    void addEdge(ll u,ll v,ll wt);
    void shortestPath(ll src,ll dest);
};
Graph::Graph(ll v)
{
    this->v=v;
    vector<pair<ll,ll>> adj[v];
}
void Graph::addEdge(ll u,ll v,ll wt)
{
    adj[u].push_back(make_pair(v,wt));
}
void Graph::shortestPath(ll src,ll dest)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    ll dist[v];
    for(ll i=0;i<v;i++)
    dist[i]=INT_MAX;
    pq.push(make_pair(0,src));
    dist[src]=0;
    while(!pq.empty())
    {
        ll u=pq.top().second;
        pq.pop();
        vector<pair<ll,ll>>::iterator x;
        for(x=adj[u].begin();x!=adj[u].end();x++)
        {
            ll v=(*x).first;
            ll wt=(*x).second;
            if(dist[v]>dist[u]+wt)
            { 
                dist[v]=dist[u]+wt;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
   /*for (ll i = 0; i < v; ++i) 
        printf("%lld \t\t %lld\n", i, dist[i]);*/
        if(dist[dest]==INT_MAX)
        cout<<"-1\n";
        else
        cout<<dist[dest]<<"\n";
    
}
int main() {
    ll v,e;
    cin>>v>>e;
    Graph g(v);
    for(ll i=0;i<e;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        g.addEdge(a-1,b-1,c);
    }
    
    ll src,dest;
    cin>>src>>dest;
    g.shortestPath(src-1,dest-1);
    
	return 0;
}