#include <bits/stdc++.h>
using namespace std;
//for(int i=0;i<n;i++)
//for(int j=0;j<n;j++)
int main()
{
    int n,l,k,a,b;
    cin>>n>>l>>k;
    vector<int>  v(n-1);

    cin>>a;
    int f = a;
    
    for(int i=0;i<n-1;i++)
    {
        cin>>b;
        v[i]=b-a;
        a=b;
    }
    if(k>=n)
    {    
        cout<<n<<endl;
        return 0;
    }
    sort(v.begin(),v.end(),greater<int>());
    int ans = b-f+1;
    for(int j=0;j<k-1;j++)
    {
        ans-=(v[j]-1);
    }
    cout<<ans<<endl;
    return 0;
}