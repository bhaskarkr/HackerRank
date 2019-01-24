#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    bool h=false,v=false;
    for(char c:s)
    {
        if(c=='0')
        {
            if(v)
            {
                cout<<"1 1"<<endl;
                v=false;
            }
            else
            {
                cout<<"3 1"<<endl;
                v=true;
            }
        }
        else
        {
            if(h)
            {
                cout<<"1 1"<<endl;
                h=false;
            }
            else
            {
                cout<<"1 3"<<endl;
                h=true;
            }
        }
    }
    return 0;
}