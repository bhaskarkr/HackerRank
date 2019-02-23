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
    ll n,ans=0;
    cin>>n;
    vector<ll> v(n+1,0),odd(n+1,0),even(n+1,0);
    for(int i=1;i<=n;i++)
    {    
        cin>>v[i];
        if(i%2)
        {    
            odd[i]+=odd[i-1]+v[i];
            even[i]=even[i-1];
        }
        else
        {
            odd[i]=odd[i-1];
            even[i]=even[i-1]+v[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
            if(odd[i-1]+even[n]-even[i]==even[i-1]+odd[n]-odd[i])
                ans++;
        
    }
    cout<<ans<<endl;
    return 0;
}