#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>adj[100000];
ll dist[100000];

ll v,e;
bool minPath(ll src,ll dest) 
{ 
    bool visited[v];
    for(ll i=0;i<v;i++)
    {
        visited[i]=false;
        dist[i]=INT_MAX;
    }
    //cout<<src;
    visited[src]=true;
    queue <int> q; 
    q.push(src); 
    dist[src]=0;
    while (!q.empty()) 
    { 
        
        ll u = q.front(); 
        q.pop(); 
  
        vector<ll>::iterator x;
        
        for ( x =adj[u].begin();x!=adj[u].end(); ++x) 
        { 
            if(!visited[*x])
            {
                visited[*x]=true;
                dist[*x]=dist[u]+1;
                q.push(*x);
                 if(*x==dest)
                   return true;
            }
           
        }
    } 
   
    return false;
} 
  
int main() {
	cin>>v>>e;
	for(ll i=0;i<v;i++)
	adj[i].clear();
	
	for(ll i=0;i<e;i++)
	{
	    ll a,b;
	    cin>>a>>b;
	    adj[a-1].push_back(b-1);
	    adj[b-1].push_back(a-1);
	}
	ll src,dest;
	cin>>src>>dest;
	ll cnt=0;
	ll x=minPath(src-1,dest-1);
	//for(ll i=0;i<v;i++)
	//cout<<dist[i]<<" ";
	if(x==false)
	cout<<-1;
	else
	cout<<dist[dest-1];
	return 0;
}