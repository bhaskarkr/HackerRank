#include <bits/stdc++.h>
using namespace std;
//unordered_map
//for(int i=0;i<n;i++)
//cin>>
//cout<<
int main()
{
    
    int n;
    cin>>n;
    int i;
    for(i=9;i>=1;i--)
    {
        if(n%i==0)
        {
            cout<<n/i<<endl;
            for(int j=0;j<n/i;j++)
                cout<<i<<" ";
            cout<<endl;
            break;
        }
    }
    return 0;
}