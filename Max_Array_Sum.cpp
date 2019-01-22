#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a=0,b=0,t,ans=0;
    cin>>n;
    while(n--)
    {
        cin>>t;
        if(t>0)
            ans=max(a+t,b);
        else
            ans=max(a,b);
        a=b;
        b=ans;
        //cout<<a<<" "<<b<<endl;
    }
    cout<<max(a,b)<<endl;
    return 0;
}