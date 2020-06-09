#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[100],k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	int l=0,r=n-1,ans=n;
	while(l<=r)
	{
		int mid=l+r;
		mid>>=1;
		
		if(a[mid]>=k)
		r=mid-1,ans=mid;
		else
		l=mid+1;
	}
	cout<<ans+1;
}
