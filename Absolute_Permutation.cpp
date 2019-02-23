#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        vector<ll> v(n+1);
        bool ans = true;
        vector<bool> vis(n+1,false);
        for(int i=1;i<=n;i++)
            v[i]=i;
        for(int i=1;i<=n&&ans;i++)
        {
            if(i-k>0&&!vis[i-k])
                v[i]-=k;
            else if(i+k<=n&&!vis[i+k])
                v[i]+=k;
            else
            {
                ans=false;
                break;
            }
            vis[v[i]]=true;
        }
        if(ans)
        {
            for(int i=1;i<=n;i++)
                cout<<v[i]<<" ";
            cout<<endl;
        }
        else
            cout<<-1<<endl;
    }
    return 0;
}