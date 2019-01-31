#include <bits/stdc++.h>
using namespace std;
//for(int i=0;i<n;i++)

#define long ll 
int main()
{
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    int ans=0;
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<n-1;j++)
        {
            if(s[i][j]=='X')
            {
                if(i-1>-1&&j-1>-1&&i+1<n&&j+1<n)
                {
                    if(s[i+1][j+1]=='X'&&s[i-1][j+1]=='X'&&s[i+1][j-1]=='X'&&s[i-1][j-1]=='X')
                        ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}