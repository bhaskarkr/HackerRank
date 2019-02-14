#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,n,m,u,v,color,ans=-1;
    cin>>n>>m;
    unordered_map<int, vector<int> > S;
    vector<int> V[n+1],Dist(n+1),par(n+1);
    vector<bool> vis(n+1,false);
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        V[u].push_back(v);
        V[v].push_back(u);
    }
    for(int i=0;i<n;i++)
    {
        cin>>a;
        par[i+1]=i;
        S[a].push_back(i+1);
    }
    cin>>color;
    bool found = false;
    queue<int> Q;
    for(auto a:S[color])
    {    
        Q.push(a);
        Dist[a]=0;
        vis[a]=true;
    }
    while(!Q.empty()&&!found)
    {
        int cur=Q.front();
        Q.pop();
        for(int i=0;i<V[cur].size();i++)
        {
            int k = V[cur][i];
            if(par[k]!=par[cur])
            {
                if(vis[k])
                {
                    found =true;
                    ans = Dist[cur]+Dist[k]+1;
                    break;
                }
                else
                {
                    Q.push(k);
                    vis[k]=true;
                    par[k]=par[cur];
                    Dist[k]=Dist[cur]+1;
                }
                
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}