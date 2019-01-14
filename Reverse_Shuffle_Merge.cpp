#include <bits/stdc++.h>
using namespace std;
int freq[150],need[150];
int main()
{
    string s,ans="";
    cin>>s;
    int l=0,L=s.length();
    memset(freq,0,sizeof(freq));
    for(int i=0;i<s.length();i++)
        freq[s[i]]++;
    for(int i='a';i<='z';i++)
        need[i]=freq[i]/2;  
    int i=L-1;
    while(l<L/2)
    {
        int last=-1;
        while(1)
        {
            if(need[s[i]]>0&&(last==-1||s[i]<s[last]))
                last=i;
            freq[s[i]]--;
            if(freq[s[i]]<need[s[i]])
                break;
            i--;
        }
        for(int j=i;j<last;j++)
            freq[s[j]]++;
        need[s[last]]--;
        ans.push_back(s[last]);
        i=last-1;
        l++;
    }
    cout<<ans<<endl;
    return 0;
}