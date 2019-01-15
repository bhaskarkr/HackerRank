#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k,a;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int c=0;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(a<=0)
                c++;
        }
        if(c>=k)
            cout<<"NO\n";
        else    
            cout<<"YES\n";
    }
    return 0;
}