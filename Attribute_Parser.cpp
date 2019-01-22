#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,q,p;
    string s,t,r;
    cin>>n>>q;
    unordered_map<string,vector<pair<string,string> > > u;
    while(n--)
    {
        cin>>s;
        if(s.find(" ")!=string::npos)
        {
            p=s.find(" ");
            pair<string,string> temp;
            temp.first = s.find("=",p);
        }
    }

    return 0;
}