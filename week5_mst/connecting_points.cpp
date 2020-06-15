#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define test ll t;cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define input1(n) ll n;cin>>n;
struct edge
{
    ll u,v;
    double d;
};
struct SET
{
    ll p;
    ll r;
};
double distance(pair<ll,ll> p1,pair<ll,ll> p2)
{
    double d=sqrt(pow(p1.first-p2.first,2)+pow(p1.second-p2.second,2))*1.0;
    return d;
}
bool compare(edge e1,edge e2)
{
    return e1.d<e2.d;
}
ll root(SET s[],ll a)
{
    if(s[a].p!=a)
     s[a].p=root(s,s[a].p);
    return s[a].p;
}
void Union(SET s[],ll a,ll b)
{
    if(s[a].r<s[b].r) s[a].p=b;
    else if(s[a].r>s[b].r) s[b].p=a;
    else s[a].p=b,s[b].r++;
}
void kruskal(edge e[],ll k,ll n,vector<ll> &v)
{
    ll i;
    SET s[n+5];
    for(i=0;i<n;i++) s[i].p=i,s[i].r=0;
    for(i=0;i<k;i++)
    {
        ll x=root(s,e[i].u);
        ll y=root(s,e[i].v);
        if(x!=y)
        {
            v.pb(i);
            Union(s,x,y);
        }
    }
}
int main() 
{
	fast;
	ll i,j,k;
	input1(n);
	pair<ll,ll> p[n+1];
	for(i=0;i<n;i++) 
	cin>>p[i].first>>p[i].second;
	edge e[n*n+1];
	k=0;
	for(i=0;i<n;i++)
	 for(j=i+1;j<n;j++)
	 {
	     e[k].u=i;
	     e[k].v=j;
	     e[k++].d=distance(p[i],p[j]);
	 }
	sort(e,e+k,compare);
	vector<ll> v;
	kruskal(e,k,n,v);
	double ans=0.0;
	for(i=0;i<v.size();i++) ans+=e[v[i]].d;
	cout<<fixed<<setprecision(7)<<ans<<"\n";
	return 0;
}