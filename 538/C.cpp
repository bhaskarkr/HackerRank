#include <bits/stdc++.h>
using namespace std;
//for(int i=0;i<n;i++)
long long  n,b;
long long calc(long long a)
{
    long long res = 0,k=n;
    while(k)
    {
        res+=k/a;
        k/=a;
    }
    return res;
}
int main()
{
    
    cin>>n>>b;
    map<long long,long long> mp;
    for(int i=2;i*i<=b;i++)
    {
        while(b%i==0)
        {
            mp[i]++;
            b/=i;
        }
    }
    if(b!=1)
        mp[b]++;
    long long ans=8e18; 
    for(auto a:mp)
    {
        ans=min(ans,calc(a.first)/a.second);
    }
    cout<<ans<<endl;
    return 0;
}