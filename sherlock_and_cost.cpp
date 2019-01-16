#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n],L=0,H=0,l,h,ans;
        cin>>arr[0];
        for(int i=1;i<n;i++)
        {
            cin>>arr[i];
            l=max(L,H+abs(1-arr[i-1]));
            H=max(L+abs(arr[i]-1),H+abs(arr[i]-arr[i-1]));
            L=l;
        }
        ans = max(L,H);
        cout<<ans<<endl;
    }
    return 0;
}