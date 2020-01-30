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
const ll oo = 1e18L+7;


int main() {
    
    int n;
    scanf("%d", &n);
    
    vi slimes(n);
    vector<vector<ll>> dp(n, vector<ll>(n, oo));
    
    for(int& i : slimes) {
        scanf("%d",&i);
    }
    
    vector<ll> pre(n, 0);
    ll run = 0;
    
    for(int i = 0; i < n; ++i) {
        run += slimes[i];
        pre[i] = run;
    }
    
    // dp[i][j] - the minimal cost of grouping all slimes in range
    // [i, j) together into one slime
    
    for(int i = n-1; i >= 0; --i) {
        dp[i][i] = 0;
        if(i+1 < n) dp[i][i+1] = slimes[i] + slimes[i+1];
        
        for(int j = i+2; j < n; ++j) {
            for(int k = i+1; k <= j; ++k) {
                ll cost = dp[i][k-1] + dp[k][j] + (pre[j] - (i > 0 ? pre[i-1] : 0));
                debug() << imie(i) imie(k) imie(j) imie(dp[i][k-1]) imie(dp[k][j]) imie((pre[j] - (i > 0 ? pre[i-1] : 0))) imie(cost);
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    
    debug() << imie(dp);
    
    printf("%lld\n", dp[0][n-1]);
    
    return 0;
}


