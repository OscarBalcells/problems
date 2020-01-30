#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vii = vector<ii>;
const int oo = 1e9+7;
const int mod = 1e9+7;

vector<vector<int>> dp;
vector<vector<int>> can;
int n;

int add(int& a, int b) {
    return (a + b) % mod;
}

int solve(int ind, int mask) {
    
    if(ind == n && mask == (1 << n)-1) {
        return 1;
    } else if(dp[ind][mask] != -1) {
        return dp[ind][mask];
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; ++i) {
        if(can[ind][i] && !(mask & (1 << i))) {
            ans = add(ans, solve(ind+1, mask | (1 << i)));
        }
    }
    
    dp[ind][mask] = ans;
    return ans;
}

int main() {
    
    scanf("%d",&n);
    
    can.resize(n);
    for(int i = 0; i < n; ++i) {
        can[i].resize(n);
        for(int j = 0; j < n; ++j) {
            scanf("%d",&can[i][j]);
        }
    }
    
    dp.assign(n, vector<int>((1<<n), -1));
    
    int ans = solve(0, 0);

    cout << ans << endl;
    
    return 0;
}


