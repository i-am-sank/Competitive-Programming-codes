#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int n,a[100],i,j;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	for(j=0;j<n-1;j++)
	{
		if(a[j]>a[j+1])
		swap(a[j],a[j+1]);
	}
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}
