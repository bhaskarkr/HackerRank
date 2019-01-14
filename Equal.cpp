#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector <int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        int a,b,c,d=(v[n-1])-v[0],ans=INT_MAX;
        for(int i=0;i<5;i++)
        {
            a=0;
            b=0;
            c=0;
            for(int j=0;j<n;j++)
            {
                a+=(v[j]-(v[0]-i))/5;
                b+=((v[j]-(v[0]-i))%5)/2;
                c+=((v[j]-(v[0]-i))%5)%2;
            }
            //cout<<a<<" "<<b<<" "<<c<<endl;
            if(ans>a+b+c)
                ans=a+b+c;
        }
        //cout<<"d "<<d<<endl;
        if(d==0)
            cout<<0<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}