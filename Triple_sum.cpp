#include<bits/stdc++.h>
using namespace std;
int main()
{
    int la,lb,lc;
    long ans=0,t;
    cin>>la>>lb>>lc;
    vector<long> va(la),vb(lb),vc(lc);
    for(int i=0;i<la;i++)
        cin>>va[i];
    for(int i=0;i<lb;i++)
        cin>>vb[i];
    for(int i=0;i<lc;i++)
        cin>>vc[i];
    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());
    sort(vc.begin(),vc.end());
    auto bega=unique(va.begin(),va.end());
    auto begb=unique(vb.begin(),vb.end());
    auto begc=unique(vc.begin(),vc.end());
    for(auto it=vb.begin();it!=begb;it++)
    {
        auto j=upper_bound(va.begin(),bega,*it)-va.begin();
        auto k=upper_bound(vc.begin(),begc,*it)-vc.begin();
        ans+=(long)j*k;
    }
    cout<<ans<<endl;
    return 0;
}