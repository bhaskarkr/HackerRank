#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("in.txt","r",stdin);freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define LL signed long long int
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define rep(i,from,to) for(int i=(from);i <= (to); ++i)
#define pii pair<int,int>
LL dp[300000+5][22];
LL sdp[300000+5];
int main(){
    int N = 20;
    for(int i=0;i<=9;++i)dp[i][0] = 1;
    for(int i=0;i<=N;++i){
        for(int j=1;j<=20;++j){
            for(int d=0;d<=9;++d){
                if((i-d*(1<<j)) >= 0) 
                    dp[i][j] = (dp[i][j] + dp[i-d*(1<<j)][j-1]);
                cout<<dp[i][j]<<",";              
            }
            cout<<" i "<<i<<" j "<<j<<" "<<dp[i][j]<<endl;
        }
        cout<<endl;
        sdp[i] = sdp[i-1] + dp[i][20];
    }
    int Q;
    cin>>Q;
    while(Q--){
        LL x;
        cin>>x;
        if(x==1){cout<<0<<endl;continue;}
        int L = 0;
        int R = N;
        while(L!=R){
            int m = ceil((L+R)/2.0);
            if(sdp[m] < x)L=m;
            else R = m-1;
        }
        LL val = L+1;
        x -= sdp[L];
        int pos = 0;
        for(int j=20;j>=1;--j){
            for(int d = 0;d<=9;++d){
                if(x > dp[val-d*(1<<j)][j-1]){
                    //cout<<j<<' '<<d<<endl;
                    x -= dp[val-d*(1<<j)][j-1];
                }
                else{
                    if(pos or d){
                        pos = 1;
                        cout<<d;
                        val -= d * (1<<j);
                    }
                    break;
                }
            }
        }
        cout<<val<<endl;
    }
}