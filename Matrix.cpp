#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int> > > C(n-1);
    vector<bool> red(n,false);
    vector<set<int>> V(n);
    vector<int> par(n);
    for(int i=0;i<n-1;i++)
    {   
        cin>>C[i].second.first>>C[i].second.second>>C[i].first;
         V[i].insert(i);
        par[i]=i;
    }
    V[n-1].insert(n-1);
    par[n-1]=n-1;
    for(int i=0;i<m;i++)
    {
        cin>>a;
        red[a]=true;
    }
    sort(C.begin(),C.end(),greater<pair<int,pair<int,int> > >());
    long long ans=0,u,v,c;
    for(int i=0;i<n-1;i++)
    {
        u=C[i].second.first,v=C[i].second.second,c=C[i].first;
        if(red[par[u]]&&red[par[v]])
            ans+=c;
        else
        { 
            int fin_set=min(par[u],par[v]);
            int tran_set=max(par[u],par[v]);
            if(red[par[u]]||red[par[v]])
                red[fin_set]=true;
            for(auto X:V[tran_set])
            {    
                V[fin_set].insert(X);
                par[X]=fin_set;
            }
            V[tran_set].clear();
        }
    }
    cout<<ans<<endl;
    return 0;
}