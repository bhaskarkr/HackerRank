#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long dp1[n+1],in[n+1];
    cin>>in[1];
    dp1[1]=1;
    dp1[n]=1;
    for(int i=2;i<=n;i++)
    {
        cin>>in[i];
        if(in[i]>in[i-1])
            dp1[i]=dp1[i-1]+1;
        else    
            dp1[i]=1;
    }
    long long  sum=dp1[n];
    for(int i=n-1;i>=1;i--)
    {
        if(in[i]>in[i+1] && dp1[i]<=dp1[i+1])
            dp1[i]=dp1[i+1]+1;    
        sum+=dp1[i];
    }
    cout<<sum<<endl;
    return 0;
}