#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> A(n),B(n);
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<n;i++)
        cin>>B[i];
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int ans=0,j=0;
    bool a=false,b=false;
    for(int i=0;j<n&&i<n;)
    {
        if(A[j]==B[i])
        {
            j++;
            i++;
            ans++;
        }
        else if (A[j]<B[i])
        {
            j++;
            b=true;
        }
        else{
            i++;
            b=true;
        }
    }
    if(b)
        ans++;
    cout<<ans<<endl;
    return 0;
}