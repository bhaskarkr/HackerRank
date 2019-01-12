#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,d;
    cin>>n>>d;
    int c[205],in[200005];
    memset(c,0,sizeof(c));
    for(int i=0;i<d;i++)
    {    
        cin>>in[i];
        c[in[i]]++;
    }
    int ans=0;
    if (d%2==1)
    {
        for(int i=d;i<n;i++)
        {
            cin>>in[i];
            float m1=0,m2=0;
            for(int t=0,j=1;j<=200;j++)
            {
                t+=c[j];
                if(t>d/2)
                {
                    m1=j;
                    break;
                }
            }
            if(m1*2<=in[i])
                ans++;
            c[in[i-d]]--;
            c[in[i]]++;
        }
    }
    cout<<ans<<endl;
    return 0;
}