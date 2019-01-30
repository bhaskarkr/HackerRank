#include <bits/stdc++.h>
using namespace std;
#define RI(k) cin>>k
#define RII(a , b) cin>>a>>b
#define LOOPi(n) for(int i=0;i<n;i++)
#define LOOPj(m) for(int j=0;j<m;j++)
#define LOOPabk(a,b) for(int k=a;k<=b;k++)
#define F first
#define S second
#define MAX 1e5+5
typedef pair < pair<int,int> ,int > ppiii;
typedef vector< pair <pair<int,int>,int > > VIII;
typedef vector<int> VI;
int ans,n,m;;
VI a(MAX);
void solve()
{
    int mn=INT_MAX,mx=INT_MIN;
    LOOPi(n)
    {
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
    }
    ans=mx-mn;
}
multiset<ppiii> temp,Ans;
int main()
{
    int ANS=INT_MIN;
    cin>>n>>m;
    VIII seg(m);
    LOOPi(n)
        RI(a[i]);
    solve();
    LOOPi(m)
    {   
        RII(seg[i].F.F,seg[i].F.S);
        seg[i].S=i;
    }
    sort(seg.begin(),seg.end());
    int now=0;
    LOOPi(n)
    {
        while(now<m&&seg[now].F.F-1==i)
        {
            LOOPabk(seg[now].F.F-1,seg[now].F.S-1)
                a[k]--;
            solve();
            int p = seg[now].F.F;
            seg[now].F.F=seg[now].F.S;
            seg[now].F.S=p;
            temp.insert(seg[now]);
            now++;
        }
        while(temp.size()&&(*temp.begin()).F.F==i)
        {
            LOOPabk((*temp.begin()).F.S-1,(*temp.begin()).F.F-1)
                a[k]++;
            solve();
            temp.erase(temp.begin());
        }
        if(ans>ANS)
        {
            Ans=temp;
            ANS=ans;
        }
    }
    cout<<ANS<<endl;
    set<int> sol;
    for(auto t:Ans)
        sol.insert(t.S+1);
    cout<<sol.size()<<endl;
    for(auto t:sol)
        cout<<t<<" ";
    cout<<endl;
    return 0;
}