#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c,d;
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c>>d;
        int l=a,r=d;
        if(l==r)
        {
            l=b;
        }
        cout<<l<<" "<<r<<endl;
    }
    return 0;
}