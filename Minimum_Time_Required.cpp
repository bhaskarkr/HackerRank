#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, k, mnd = INT_MAX, mxd = INT_MIN;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) 
  {
    cin >> v[i];
    if (v[i] < mnd)
      mnd = v[i];
  }
  mxd = mnd * k;
  mnd = (mnd * n) / k;
  while (mnd < mxd) 
  {
    long mid = (mnd + mxd) >> 1, item = 0;
    for (int i = 0; i < n; i++)
      item += (mid / v[i]);
    if (item >= k)
      mxd = mid;
    else
      mnd = mid + 1;
  }
  cout << mnd << endl;
  return 0;
}