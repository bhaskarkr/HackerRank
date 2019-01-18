#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int max_so_far=INT_MIN,max_current=0,max_element=INT_MIN,pos_sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(a>max_element)
                max_element=a;
            max_current+=a;
            if(max_current<0)
                max_current=0;
            else if(max_current>max_so_far)
                max_so_far=max_current;
            if(a>0)
                pos_sum+=a;
        }
        vector<int> ans(2);
        if(max_element<=0)
            cout<<max_element<<" "<<max_element<<endl;
        else
            cout<<max_so_far<<" "<<pos_sum<<endl;
    }
    return 0;
}