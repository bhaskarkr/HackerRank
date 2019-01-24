#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int DP[3][n+1];
    DP[0][0]=0;
    DP[1][0]=0;
    DP[2][0]=0;
    string s1="",s2="",s3="",a="R",b="G",c="B";
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R')
        {
            DP[0][i+1]=min(DP[1][i],DP[2][i]);
            DP[1][i+1]=min(DP[0][i]+1,DP[2][i]+1);
            DP[2][i+1]=min(DP[0][i]+1,DP[1][i]+1);
            s1=(DP[1][i]<=DP[2][i]?b+'R':c+'R');
            s2=(DP[0][i]<=DP[2][i]?a+'G':c+'G');
            s3=(DP[0][i]<=DP[1][i]?a+'B':b+'B');
        }
        else if(s[i]=='G')
        {
            DP[0][i+1]=min(DP[1][i]+1,DP[2][i]+1);
            DP[1][i+1]=min(DP[0][i],DP[2][i]);
            DP[2][i+1]=min(DP[0][i]+1,DP[1][i]+1);
            s1=(DP[1][i]<=DP[2][i]?b+'R':c+'R');
            s2=(DP[0][i]<=DP[2][i]?a+'G':c+'G');
            s3=(DP[0][i]<=DP[1][i]?a+'B':b+'B');
        }
        else
        {
            DP[0][i+1]=min(DP[1][i]+1,DP[2][i]+1);
            DP[1][i+1]=min(DP[0][i]+1,DP[2][i]+1);
            DP[2][i+1]=min(DP[0][i],DP[1][i]);
            s1=(DP[1][i]<=DP[2][i]?b+'R':c+'R');
            s2=(DP[0][i]<=DP[2][i]?a+'G':c+'G');
            s3=(DP[0][i]<=DP[1][i]?a+'B':b+'B');
        }
        //cout<<DP[0][i+1]<<" "<<DP[1][i+1]<<" "<<DP[2][i+1]<<endl;
        a=s1;
        b=s2;
        c=s3;
        //cout<<s1<<"\n"<<s2<<"\n"<<s3<<endl;
    }
    
    
    cout<<min(DP[0][n],min(DP[1][n],DP[2][n]))<<endl;
    if(DP[0][n]<DP[1][n]&&DP[0][n]<DP[2][n])
        cout<<s1.substr(1)<<endl;
    else if(DP[1][n]<DP[0][n]&&DP[1][n]<DP[2][n])
        cout<<s2.substr(1)<<endl;
    else   
        cout<<s3.substr(1)<<endl;
    return 0;
}