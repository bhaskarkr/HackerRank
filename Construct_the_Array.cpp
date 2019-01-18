#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main()
{
    int n,k,x;
    cin>>n>>k>>x;
    long long ap,bp,an=0,bn=0;
    ap=(x==1?1:0);
    bp=1-ap;
    for(int i=1;i<n;i++)
    {
        an=bp;
        bn=(ap*(k-1)+bp*(k-2))%MOD;
        ap=an;
        bp=bn;
    }
    cout<<an<<endl;
    return 0;
}