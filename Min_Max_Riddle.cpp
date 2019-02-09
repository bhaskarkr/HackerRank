#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,max_curr=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    unordered_map<int,int> t;
    stack<int> L,R;
    for(int i=0;i<n;i++)
    {
        if(R.empty())
            R.push(i);
        else
        {
            if(v[R.top()]>=v[i])
            {
                int last_popped;
                while(!R.empty()&&v[R.top()]>=v[i])
                {
                    last_popped = R.top();
                    t[last_popped]=i-last_popped;
                    R.pop();
                }
            }
            R.push(i);
        } 
    }
    while(!R.empty())
    {

        int last_popped = R.top();
        t[last_popped]=n-last_popped;
        R.pop();
    }
    for(int i=n-1;i>=0;i--)
    {
        if(L.empty())
            L.push(i);
        else
        {
            if(v[L.top()]>=v[i])
            {
                int last_popped;
                while(!L.empty()&&v[L.top()]>=v[i])
                {
                    last_popped = L.top();
                    t[last_popped]+=(last_popped-i-1);
                    L.pop();
                }
            }
            L.push(i);
        }
    }
    while(!L.empty())
    {
        int last_popped = L.top();
        t[last_popped]+=last_popped;
        L.pop();
    }
    vector<int> win(n+2,1);
    for(int i=0;i<n;i++)
        win[t[i]]=max(win[t[i]],v[i]);
    for(int i=n;i>0;i--)
        win[i]=max(win[i],win[i+1]);
    for(int i=1;i<=n;i++)
        cout<<win[i]<<" "; 
    cout<<endl;
    return 0;
}