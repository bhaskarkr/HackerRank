#include <bits/stdc++.h>
using namespace std;
//for(int i=0;i<n;i++)

#define long ll 
int main()
{
    double n,k,m;
    double sum=0,avg;
    cin>>n>>k>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {    
        cin>>v[i];
        sum+=v[i];
    }
    sort(v.begin(),v.end());
    if(m>k*n)
        m=k*n;
    avg=(sum+m)/n;
    //cout<<avg<<endl;
    int i=0;
    while(m--&&i<n-1)
    {
        sum-=v[i];
        avg=max(avg,(sum+(m>(n-1-i)*k?(n-1-i)*k:m))/(n-1-i));
        //cout<<avg<<endl;
        i++;

    }
    printf("%lf\n",avg);
    return 0;
}