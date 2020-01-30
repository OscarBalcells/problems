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

int n;
vector<vi> dp;
vector<vi> AdjList;

int solve(int ind, int mask) {
    
    if(dp[ind][mask] != -1) return dp[ind][mask];
    int ans = 0;
     
    for(int i = 0; i < (int)AdjList[ind].size(); ++i) {
        if((mask & (1 << AdjList[ind][i]))) continue;
        ans += (ind < n-1 ? solve(ind+1, mask | (1 << AdjList[ind][i])) : 1);
        if(ans >= mod) ans -= mod;
    }
    return dp[ind][mask] = ans;
}

int main() {
    
    scanf("%d",&n);
    
    dp.resize(n);
    AdjList.resize(n);
    
    for(int i = 0; i < n; ++i) {
        dp[i].assign((1 << n), -1);
        for(int j = 0; j < n; ++j) {
            int x; scanf("%d",&x);
            if(x & 1) AdjList[i].push_back(j);
        }
    }
     
    int ans = solve(0, 0);
    printf("%d\n", ans);
    
    return 0;
}


