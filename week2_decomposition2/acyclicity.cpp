#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool visited[1001];
bool inStack[1001];
void addEdge(vector<ll>adj[],ll a,ll b)
{
    adj[a].push_back(b);
}
bool isCycleUtil(vector<ll>adj[],ll s ,ll v)
{
    if(visited[s]==false)
    {
        visited[s]=true;
        inStack[s]=true;
        vector<ll>::iterator i;
        for(i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(!visited[*i]&&isCycleUtil(adj,*i,v))
            return true;
            else if(inStack[*i]==true)
            return true;
        }
    }
    inStack[s]=false;
    return false;
}

bool isCycle(vector<ll>adj[],ll v)
{
    for(ll i=0;i<v;i++)
    {
        visited[i]=false;
        inStack[i]=false;
    }
    for(ll i=0;i<v;i++)
    {
        if(isCycleUtil(adj,i,v))
        return true;
        
    }
    return false;
    
}
int main() {
    ll v,e;
    cin>>v>>e;
    vector<ll>adj[v];
    for(ll i=0;i<e;i++)
    {
        ll a,b;
        cin>>a>>b;
        addEdge(adj,a-1,b-1);
    }
    if(isCycle(adj,v))
    cout<<1<<"\n";
    else
    cout<<0<<"\n";
	
	return 0;
}