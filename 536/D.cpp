#include <bits/stdc++.h>
using namespace std;
//for(int i=0;i<n;i++)
set<int> arr[100005]; 
#define long ll 
queue<int> stk;
set<int> seen;
void bfs()
{
    set<int> cur;
    cur.insert(1);
    while(!cur.empty())
    {
        auto it=cur.begin();
        stk.push(*it);
        seen.insert(*it);
        cur.erase(*it);
        for(auto next:arr[*it])
        {
            if(seen.find(next)==seen.end())
                cur.insert(next);
        }
    }
}
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        arr[a].insert(b);
        arr[b].insert(a);
    }
    bfs();
    while(!stk.empty())
    {
        cout<<stk.front()<<" ";
        stk.pop();
    }
    cout<<endl;
    return 0;
}