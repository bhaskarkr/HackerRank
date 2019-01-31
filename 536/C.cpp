#include <bits/stdc++.h>
using namespace std;
//for(int i=0;i<n;i++)
 
int main()
{
    int n;
    cin>>n;
    vector<long> v(n);
    for(int i=0;i<n;i++)
    {   
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    unsigned long long int sum=0;
    for(int i=0;i<n/2;i++)
    {
        sum+=(1LL*(v[i]+v[n-1-i]))*(v[i]+v[n-1-i]);
    }
    cout<<sum<<endl;
    return 0;
}