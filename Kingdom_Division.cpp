#include<bits/stdc++.h>
using namespace std;
vector<int> vec[100005];
#define mod 1000000007
long child_same_color[100005][2],child_any_configuration[100005][2];
void dfs(int curr,int parent)
{
    for(auto child:vec[curr])
    {
        if(child!=parent)
            dfs(child,curr);
    }
    child_same_color[curr][0]=child_same_color[curr][1]=1;
    for(auto child:vec[curr])
    {
        if(child!=parent)
        {
            child_same_color[curr][0]=(1LL*child_same_color[curr][0]*child_any_configuration[child][1])%mod;
            child_same_color[curr][1]=(1LL*child_same_color[curr][1]*child_any_configuration[child][0])%mod;
        }
    }
    child_any_configuration[curr][0]=child_any_configuration[curr][1]=1;
    for(auto child:vec[curr])
    {
        if(child!=parent)
        {
            child_any_configuration[curr][0]=(1LL*child_any_configuration[curr][0]*(child_same_color[child][0]+child_any_configuration[child][0]+child_any_configuration[child][1]))%mod;
            child_any_configuration[curr][1]=(1LL*child_any_configuration[curr][1]*(child_same_color[child][1]+child_any_configuration[child][0]+child_any_configuration[child][1]))%mod;
        }
    }
    child_any_configuration[curr][0] = (child_any_configuration[curr][0] - child_same_color[curr][0]+mod)%mod;
    child_any_configuration[curr][1] = (child_any_configuration[curr][1] - child_same_color[curr][1]+mod)%mod;
}
int main()
{
    int n,a,b;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        a--;
        b--;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(0,-1);
    cout<<(child_any_configuration[0][1]+child_any_configuration[0][0])%mod<<endl;
    return 0;
}