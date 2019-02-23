#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        string s[n];
        for(int i=0;i<n;i++)
            cin>>s[i];
        cin>>a>>b;
        string p[a];
        for(int i=0;i<a;i++)
            cin>>p[i];
        bool ans = false;
        for(int i=0;i<=n-a&&!ans;i++)
        {
            for(int x=0,y=0,j=0;j<=m-b&&!ans;j++)
            {
                bool cur=true;
                for(x=0;x<a&&cur;x++)
                {
                    for(y=0;y<b&&cur;y++)
                    {
                        if(s[i+x][j+y]!=p[x][y])
                        {
                            cur=false;
                            break;
                        }
                    }
                }
                if(x==a&&y==b)
                {
                    ans=true;
                    break;
                }
            }
        }
        cout<<(ans?"YES":"NO")<<endl;
    }
    return 0;
}