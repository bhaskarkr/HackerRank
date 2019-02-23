#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pii;
int main()
{
    ll a,n;
    cin>>n;
    int v[n][n];
    unordered_map<ll,ll> um;
    for(int i=0;i<n*n;i++)
    {
        cin>>a;
        um[a]++;
    }
    ll c=0,o=0,r=0;
    for(auto p:um)
    {
        //cout<<p.fi<<" "<<p.se<<endl;
        if((p.second%2)==1)
        {
            r=p.fi;  
            c++;
        }
        if(p.second%4>0)
            o++;
        //cout<<p.fi<<" "<<p.se<<endl;  
        //if(c>1)
          //  break;
    }
    //cout<<o<<endl;
    if((n>1&&o>n)||((c>0||o>0)&&n%2==0))
        cout<<"NO"<<endl;
    else
    {
        auto it=um.begin();
        int k = it->se,l=0;
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                //cout<<i<<" "<<j<<endl;
                if(it!=um.end()&&it->se<4&&l<=n*n-1)
                    it++;
                v[i][j]=it->fi;
                v[i][n-1-j]=it->fi;
                v[n-1-i][j]=it->fi;
                v[n-1-i][n-1-j]=it->fi;
                it->se-=4;
                l+=4;
                if(it!=um.end()&&it->se<2&&l<=n*n-1)  
                    it++;
            }
        }
        //cout<<"afsdfas";
        if(n%2)
        {
            v[n/2][n/2]=r;
            auto it=um.begin();
            while(it!=um.end()&&(*it).second<2)
            {  
                it++;
            }
            for(int i=0;i<n/2;i++)
            {
                v[i][n/2]=it->fi;
                v[n-1-i][n/2]=it->fi;
                it->se-=2;
                l+=2;
                if(it->se<2)
                {
                    it++;
                    while(it!=um.end()&&(*it).se<2)
                        it++;
                }
                v[n/2][i]=(*it).fi;
                v[n/2][n-1-i]=(*it).fi;
                it->se-=2;
                l+=2;
                if(it->se<2&&l<n*n-1)
                {
                    it++;
                    while(it!=um.end()&&(*it).se<2)
                        it++;
                }
            }
        }
        cout<<"YES\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<v[i][j]<<" ";
            cout<<endl;
        }
    }

    
    return 0;
}