#include<iostream>
using namespace std;
void swap (int *a,int *b)//function for swapping values
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void countingsort(int key[],int value[],int a,int size) //key ,value  and their size as argument
{
	int i,l,h,ind[1000],count[1000],sumcount[1000],sort[100],index[100];
	h=key[0];l=key[0];
	for(i=a+1;i<=size;i++)//to find the lowest value in key
	{   
	    if(l>key[i])
		l=key[i];
	}
	for(i=a+1;i<=size;i++)//to find the highest value in key
	{if(h<key[i])
		h=key[i];	
	}
	for(i=0;i<h-l+1;i++)//creating ind array from range low to high value in key
	ind[i]=l+i;
	for(i=a;i<=h;i++)//initializing count and sumcount arrays
	{ 
	 sumcount[i]=0;
	 count[i]=0;
	}
	for(i=a;i<=size;i++)//storing frequency of occurence of elements in key 
	count[key[i]]++;
	
	for(i=l;i<=h;i++)//summing the frequncy with previous elements frequencies
	sumcount[i]=sumcount[i-1]+count[i];
	
	for(i=a;i<=size;i++)//storing the values of key & value arrays in new arrays in sorted manner.
	{ 
	index[sumcount[key[i]]-1]=value[i];//elements of sumcount array gaves the sorted position of key array and stores the value in sort array 
	sort[sumcount[key[i]]-1]=key[i];    //and index array sets the value for value array acoording to their key.
	  
	  sumcount[key[i]]--;	//decreasing the frequency after setting value in sorted place,so that repetition of numbers also placed in correct order.
	}
	for(int i=a;i<=size;i++)
 	{ if((sort[i]==sort[i+1])&&(index[i]>index[i+1]))//checking for same key for different value and swapped them for sorted array
	  {swap(&index[i],&index[i+1]);}
	  
	  cout<<"("<<sort[i]<<","<<index[i]<<")"<<endl;}
}
int main()
{    int n,key[100],value[100],i;
       cout<<"enter no of elements:";
      cin>>n;
 	for(i=0;i<n;i++) ///input key and value
	cin>>key[i]>>value[i];
	 
	countingsort(key,value,0,n-1);//sorting function

}
