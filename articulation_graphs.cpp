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
vi g[100010];
vector<bool> visited;
vector<int> tin, low,ans;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                ans.pb(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        ans.pb(v);
}

void find_cutpoints(int n) {
    timer = 0;
    ans.clear();
    visited.assign(n+1, false);
    tin.assign(n+1, -1);
    low.assign(n+1, -1);
    for (int i = 1; i <=n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}


int main(){
    fastio;
    int n,m;
    cin>>n>>m;
    while(m--){
    	int u,v;
    	cin>>u>>v;
    	g[u].pb(v);
    	g[v].pb(u);
    }
    find_cutpoints(n);
    cout<<ans.size();
    return 0;
}
