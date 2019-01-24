#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> s;
    string S;
    cin>>S;
    bool ans=false;
    for(char c:S)
    {
        if(!s.empty()&&s.top()==c)
        {    
            s.pop();
            ans=ans^true;
        }
        else
            s.push(c);
    }
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}