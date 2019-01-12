#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k;
    cin>>n>>k;
    vector<long long> v(n),pos(n+1);
    for(int i=0;i<n;i++)
    {    
        cin>>v[i];
        pos[v[i]]=i;
    }
    for(int i=0;i<n&&k>0;i++)
    {
        if(v[i]!=n-i)
        {
            v[pos[n-i]]=v[i];
            pos[v[i]]=pos[n-i];
            v[i]=n-i;
            k--;         
        }
    }    
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}