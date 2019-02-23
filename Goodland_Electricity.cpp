#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,prev=0;
    cin>>n>>k;
    vector <int> v(n);
    for(int i = 0;i<n;i++)
        cin>>v[i];
    int i=0,j=0,ans=0;
    while(i<n)
    {
        ans++;
        j=i+k-1;
        if(j>n)
            j=n-1;
        while(j>=prev&&v[j]==0)
            j--;
        if(j<prev)
        {
            ans=-1;
            break;
        }
        prev=j+1;
        j+=k;
        i=j;
    }
    cout<<ans<<endl;
    return 0;
}