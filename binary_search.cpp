#include<iostream>
using namespace std;
int main()
{
	int n;
	int a[10]={1,2,3,4,5,6,8,100,456};
	cin>>n;
	
	int l=0,r=8,mid;
	while(l<=r)
	{
		 mid=l+r;
		mid>>=1;
		if(a[mid]<n)
		l=mid+1;
		else if(a[mid]>n)
		r=mid-1;
		else
		break;
	}
	cout<<mid;
}
