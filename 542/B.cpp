#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pii;
int main()
{
    ll n,a,y=0,x=0;
    unordered_map<ll,ll> u,v;
    cin>>n;
    for(int i=0;i<2*n;i++)
    {
        cin>>a;
        if(u[a]==0)
            u[a]=i+1;
        else
            v[a]=i+1;
    }
    ll p=1,q=1;
    for(int i=1;i<=n;i++)
    {
        if(abs(u[i]-p)+abs(v[i]-q)<=abs(v[i]-p)+abs(u[i]-q))
        {
            x+=abs(u[i]-p);
            y+=abs(v[i]-q);
            p=u[i];
            q=v[i];
            
        }
        else
        {
            x+=abs(v[i]-p);
            y+=abs(u[i]-q);
            p=v[i];
            q=u[i];
            
        }
        //cout<<x<<" "<<y<<endl;
    }
    cout<<x+y<<endl;
    return 0;
}