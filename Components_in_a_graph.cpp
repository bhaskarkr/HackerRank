#include <bits/stdc++.h>
using namespace std;
int main()
{
    int fpar,tpar,edge,a,b,ansa=INT_MAX,ansb=INT_MIN;
    cin>>edge;
    vector<int> par(2*edge+2),count(2*edge+2,1);
    for(int i=0;i<2*edge;i++)
        par[i+1]=i+1;
    for(int i=0;i<edge;i++)
    {
        scanf("%d%d",&a,&b);
        fpar=par[a];
        while(par[fpar]!=fpar)
            fpar=par[fpar];
        tpar=par[b];
        while(par[tpar]!=tpar)
            tpar=par[tpar];
        if(fpar==tpar)
            continue;
        par[tpar]=fpar;
        count[fpar]+=count[tpar];
        count[tpar]=0;
    }
    for(int i=1;i<=edge;i++)
    {
        int l = count[i];
        if(l<2)
            continue;
        if(l>1&&l<ansa)
            ansa=l;
        if(l>1&&l>ansb)
            ansb=l;
    }
    cout<<ansa<<" "<<ansb<<endl;
    return 0;
}