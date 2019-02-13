#include <bits/stdc++.h>
using namespace std;
//for(int i=0;i<n;i++)
bool comp(pair<int,int> a,pair<int,int> b)
{
    return a.second<b.second;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int > > v(n);
    for(int i=0;i<n;i++)
    {    
        cin>>v[i].first;
        v[i].second = i;
    }
    sort(v.begin(),v.end(),greater<pair<int,int> >());
    sort(v.begin(),v.begin()+m*k,comp);

    long long int sum=0;
    for(int i=0;i<m*k;i++)
        sum+=1LL*v[i].first;
    cout<<sum<<endl;;
    for(int i=m-1;i<m*k-1;i+=m)
        cout<<v[i].second+1<<" ";
    cout<<endl;
    return 0;
}