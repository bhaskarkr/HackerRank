#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a,b,c,d;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a=n%3;
        b=0;
        c=0;
        if(n>2)
        {
            if(a==0)
            {
                while(n--)
                    cout<<5;
            }
            else if(a==2 && n-5>=0)
            {    
                while((n-- - 5))
                    cout<<5;
                cout<<33333;
            }
            else if(a==1&&n-10>=0)
            {    
                while((n-- - 10))
                    cout<<5;
                cout<<"3333333333";
            }
            else
                cout<<-1;
        }
        else
        {
            cout<<-1;
        }
        cout<<endl;
    }
    return 0;
}