#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool visited[100001];
bool inStack[1001];
stack<ll>st;
void addEdge(vector<ll>adj[],ll a,ll b)
{
    adj[a].push_back(b);
}
bool topologicalSortUtil(vector<ll>adj[],ll s ,ll v)
{
     visited[s]=true;
        
        vector<ll>::iterator i;
        for(i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(!visited[*i])
            {
                
                topologicalSortUtil(adj,*i,v);
            }
    }
    st.push(s);
}

void topologicalSort(vector<ll>adj[],ll v)
{
    for(ll i=0;i<v;i++)
    {
        visited[i]=false;
    }
    for(ll i=0;i<v;i++)
     {
         if(!visited[i])
         topologicalSortUtil(adj,i,v);
     }
    while(!st.empty())
    {
        cout<<st.top()+1<<" ";
        st.pop();
    }
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
    topologicalSort(adj,v);
	
	return 0;
}