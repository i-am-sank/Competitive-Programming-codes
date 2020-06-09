#include<bits/stdc++.h>
using namespace std;

void sieveoferatosthenes(long long int n)
{
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
   long long int i,p,count=0;
	for(i=2;i*i<=n;i++)
	{
		if(prime[i])
		{
			for(p=i*i;p<=n;p+=i)
			prime[p]=false;
		}
	}
	
	for(i=2;i<=n;i++)
	if(prime[i])
	count++,cout<<i<<" ";
	
	cout<<endl<<count;
}
int main()
{
	long long int n;
	cin>>n;
	sieveoferatosthenes(n);
}
