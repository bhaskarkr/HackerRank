#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,ans=0;
    cin>>n;
    stack<pair<int,int> > S;
    for(int i=0;i<n;i++)
    {    
        cin>>a;
        int max_curr=0;
        while(!S.empty()&&S.top().first>=a)
        {
            max_curr=max(max_curr,S.top().second);
            S.pop();
        }
        if(S.empty())
            S.push(make_pair(a,0));
        else
        {
            ans=max(ans,max_curr+1);
            S.push(make_pair(a,max_curr+1));
        }     
    }
    cout<<ans<<endl;
    return 0;
}