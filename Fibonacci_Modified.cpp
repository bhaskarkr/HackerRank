#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
    long double t1,t2,n,ans;
    scanf("%Lf%Lf%Lf",&t1,&t2,&n);
    while(n-- -2 >0)
    {
        ans=t1+t2*t2;
        t1=t2;
        t2=ans;
    }
    printf("%0.Lf\n",ans);
    return 0;
}