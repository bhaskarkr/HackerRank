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
    ll W,w,a,b,c,d,ans=0;
    cin>>a>>b>>c>>d;
    W=max(a,c);
    w=min(a,c);
    ans+=(W*2+b*2+d*2+4);
    cout<<ans<<endl;
    return 0;
}