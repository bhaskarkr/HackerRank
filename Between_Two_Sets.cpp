#include<bits/stdc++.h>
using namespace std;
long long  gcd(long long a,long long b)
{
    long long c=a%b;
    while(c)
    {
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}

int main()
{
    long long n,m,a;
    cin>>n>>m;
    long long lcm=1,hcf=1;
    cin>>lcm;
    for(int i=1;i<n;i++)
    {
        cin>>a;
        lcm = (lcm*a)/gcd(lcm,a);
    }
    cin>>hcf;
    for(int i=1;i<m;i++)
    {
        cin>>a;
        hcf = gcd(hcf,a);
    }
    int ans=0,t=lcm;
    while(lcm<=hcf)
    {
        ans+=(hcf%lcm==0?1:0);
        lcm+=t;
    }
    cout<<ans<<endl;
    return 0;
}