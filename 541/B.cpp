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
    ll n,ans=1,a,b;
    cin>>n;
    vector<pii> v(n+1);
    v[0]=mp(0,0);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].fi>>v[i].se;
        a=max(v[i-1].fi,v[i-1].se);
        b=min(v[i].fi,v[i].se);
        if(v[i].fi==v[i].se&&(v[i].fi!=v[i-1].fi||v[i].se!=v[i-1].se))
        {    
            ans++;
        }
        else if(v[i].fi==v[i-1].fi)
        {
            if(v[i-1].se<v[i].fi&&v[i].se>v[i].fi)
                ans+=1;
        }
        else if(v[i].se==v[i-1].se)
        {
            if(v[i-1].fi<v[i].se&&v[i].fi>v[i].se)
                ans+=1;
        }
        else if(b-a>0)
        {
            ans+=(b-a)+(v[i-1].fi!=v[i-1].se?1:0);
        }
        //cout<<ans<<endl;
    }
    if(v[n].fi==v[n].se&&v[n].se!=0)
        ans++;
    cout<<ans<<endl;
    return 0;
}
/*7
0 1
2 1
2 2
2 3
4 3
5 3
5 4
*/
