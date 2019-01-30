#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double a,b,c;
        cin>>a>>b>>c;
        cout<<hex<<showbase<<(long long)a<<endl;
        long long d=b,C=0,e=c;
        while(d)
        {
            C++;
            d/=10;
        }

        cout<<dec;
        int k=15-4-C;
        while(k--)
            cout<<"_";
        cout<<(b>0?"+":"-");
        printf("%.2lf\n",b);
        cout<<scientific<<uppercase<<setprecision(9)<<c<<endl;
    }
    return 0;
}