#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b,n;
    cin>>n;
    ll ans=0;
    unordered_map<ll,ll> par,c;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if(par[a]==0)
        {
            par[a]=a;    
            c[a]++;
        }
        if(par[b]==0)
        {
            par[b]=b;    
            c[b]++;
        }
        ll f = par[a];
        while(par[f]!=f)
            f=par[f];
        ll t = par[b];
        while(par[t]!=t)
            t=par[t];
        ll fin = min(f,t),trn=max(f,t);
        if(fin!=trn)
        {
            c[fin]+=c[trn];
            par[trn]=par[fin];
            c[trn]=0;
        }
        cout<<(ans=max(ans,c[fin]))<<endl;       
    }
    return 0;
}