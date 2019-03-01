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
    ll p=0,nn=0;
    double a,n;
    cin>>n;
    for(int i=0;i<ll(n);i++)
        {
            cin>>a;
            if(a>0)
                p++;
            if(a<0)
                nn++;

        }
    if (p>=ceil(n/2))
        cout<<1<<endl;
    else if(nn>=ceil(n/2))
        cout<<-1<<endl;
    else
    {
        cout<<0<<endl;
    }
    
    return 0;
}