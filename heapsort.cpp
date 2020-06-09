#include<iostream>
#include<algorithm>//for distance function
#include<cmath>//for logarithm function
using namespace std;
void swap(int *a,int *b)//to swap values
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void minheap(int key[],int index[],int l,int h)//function to create minheap which give smallest as node ,index array is for setting elements of value array
{       int i,c;
      if(h%2==0)//if h is even
	{	for( i=l-1;i<=(h/2-1);i++)
	   {  
	     c=(key[2*i+2]<key[2*i+1]?key[2*i+2]:key[2*i+1]);//minimum of 2 child node of a parent node
		 if((key[i]>c)&&((2*i+2)==h))//when child is last element
	     {   
		     swap(&index[i],&index[2*i+1]);//comparing the parent node with their child node and swapping ,if parent node is greater than child node.  
	    	 swap(&key[i],&key[2*i+1]);//swapping index array for setting index for value array.
	      }
	    if((key[i]>c)&&((2*i+2)!=h)) 
	    {  
		    swap(&index[i],&index[distance(key,find(key,key+h,c))]);//using distance function to find index of smallest child for index array
	        swap(&key[i],&(key[2*i+2]<key[2*i+1]?key[2*i+2]:key[2*i+1]));
	   }
	   }
	}
	else//if h is odd
	  {	for( i=l-1;i<=(h/2-1);i++)
	    {  c=(key[2*i+2]<key[2*i+1]?key[2*i+2]:key[2*i+1]);
		    
	    if(key[i]>c)
	    {  
		   swap(&index[i],&index[distance(key,find(key,key+h,c))]);
		   swap(&key[i],&(key[2*i+2]<key[2*i+1]?key[2*i+2]:key[2*i+1]));
		 }
      }}	
}
void heapsort(int key[],int index[],int l,int h)//heapsort function
{   if(h>l)
	{
	 
	for(int i=1;i<=(h);i++)//looping minheap upto no of levels of heap which is h
	{
	minheap(key,index,l,h);}
	 
	swap(&key[l-1],&key[h-1]);//swapping first and last element ,then removing last element by decreasing size of array
	swap(&index[l-1],&index[h-1]);
	h--;
	heapsort(key,index,l,h); //recursively calling this function until l=h.
    }
}
int main()
{    int n,key[100],value[100],index[100],i;
      cout<<"enter the no of element:";
      cin>>n;
 	for(i=0;i<n;i++)
	{cin>>key[i]>>value[i];
	 index[i]=i;
	}
	heapsort(key,index,1,n);
	if (key[0]<key[1])
	{   swap(&index[0],&index[1]);
		swap(&key[0],&key[1]);
	}
	
	for(int i=n-1;i>=0;i--)
	{ if((key[i]==key[i-1])&&(value[index[i]]>value[index[i-1]])) //swapping if having same key and bigger value has to be sorted
	   swap(&value[index[i]],&value[index[i-1]]);
	 
	cout<<"("<<key[i]<<","<<value[index[i]]<<")"<<endl;}
}
