#include <bits/stdc++.h>
using namespace std;
long gcd(long a,long b)
{
    long c=a%b;
    while(c>0)
    {
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    long prev=v[n-1],a=1,b=v[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(b%v[i]!=0||prev==v[i])
        {
            if(a%v[i]==0)
            {
                continue;
            }
            else
            {
                a=(a*v[i])/gcd(a,v[i]);
            }
        }
        //cout<<v[i]<<" "<<a<<" "<<b<<endl;
        prev=v[i];
        //cout<<v[i]<<" "<<a<<" "<<b<<endl;
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}