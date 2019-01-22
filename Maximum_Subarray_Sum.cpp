#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n,k,q;
    cin>>q;
    while(q--)
    {
        cin>>n>>k;
        set<long> s;
        long ans=0,prefix=0,v;
        for(int i=0;i<n;i++)
        {    
            cin>>v;
            prefix=(prefix+v%k)%k;
            ans=max(ans,prefix);
            auto p=s.lower_bound(prefix+1);
            if(p!=s.end())
                ans=max(ans,prefix-*p+k);        
            s.insert(prefix);
        }
        cout<<ans<<endl;
    }
    return 0;
}