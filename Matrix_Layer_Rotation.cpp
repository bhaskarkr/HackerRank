#include<bits/stdc++.h>
using namespace std;
int main()
{  
    int n,m,r;
    cin>>n>>m>>r;
    vector<vector<int> > v(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    }
    r %=2*(n+m-2);
    for(int k=0;k<r;k++)
    {
        for(int i=n-1;i>=n-2;i--)
        {
            for(int j=0;j<m-1;j++)
        }
    }
    return 0; 
}