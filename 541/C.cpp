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
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    deque<int> Q;
    for(int i=n-1;i>=0;i--)
    {
        Q.push_back(v[i]);
        i--;
        if(i>=0)
            Q.push_front(v[i]);
    }
    for(auto a:Q)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}