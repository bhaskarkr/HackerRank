#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end(),greater<long long>());
    bool ans=false;
    long long a=-1,b=-1,c=-1,d;
    for(int i=0;i<n-2;i++)
    {
        a=v[i];
        b=v[i+1];
        d=a-b;
        //cout<<"d "<<d<<endl;
        if(v[i+2]>d)
        {    
            c=v[i+2];
            ans=true;
            break;
        }    
    }
    if(ans)
        cout<<a<<" "<<b<<" "<<c<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
