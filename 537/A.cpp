#include <bits/stdc++.h>
using namespace std;
//for(int i=0;i<n;i++)

#define long ll 
int main()
{
    string a,b ;
    cin>>a>>b;
    bool ans=true;
    char v[5]={'a','e','i','o','u'};
    if(a.length()!=b.length())
        ans=false;
    else
    {
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=b[i])
            {
                bool va=false,vb=false;
                for(int j=0;j<5;j++)
                {
                    if(a[i]==v[j])
                    {
                        va=true;
                    }
                    if(b[i]==v[j])
                    {
                        vb=true;
                    }
                    
                }
                if(va&&vb)
                    continue;
                else if (va||vb)
                    ans=false;
            }
            if(!ans)
                break;
        }
    }
    cout<<(ans?"Yes":"No")<<endl;
    
    return 0;
}