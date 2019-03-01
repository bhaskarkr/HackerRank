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
    ll n,C,a,b;
    cin>>n>>C;
    vector<ll> mindist(n,INT_MAX),slot(n,-1),c(n,0);
    for(int i=0;i<C;i++)
    {
        cin>>a>>b;
        a--;
        b--;
        c[a]++;
        if(a>b)
            b+=n;
        mindist[a]=min(mindist[a],b-a);
    }
    ll mx=0;
    for(int i=0;i<n;i++)
    {
        if(c[i]>0)
        {    
            slot[i]=i+(c[i]-1)*n;
            mx=max(mx,slot[i]+mindist[i]);
        }
    }
    vector<ll> ans(n);
    for(int i=0;i<n;i++)
    {
        ans[i]=mx-i;
        if(c[i]>0)
        {
            mx=max(mx,slot[i]+n+mindist[i]);
        }
    }
    for(auto k:ans)
        cout<<k<<" ";
    cout<<endl;
    return 0;
}