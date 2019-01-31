#include <bits/stdc++.h>
using namespace std;
//for(int i=0;i<n;i++)
int main()
{
   long n,m,a,b;
    cin>>n>>m;
    vector<long> type(n),cost(n);
    set<pair<long,long> > remain;
    for(int i=0;i<n;i++)
    {
        cin>>type[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>cost[i];
        remain.insert(make_pair(cost[i],i));
    }
    for(int i=0;i<m;i++)
    {
        unsigned long long int ans=0;
        cin>>a>>b;
        if(type[a-1]>=b)
        {
            cout<<1LL*b*cost[a-1]<<endl;
            type[a-1]-=b;
        }
        else
        {
            ans+=1LL*type[a-1]*cost[a-1];
            b-=type[a-1];
            type[a-1]=0;
            //cout<<"b "<<b<<endl;
            while(b>0&&!remain.empty())
            {
                //cout<<"b "<<b<<" "<<ans<<endl;
                //cout<<"popppp "<<(*remain.begin()).second<<endl;
                while(!remain.empty()&&type[(*remain.begin()).second]==0)
                    {

                       // cout<<"pop "<<(*remain.begin()).second<<endl;
                    remain.erase(remain.begin());
                    }
                if(!remain.empty())
                {
                    auto it=remain.begin();
                    long ind = (*it).second;
                    //cout<<"index "<<ind<<" "<<type[ind]<<" "<<cost[ind]<<endl;
                    if(type[ind]>=b)
                    {
                        type[ind]-=b;
                        ans+=1LL*b*cost[ind];
                        b=0;
                    }
                    else
                    {
                        b-=type[ind];
                        ans+=1LL*type[ind]*cost[ind];
                        type[ind]=0;
                        remain.erase(remain.begin());
                    }
                }
            }
            if(b>0)
                ans=0;
            cout<<ans<<endl;
            /*for(int j=0;j<n;j++)
                cout<<type[j]<<" ";
            cout<<endl;*/
        }
        
    }
    return 0;
}