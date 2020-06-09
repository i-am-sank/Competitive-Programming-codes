#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;
ull binpower( ull a,ull b,ull p)
{
   ull res=1;
   a=a%p;
   while(b>0){
   if(b&1)
   res*=a%p;
   a=a*a%p;
   b>>=1;
   }
   return res;
}

bool check_composite(ull n, ull a, ull d, int s) {
    ull x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(ull n, int iter=5) { 
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    ull d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

     for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}
int main(){
int t;
ull n;
cin>>t;
while(t--){
cin>>n;

if(MillerRabin(n,5))
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
}
return 0;
}
   
