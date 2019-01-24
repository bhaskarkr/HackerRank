#include <bits/stdc++.h>
using namespace std;
bool query(long x,long y)
{
    cout<<"? "<<x<<" "<<y<<endl;
    //fflush(stdout);
    char c;
    cin>>c;
    return (c=='x');
}
int main()
{
    string s;
    while(cin>>s)
    {
        if(s[0]=='e')
            break;
        long l=1,r=2;
        if(query(l,r))
        {
            if(query(2,1))
                cout<<"! 1"<<endl;
            else
                cout<<"! 2"<<endl;
            continue;
        }
        l*=2;
        r*=2;
        while(!query(l,r))
        {
            l*=2;
            r*=2;
            if(r>=1000000000)
            {    
                r=1000000000;
                break;
            } 
            
        }
        long a=l+1;
        long b=r+1;
        while(a<b)
        {
            long m=(a+b)>>1;
            if(!query(l,m))
                a=m+1;
            else
                b=m;
        }
        cout<<"! "<<b<<endl;
    }
    return 0;
}