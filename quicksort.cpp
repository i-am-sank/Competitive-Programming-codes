#include<iostream>
using namespace std;
void swap (int *a,int *b)//to swap numbers
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int key[],int index[],int l,int h)
{ int i,j,pivot;
  pivot=key[h];//initialising pivot as  last element
 i=l-1;
 for(j=l;j<h;j++)
 {
 	if(key[j]<=pivot)//shifting the values which are smaller than pivot to left and shifting the values which are higher than pivot to right.
 	{i++;
 	swap(&key[i],&key[j]);
	swap(&index[i],&index[j]);}//doing same operations with index array so that value array gets set according to key array 
 }
 swap(&key[i+1],&key[h]);//shifting the pivot to correct place .
 swap(&index[i+1],&index[h]);
 return (i+1) ;	//returns partitioning element
}
void quicksort(int key[],int index[],int l,int h)
{
	if(l<h)
	{
	int	p=partition(key,index,l,h);
	quicksort(key,index,l,p-1);//sorting the partitioned arrays
	quicksort(key,index,p+1,h);
	}
}
int main()
{    int n,key[100],value[100],index[100],i;
      cin>>n;
 	for(i=0;i<n;i++)
	{cin>>key[i]>>value[i];
	 index[i]=i;
	}
	quicksort(key,index,0,n-1);
	
	for(int i=0;i<n;i++)
	{ if((key[i]==key[i+1])&&(value[index[i]]>value[index[i+1]]))//swapping values with same key
	   swap(&value[index[i]],&value[index[i+1]]);
	cout<<"("<<key[i]<<","<<value[index[i]]<<")"<<endl;}
}
