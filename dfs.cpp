#include<iostream>
#include<vector>
using namespace std;
vector<int > t[100001];
vector <int> vis[100002];
void dfs(int u)
{   
	
	for(int i=0;i<t[u].size();i++)
	{   
		dfs(t[u][i]);
	}
}
int main()
{  
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m,u,v,cnt=2;
   cin>>n>>m;
   n--;
   while(n--)
   {  
   	 cin>>u;
   	 t[u].push_back(cnt);
   	 cnt++;
	}
	dfs(1);
 while(m--)	
 {  
 	cin>>u>>v;  
 
	 if(vis[u-1]<v)
	 cout<<"-1"<<endl;
	 else
	 cout<<vis[v-1]<<endl;
	vis.clear(); 	
  } 
return 0;	   	
}
