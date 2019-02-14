#include <bits/stdc++.h>
using namespace std;
bool vis[10][10];
int X[]={0,1,1,1,0,-1,-1,-1},Y[]={1,1,0,-1,-1,-1,0,1},n,m,ans=0;
char s[10][10];
int DFS(int x,int y)
{   
    int temp=1;
    for(int i=0;i<8;i++)
    {
        int nx=x+X[i],ny=y+Y[i];
        if(nx>=0&&ny>=0&&nx<n&&ny<m&&s[nx][ny]=='1'&&!vis[nx][ny])
        {
            vis[nx][ny]=true;
            temp+=DFS(nx,ny);
        }
    }
    return temp;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)    
            cin>>s[i][j];
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='1'&&!vis[i][j])
            {
                vis[i][j]=true;    
                ans=max(ans,DFS(i,j));
            }
        }
    cout<<ans<<endl;
    return 0;
}