#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> pii;
int main()
{
    ll n,m,a;
    cin>>n;
    map<ll,vector<pii> > M;
    vector<ll> p(n);
    for(int i = 0;i<n;i++)
        cin>>p[i];
    for(int i = 0;i<n;i++)
    {
        cin>>a;
        M[a].pb(mp(2,p[i]));
    }
    cin>>m;
    vector<ll> P(m);
    for(int i=0;i<m;i++)
        cin>>P[i];
    for(int i=0;i<m;i++)
    {
        cin>>a;
        M[P[i]-a].pb(mp(1,i));
        M[P[i]+a+1].pb(mp(-1,i));
    }
    set<ll> active;
    ll light=0;
    vector<ll> singlecloud(m,0);
    for(auto pos:M)
    {
        sort(pos.second.begin(),pos.second.end());
        for(auto pair:pos.second)
        {
            if(pair.first==-1)
            {
                active.erase(pair.second);
            }
            else if(pair.first==1)
            {
                active.insert(pair.second);
            }
            else
            {
                if(active.size()==0)
                {
                    light+=pair.second;
                }
                else if(active.size()==1)
                {
                    singlecloud[*active.begin()]+=pair.second;
                }
            }
        }
    }
    ll ans=0;
    for(auto k:singlecloud)
        if(k>ans)
            ans=k;
    cout<<ans+light<<endl;
    return 0;
}