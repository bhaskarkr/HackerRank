#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        char c;
        bool ans=true;
        vector<vector<char> > v(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>c;
                v[i].push_back(c);
            }
            sort(v[i].begin(),v[i].end());
            if(i>0)
            {

                for(int j=0;j<n;j++)
                {
                    if(v[i][j]<v[i-1][j])
                    {
                        ans=false;
                        break;
                    }
                }
            }
        }
        cout<<(ans?"YES\n":"NO\n");
    }
    return 0;
}