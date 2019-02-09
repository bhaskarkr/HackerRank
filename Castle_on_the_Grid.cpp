#include <bits/stdc++.h>
using namespace std;
string s[101];
int n;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int sx,sy,ex,ey;
int bfs()
{
    bool visited[n][n];
    memset(visited,false,sizeof(visited));
    int cost[n][n];
    memset(cost,-1,sizeof(cost));
    queue<pair<int,int> > Q;
    Q.push(pair<int,int> (sx,sy));
    int c=0;
    cost[sx][sy]=0;
    visited[sx][sy]=true;
    while(!Q.empty())
    {
        c = Q.size();
        if(visited[ex][ey])
            break;
        while(c--)
        {
            pair<int,int> f=Q.front();
            Q.pop();
            int xx=f.first,yy=f.second;
            visited[xx][yy]=true;
            int X=xx,Y=yy;
            for(int i=0;i<4;i++)
            {
                xx=X;
                yy=Y; 
                while((xx+dx[i]>=0)&&(xx+dx[i]<n)&&(yy+dy[i]>=0)&&(yy+dy[i]<n)&&(!visited[xx+dx[i]][yy+dy[i]])&&s[xx+dx[i]][yy+dy[i]]!='X')
                {
                    Q.push(pair<int,int>(xx+dx[i],yy+dy[i]));
                    if(cost[xx+dx[i]][yy+dy[i]]==-1)
                        cost[xx+dx[i]][yy+dy[i]]=cost[X][Y]+1;
                    else
                        cost[xx+dx[i]][yy+dy[i]] = min(cost[xx+dx[i]][yy+dy[i]],cost[X][Y]+1);                    
                    xx=xx+dx[i];
                    yy=yy+dy[i];
                }
            }
        }
    }
    return cost[ex][ey];
}
int main()
{
    cin>>n;   
    for(int i=0;i<n;i++)
        cin>>s[i];
    cin>>sx>>sy>>ex>>ey;    
    cout<<bfs()<<endl;;
    return 0;
}