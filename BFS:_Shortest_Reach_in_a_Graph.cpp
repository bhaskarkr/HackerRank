#include <bits/stdc++.h>
using namespace std;
int main()
{
    int u,v,t,n,m,start;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<int> Dist(n+1,-1);
        vector<int> V[n+1];
        vector<bool> vis(n+1,false);
        queue<int> Q;
        for(int i = 0;i<m;i++)
        {
            cin>>u>>v;
            V[u].push_back(v);
            V[v].push_back(u);
        }
        cin>>start;
        Dist[start]=0;
        Q.push(start);
        while(!Q.empty())
        {
            int cur = Q.front();
            Q.pop();
            for(int i=0;i<V[cur].size();i++)
            {
                if(!vis[V[cur][i]])
                {
                    Dist[V[cur][i]]=Dist[cur]+6;
                    vis[V[cur][i]]=true;
                    Q.push(V[cur][i]);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(i!=start)
                cout<<Dist[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}