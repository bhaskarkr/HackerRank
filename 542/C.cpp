#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pii;
set<pii> A,B;
string s[51];
ll n,sx,sy,ex,ey;
bool v[51][51];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
void dfs(int x,int y,int ch)
{
    v[x][y]=true;
    if(ch==1)
        A.insert(mp(x,y));
    else
        B.insert(mp(x,y));
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<0||ny<0||nx>=n||ny>=n)
            continue;
        else if(!v[nx][ny]&&s[nx][ny]=='0')
            dfs(nx,ny,ch);
    }
}
int main()
{
    cin>>n>>sx>>sy>>ex>>ey;  
    sx--;
    sy--;
    ex--;
    ey--;
    for(int i=0;i<n;i++)
        cin>>s[i];
    dfs(sx,sy,1);

    if(A.find(mp(ex,ey))!=A.end())
    {
        cout<<0<<endl;
        return 0;
    }
    memset(v,false,sizeof(v));
    dfs(ex,ey,2);
    ll ans=INT_MAX;
    for(auto p:A)
    {
        for(auto q:B)
        {
            ans=min(ans,(p.first-q.first)*(p.first-q.first)+(p.second-q.second)*(p.second-q.second));
        }
    }
    //cout<<A.size()<<" "<<B.size()<<endl;
    cout<<ans<<endl;
    return 0;
}