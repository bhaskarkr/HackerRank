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
    ll t,a,n,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        cout<<min(a*n,(n/2)*b+(n%2)*a)<<endl;
    }
    return 0;
}