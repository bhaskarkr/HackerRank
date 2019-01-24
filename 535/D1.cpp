#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0;
    cin>>n;
    string s;
    cin>>s;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
        {
            ans++;
            if(s[i-1]=='R'&&s[i+1]!='G')
                s[i]='G';
            else if(s[i-1]=='R'&&s[i+1]!='B')
                s[i]='B';
            else if(s[i-1]=='G'&&s[i+1]!='B')
                s[i]='B';
            else if(s[i-1]=='G'&&s[i+1]!='R')
                s[i]='R';
            else if(s[i-1]=='B'&&s[i+1]!='R')
                s[i]='R';
            else
                s[i]='G';
        }
    }
    cout<<ans<<"\n"<<s<<endl;
    return 0;
}