#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvl vector<vll>
#define pb push_back
#define mp make_pair
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vpii vector<pii >
#define vpll vector<pll >
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(false) , cin.tie(NULL) ,cout.tie(NULL) 

using namespace std;
vi g[100001],gt[100001];
vector<bool> vis;
vi order,comp;
void dfs1(int v){
	vis[v]=true;
	for(int x:g[v]){
		if(!vis[x])
		dfs1(x)
	}
	order.pb(v);
}
void dfs1(int v){
	vis[v]=true;
	for(int x:g[v]){
		if(!vis[x])
		dfs1(x)
	}
	order.pb(v);
}
void dfs2(int u){
	vis[u]=true;
	comp.pb(u);
	for(int x:g[u]){
		if(!vis[x])
		dfs2(x);
	}
}
int main(){
    fastio;
    int n,u,v,m;
    cin>>n>>m;
    while(m--){
    	cin>>u>>v;
    	g[u].pb(v);
    	gt[v].pb(u);
    }
    vis.assign(n+2,false);
    for(int i=1;i<=n;i++)
    if(!vis[i])
    dfs1(i);
    
    vis.assign(n+2,false);
    for(int i=0;i<n;i++)
    {
    	int v=order[n-i-1];
    	if(!vis[v])
    	dfs2(v);
    	
    	for(int i:comp) cout<<i<<" ";
    	comp.clear();
    }
    return 0;
}
