#include<bits/stdc++.h>
using namespace std;
vector<int > z_function_trivial(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i =1 ,l=0,r=0; i < n; ++i)
    {
    	if(i<=r)
    	z[i]=min(r-i+1,z[i-l]);
		    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        
       if(i+z[i]-1>r)
	   l=i,r=i+z[i]-1;
	        
    }
    return z;
}
int main(){
	string s,p;
	cin>>s;
	cin>>p;
	s=p+"@"+s;
   vector<int > o;
   o=z_function_trivial(s);
   for(int i=p.size();i<o.size();i++)
   {
   	  //cout<<o[i]<<" ";
   	  if(o[i]==p.size())
   	  cout<<i-p.size()<<" ";
   }
   
}
