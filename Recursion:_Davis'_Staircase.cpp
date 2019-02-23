#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    vector<long long> v(37,0);
    v[0]=1;
    for(int i=1;i<=36;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(i-j>=0)
                v[i]=(v[i]+v[i-j])%10000000007;
        }
    }
    while(cin>>n)
        cout<<v[n]<<endl;
    return 0;
}