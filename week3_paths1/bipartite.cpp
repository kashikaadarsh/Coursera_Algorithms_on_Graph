#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>adj[100000];

ll v,e;
bool isBipartite(ll src) 
{ 
    ll colour[v]; 
    for (ll i = 0; i < v; ++i) 
        colour[i] = -1; 
  
  
    colour[src] = 1; 
  
    queue <int> q; 
    q.push(src); 
    while (!q.empty()) 
    { 
        
        ll u = q.front(); 
        q.pop(); 
  
        
       vector<ll>::iterator x;
        
        for ( x = adj[u].begin();x!=adj[u].end(); ++x) 
        { 
            
            if (colour[*x] == -1) 
            { 
                
                colour[*x] = 1 - colour[u]; 
                q.push(*x); 
            } 
  
            else if (colour[*x] == colour[u]) 
                return false; 
        } 
    } 
   
    return true; 
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
	if(isBipartite(0))
	cout<<1;
	else
	cout<<0;
	return 0;
}