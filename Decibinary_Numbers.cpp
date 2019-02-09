#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void generate(int d,int r,int cur)
{
     //cout<<d<<" "<<r<<" "<<cur<<endl;
    if(r<0||r>9*(1<<(d+1)))
        return;
    else if(r==0&&d==-1)
        v.push_back(cur);
    else
    {
        for(int i=0;i<10;i++)
            if((r-i*(1<<d))>=0&&d>=0)
                generate(d-1,r-i*(1<<d),cur*10+i);
    }
    
}
int main()
{
    int val=0,m,n;
    cin>>m;
    for(int i=0;i<600;i++)
        generate(20,i,val);
    while(m--)
    {
        cin>>n;
        cout<<v[n-1]<<endl;
    }
    return 0;
}