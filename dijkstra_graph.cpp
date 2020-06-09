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
const int INF = 1e9;
vpii g[100010];
vi p(100002,-1),d(100002,INF);
priority_queue<pii ,vpii ,greater<pii>> q;
void dijkstra(int s){
	d[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int v=q.top().ss;
		int len=q.top().ff;
		q.pop();
		if(len!=d[v])
		continue;
		
		for(pii x: g[v]){
			if(d[v]+x.ss<d[x.ff])
			{
				d[x.ff]=x.ss+d[v];
				p[x.ff]=v;
				q.push({d[x.ff],x.ff});
			}
		}
	}
}

vector<int> restore_path(int s, int t) {
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}

int main(){
    fastio;
    int n,m;
    cin>>n>>m;
    while(m--){
    	int u,v,l;
    	cin>>u>>v>>l;
    	g[u].pb({v,l});
    	g[v].pb({u,l});
    }
    dijkstra(1);

    vi a=restore_path(1,n);
    for(int i:a ) cout<<i<<" ";
    return 0;
}
