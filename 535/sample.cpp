#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5;

struct ele {
	int l, r, id;
	ele (int a = 0, int b = 0, int c = 0) : l(a), r(b), id(c) {}
	bool operator < (const ele A) const { return r < A.r; }
};

struct qwq {
	int first, second, id;
	bool operator < (const qwq A) const { return first < A.first; }
} t[N];

multiset <ele> wxw, Ans;
multiset <ele> :: iterator it;
set <int> sol;
set <int> :: iterator itt;
int a[N];
int n, m, ans, maxn = -729478395;

void solve() {
	int Max = -93249837, Min = -Max;
	for(register int i = 1; i <= n; i++) Max = max(Max, a[i]), Min = min(Min, a[i]);
	ans = Max - Min;
}

int main() {
	read(n); read(m);
	for(register int i = 1; i <= n; i++) read(a[i]);
	solve();
	for(register int i = 1; i <= m; i++) read(t[i].first), read(t[i].second), t[i].id = i;
	sort(t + 1, t + m + 1);
    for(register int i = 1; i <= m; i++)
        cout<<t[i].first<<" "<<t[i].second<<" "<<t[i].id<<endl;
	int now = 1;
	for(register int i = 1; i <= n; i++) {
		while(now <= m && t[now].first == i) {
			for(register int j = t[now].first; j <= t[now].second; j++) --a[j];
			solve(); wxw.insert(ele(t[now].first, t[now].second, t[now].id)); ++now;
		}
		while(wxw.size() && wxw.begin() -> r == i - 1) {
			int l = wxw.begin() -> l, r = wxw.begin() -> r;
			for(register int j = l; j <= r; j++) ++a[j];
			solve(); wxw.erase(wxw.begin());
		}
		if(maxn < ans) {
			maxn = ans;
			Ans = wxw;
		}
	}
	cout << maxn << endl;
	for(it = Ans.begin(); it != Ans.end(); ++it) sol.insert(it -> id);
	cout << sol.size() << endl;
	for(itt = sol.begin(); itt != sol.end(); ++itt) print(*itt, ' ');
	return 0;
}