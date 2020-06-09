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
vi g[100001];
vector<bool> vis;
vi tin,low;
vpii ans;
int timer;
void dfs(int v,int p=-1){
	vis[v]=true;
	tin[v]=low[v]=timer++;
	for(int x:g[v]){
		if(x==p) continue;
		if(vis[x]){
			low[v]=min(low[v],tin[x]);
		}
		else
		{
			dfs(x,v);
			low[v]=min(low[v],low[x]);
			if(low[x]>tin[v])
			{
				int a=x,b=v;
				if(a>b) swap(a,b);
				ans.pb(mp(a,b));
			}
		}
	}
}

void find_bridges(int n){
	timer=0;
	tin.assign(n+1,-1);
	low.assign(n+1,-1);
	vis.assign(n+1,false);
	for(int i=1;i<=n;i++){
		if(!vis[i])
		dfs(i);
	}
}

bool pp(pii x,pii y){
	if(x.ff==y.ff)
	return x.ss<y.ss;
	
	return x.ff<y.ff;
}
int main(){
    fastio;
    int t;
    cin>>t;
    while(t--){
    	  int n,q;
    cin>>n>>q;
    while(q--){
    	int u,v;
    	cin>>u>>v;
    	g[u].pb(v);
    	g[v].pb(u);
    }
  
    find_bridges(n);
    if(ans.size()==0) {
    	cout<<"-1\n";
    	 for(int i=1;i<=n;i++) g[i].clear();
    	continue;
    }
    sort(ans.begin(),ans.end(),pp);
    cout<<ans.size()<<"\n";
    for(pii x:ans) cout<<x.ff<<" "<<x.ss<<"\n";
    for(int i=1;i<=n;i++) g[i].clear();
    ans.clear();
    }
    return 0;
}
