#include <bits/stdc++.h>
using namespace std;
//unordered_map
//for(int i=0;i<n;i++)
//cin>>
//cout<<
int main()
{
    string s;
    cin>>s;
    bool a[4][4];
    memset(a,false,sizeof(a));
    for(char c:s)
    {
        if(c=='0')
        {
            for(int j=0;j<4;j++)
            {
                bool k=false;
                for(int i=0;i<3;i++)
                {
                    if(!a[i][j]&&!a[i+1][j])
                    {
                        cout<<i+1<<" "<<j+1<<endl;
                        a[i][j]=true;
                        a[i+1][j]=true;
                        k=true;
                        break;
                    }
                }
                if(k)
                    break;
            }
        }
        else
        {
            for(int i=0;i<4;i++)
            {
                bool k=false;
                for(int j=0;j<3;j++)
                {
                    if(!a[i][j]&&!a[i][j+1])
                    {
                        cout<<i+1<<" "<<j+1<<endl;;
                        a[i][j]=true;
                        a[i][j+1]=true;
                        k=true;
                        break;
                    }
                }
                if(k)
                    break;
            }
        }
        for(int j=0;j<4;j++)
        {
            int b=0;
            for(int i=0;i<4;i++)
            {
                    if(a[i][j])
                        b++;
            }
            if(b==4)
            {
                for(int i=0;i<4;i++)
                    a[i][j]=false;
            } 
        }
        for(int j=0;j<4;j++)
        {
            int b =0;
            for(int i=0;i<4;i++)
            {
                    if(a[j][i])
                        b++;
            }
            if(b==4)
            {
                for(int i=0;i<4;i++)
                    a[j][i]=false;
            } 
        }
    }
    return 0;
}