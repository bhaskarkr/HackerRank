#include <bits/stdc++.h>
using namespace std;
long long  par[100005];
set<long long > S[100005];
int main()
{
    long long  q,n,m,croad,clib,u,v;
    cin>>q;
    while(q--)
    {
        cin>>n>>m>>clib>>croad;
        for(int i=1;i<=n;i++)
        {    
            par[i]=i;
            S[i].clear();
            S[i].insert(i);
        }
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            if(par[u]!=par[v])
            {
                long long  fin_par = min(par[u],par[v]);
                long long transfer = max(par[u],par[v]);
                for(auto &s:S[transfer])
                {
                    S[fin_par].insert(s);
                    par[s]=fin_par;
                }
                S[transfer].clear();
                par[u]=par[v]=fin_par;
            }
        }
       long long ans = 0;
        for(int i=1;i<=n;i++)
            if(S[i].size()>0)
                ans+=(S[i].size()-1)*croad+clib;
        cout<<min(ans,1LL*clib*n)<<endl;
    }
    return 0;
}