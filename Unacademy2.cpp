#include <bits/stdc++.h>
using namespace std;
set<string> ans;
int h,a;
void dfs(string s)
{
    if(ans.find(s)==ans.end())
    {
        ans.insert(s);
        string temp=s;
        int n=s.length();
        for(int i=0;i<n;i++)
            temp[i]=s[(i+h)%n];
        dfs(temp);
        for(int i=1;i<n;i+=2)
            s[i]=(s[i]-'0'+a)%10+'0';
        dfs(s);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        ans.clear();
        cin>>s;
        cin>>h>>a;
        dfs(s);
        cout<<"ans "<<*(ans.begin())<<endl;
    }
    return 0;
}