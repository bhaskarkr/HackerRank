#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,m;
    cin>>n>>m;
    vector<ll> coin(m),DP(n+1,0);
    for(int i=0;i<m;i++)
        cin>>coin[i];
    DP[0]=1;
    for(int j=0;j<m;j++)
        for(int i=1;i<=n;i++)
            if(coin[j]<=i)
                DP[i]+=DP[i-coin[j]];
    cout<<DP[n]<<endl;
    return 0;
}