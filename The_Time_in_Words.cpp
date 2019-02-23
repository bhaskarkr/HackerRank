#include <bits/stdc++.h>
using namespace std;
int main()
{
    string day[]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","quarter","sixteen","seventeen","eighteen","nineteen","twenty","twenty one","twenty two","twenty three","twenty four","twenty five","twenty six","twenty seven","twenty eight","twenty nine","half","past "};
    int h,m;
    cin>>h>>m;
    if(m==0)
    {    
        cout<<day[h-1]<<" o' clock\n";
        return 0;
    }
    if(m>30)
    {    
        day[30]="to ";
        h++;
        m=60-m;
    }
    cout<<(day[m-1]+(m%15==0?"":" minute")+(m==1?" ":(m%15!=0?"s ":" "))+day[30]+day[(h-1)%12])<<endl;
    return 0;
}