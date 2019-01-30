#include <bits/stdc++.h>
using namespace std;
bool check_even(int x)
{
    return (x%2==0);
}
int main()
{
    vector<int> v={1,2,4,6,8};//v={2,4,8,10,12};all are even
    cout<<(all_of(v.begin(),v.end(),check_even)?"all are even\n":"all are not even\n");
    //another way
    cout<<(all_of(v.begin(),v.end(),[](int x){return (x%2==0);})?"all are even\n":"all are not even\n");
    return 0;
}