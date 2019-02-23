#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll h,w,ans=0;
    cin>>h>>w;
    ans=h*w*2;
    ll v[h][w];
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin>>v[i][j];
    for(int i=0;i<h;i++)
            ans+=v[i][0]+v[i][w-1];
    for(int i=0;i<w;i++)
            ans+=v[0][i]+v[h-1][i];       
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(i>0)
                ans+=abs(v[i-1][j]-v[i][j]);
            if(j>0)
                 ans+=abs(v[i][j-1]-v[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}