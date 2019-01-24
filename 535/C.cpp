#include <bits/stdc++.h>
using namespace std;
int main()
{
    char arr[6][3]={
        {'B','R','G'},{'B','G','R'},{'R','B','G'},{'R','G','B'},{'G','R','B'},{'G','B','R'}};
    int n;
    cin>>n;
    string s;
    cin>>s;
    int minindex=0,c=INT_MAX;
    for(int j=0;j<6;j++)
    {
        int C=0;
        for(int i=0;i<n;i++)
        {
            if(arr[j][i%3]!=s[i])
                C++;
        }
        if(C<c)
        {
            c=C;
            minindex=j;
        }
    }
    cout<<c<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[minindex][i%3];
    }
    cout<<endl;
    return 0;
}