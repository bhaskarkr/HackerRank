#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int ans=1;
    sort(v.begin(),v.end());
    int prev=v[0];
    for(int i=1;i<n;i++)
    {
        if(v[i]-prev>4)
        {
            prev=v[i];
            ans++;
        }    
    }
    cout<<ans<<endl;
    return 0;
}