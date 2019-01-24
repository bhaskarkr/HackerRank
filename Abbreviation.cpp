#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        string A,B;
        cin>>A>>B;
        unordered_map<char,int> ua,ub,uc;
        bool ans=true;
        for(char c:B)
            ub[c]++;
        
        for(char a:A)
        {
            if(a<='Z')
                ua[a]++;
            else
                uc[char(a-32)]++;
        }
        for(auto u:ua)
        {   
            if(u.second>ub[u.first])
            {
                ans=false;
                break;
            }
            uc[u.first]+=u.second;
        }    
        for(auto u:ub)
        {
            if(u.second>uc[u.first])
            {
                ans=false;
                break;
            }
        }
        cout<<(ans?"YES":"NO")<<endl;
    }
    return 0;
}