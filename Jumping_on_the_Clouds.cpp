#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a=-1,b=0,c,x=0,y=0,z;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>z;
            if(z==1)
                c=min(x==1?INT_MAX:a,y==1?INT_MAX:b);
            else
                c=min(x==1?INT_MAX:a,y==1?INT_MAX:b)+1;
            x=y;
            y=z;
            a=b;
            b=c;
    }
    cout<<b<<endl;
    return 0;
}