#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r,c;
    cin>>r>>c;
    string s[r];
    for(int i=0;i<r;i++)
        cin>>s[i];
    int a=0,b=0,t;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(s[i][j]=='G')
            {
                t=1;
                for(int x=1;x<=min(r/2,c/2);x++)
                {
                    if(i-x>=0&&i+x<r&&j-x>=0&&j+x<c&&s[i-x][j]=='G'&&s[i][j+x]=='G'&&s[i][j-x]=='G'&&s[i+x][j]=='G')
                        t+=4;
                    else
                        break;
                }
                if(t>=a)
                {
                    b=a;
                    a=t;
                    cout<<a<<" "<<b<<" "<<i<<" "<<j<<endl;
                }
                else if(t>b)
                    b=t;
            }
        }
    }
    cout<<a*b<<endl;
    return 0;
}