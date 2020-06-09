#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvl vector<vll>
#define pb push_back
#define mp make_pair
#define vpii vector<pair<int,int> >
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(false) , cin.tie(NULL) ,cout.tie(NULL) 
using namespace std;
ll t[200011]={};
void build(ll a[],ll v,ll tl,ll tr)
{
	if(tl==tr){
		t[v]=a[tl];
	}
	else{
		ll tm=(tl+tr)>>1;
		build(a,v+1,tl,tm);
		build(a,v+2*(tm-tl+1),tm+1,tr);
		
		t[v]=max(t[v+1] , t[v+2*(tm-tl+1)]);
	}
}
ll sum(ll v,ll tl,ll tr,ll l,ll r){
	
	if(l>r) return 0;
	if(l==tl&&r==tr) return t[v];
	
	ll tm=(tl+tr)>>1;
	return sum(v+1,tl,tm,l,min(r,tm)) + sum(v+2*(tm-tl+1),tm+1,tr,max(l,tm+1),r);
}
ll maxm(ll v,ll tl,ll tr,ll l,ll r){
	
	if(l>r) return INT_MIN;
	if(l==tl&&r==tr) return t[v];
	
	ll tm=(tl+tr)>>1;
	return max(maxm(v+1,tl,tm,l,min(r,tm)) ,maxm(v+2*(tm-tl+1),tm+1,tr,max(l,tm+1),r));
}
void update(ll v,ll tl,ll tr,ll p,ll x){
	
	if(tl==tr) t[v]=x;
	
	else{
		int tm = (tl+tr)>>1;
		if(p<=tm)
		  update(v+1,tl,tm,p,x);
		  else
		  update(v+2*(tm-tl+1),tm+1,tr,p,x);
		  
		t[v]=t[v+1]+t[v+2*(tm-tl+1)];  
	}
}
int main(){
    fastio;
    
    ll a[10]={};
    for(int i=0;i<8;i++)
    cin>>a[i];
    build(a,1,0,7);
    
 //   cout<<sum(1,0,7,1,7)<<endl;
 //   update(1,0,7,2,-2);
//    for(int i=1;i<=15;i++)
    cout<<maxm(1,1,8,1,5)<<" ";
    return 0;
}
