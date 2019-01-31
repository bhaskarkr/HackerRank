#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    bool palin=true;
    vector<bool> updated(n,false);
    for(int i=n/2-1;i>=0;i--)
    {
        if(s[i]!=s[n-i-1])
        {
           if(k>0)
           {
               k--;
               char m=max(s[i],s[n-i-1]);
               if(s[i]==m)
                    updated[n-i-1]=true;
                else
                    updated[i]=true;
               s[n-i-1]=s[i]=m;
           } 
           else
           {
               palin=false;
               break;
           }
        }
    }
    for(int i=0;k>0&&i<n/2;i++)
    {
        if(s[i]!='9')
        {
            if(updated[i]||updated[n-1-i])
            {
                s[i]=s[n-1-i]='9';
                k--;
            }
            else if(k>1)
            {
                s[i]=s[n-1-i]='9';
                k-=2;
            }
        }
    }
    if(k>0)
        s[n/2]='9';
    if(!palin)
        cout<<-1<<endl;
    else
        cout<<s<<endl;
    return 0;
}