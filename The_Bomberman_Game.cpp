#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r,c,n;
    cin>>r>>c>>n;
    char s[r][c],a[r][c];
    for(int i=0;i<r;i++)
    {    
        
        for(int j=0;j<c;j++)
        {   
            cin>>s[i][j];
            a[i][j]='O';
        }
    }
    if(n%2==0)
    {
         for(int i=0;i<r;i++)
         {   
             for(int j=0;j<c;j++)
                cout<<a[i][j];
            cout<<endl;
         }   
    }   
    else if(n==1)
    {
        for(int i=0;i<r;i++)
        {    
            for(int j=0;j<c;j++)
            {   
                cout<<s[i][j];
            }
            cout<<endl;
        }
    }
    else
    {
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(s[i][j]=='O')
                {
                    a[i][j]='.';
                    if(i>0)
                        a[i-1][j]='.';
                    if(i<r-1)
                        a[i+1][j]='.';
                    if(j>0)
                        a[i][j-1]='.';
                    if(j<c-1)
                        a[i][j+1]='.';    
                }
                if(n%4==1)
                {
                    for(int i=0;i<r;i++)
                    {    
                        
                        for(int j=0;j<c;j++)
                        {   
                            s[i][j]='O';
                        }
                    }
                    for(int i=0;i<r;i++)
                        for(int j=0;j<c;j++)
                            if(a[i][j]=='O')
                            {
                                s[i][j]='.';
                                if(i>0)
                                    s[i-1][j]='.';
                                if(i<r-1)
                                    s[i+1][j]='.';
                                if(j>0)
                                    s[i][j-1]='.';
                                if(j<c-1)
                                    s[i][j+1]='.'; 
                            }
                            for(int i=0;i<r;i++)
                            {    
                                for(int j=0;j<c;j++)
                                {   
                                    cout<<s[i][j];
                                }
                                cout<<endl;
                            }
                }
                else                    
                {
                    for(int i=0;i<r;i++)
                    {    
                        for(int j=0;j<c;j++)
                        {   
                            cout<<a[i][j];
                        }
                        cout<<endl;
                    }
               }
    }
    
    return 0;
}