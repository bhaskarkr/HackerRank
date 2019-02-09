#include <bits/stdc++.h>
using namespace std;
//for(int i=0;i<n;i++)
//for(int j=0;j<n;j++)
long gcd(long a , long b)
{
    if(a==0)
        return b;
    else if(b==0)
        return a;
    else
    {
        if(a<b)
            swap(a,b);
        long c=a%b;
        while(c>0)
        {
            a=b;
            b=c;
            c=a%b;
        }
        return b;
    }
    
}
int main()
{
    int n;
    long k,t;
    cin>>n;
    while(n--)
    {
        cin>>k;
        t=k;
        int rb=0;
        while(t>0)
        {
            rb++;
            t/=2;
        }
        //cout<<(1<<rb)<<endl;
        long next = (1<<rb)-1;
        next = next-k;
        if(next==0)
        {
            next=1;
            for(int i=2;i*i<=k;i++)
				if(k%i==0)
				{
					next = k/i;
					break;
				}
        }
        //cout<<"next "<<next<<endl;
        long ex = k^(next),an=k&(next);
        cout<<gcd(ex,an)<<endl;
    }
    return 0;
}
