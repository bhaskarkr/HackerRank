#include <bits/stdc++.h>
using namespace std;
int main()
{
    int mne=INT_MAX,mxe=INT_MIN,n,m;
    cin>>n>>m;
    vector<int> A(n),B(n);
    vector<pair<int,int> > seg(m);
    for(int i=0;i<n;i++)
    {    
        cin>>A[i];
        mne=min(A[i],mne);
        mxe=max(A[i],mxe);
    }
    int ans=mxe-mne,ival=-1,c=0; 
    for(int i=0;i<m;i++)
        cin>>seg[i].first>>seg[i].second;
    for(int i=0,C;i<n&&m>0;i++)
    {
        C=0;
        for(int j=0;j<n;j++)
            B[j]=A[j];
        for(int j=0;j<m;j++)
        {
            if(seg[j].first-1<=i && seg[j].second-1>=i)
            {
                for(int k=seg[j].first-1;k<=seg[j].second-1;k++)
                    B[k]--;
                C++;
            }
        }
        mne = INT_MAX;
        mxe = INT_MIN;
        for(int k=0;k<n;k++)
        {
            mne=min(B[k],mne);
            mxe=max(B[k],mxe);
        }
        if(mxe-mne>ans)
        {
            ans=mxe-mne;
            ival = i;
            c=C;
        }
    }
    cout<<ans<<endl;
    cout<<c<<endl;
    for(int j=0;j<m;j++)
    {
        if(seg[j].first-1<=ival && seg[j].second-1>=ival)
        {
            cout<<j+1<<" ";
        }
    }
    cout<<endl;
    return 0;
}