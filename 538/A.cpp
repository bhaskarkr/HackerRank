#include <bits/stdc++.h>
using namespace std;
//for(int i=0;i<n;i++)
int main()
{
    int a,b,c,x,y,z;
    cin>>a>>b>>c>>x>>y>>z;
    bool ans = true;
    if(x>=a)
        x-=a;
    else 
        ans=false;
    if(y+x>=b)
    {
        y-=b;
    }
    else
    {
        ans=false;
    }
    if(x+y+z<c)
        ans=false;
    cout<<(ans?"YES":"NO")<<endl;
    return 0;
}