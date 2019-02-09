#include <bits/stdc++.h>
using namespace std;
//for(int i=0;i<n;i++)
//for(int j=0;j<n;j++)
int main()
{
    int b,n,odd=0;
    cin>>b>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {    
        cin>>v[i];
        odd+=v[i]%2;
    }
    if(b%2)
        cout<<(odd%2?"odd":"even");
    else
        cout<<(v[n-1]%2?"odd":"even");
    cout<<endl;
    return 0;
}