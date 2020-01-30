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

int abso(ll a) {
    if(a < 0) return -a;
    return a;
}

vector<ll> h, dp;
int n, k;

int main() {
    
    scanf("%d",&n);
    h.resize(n+1);
    
    for(int i = 1; i <= n; ++i) {
        scanf("%lld",&h[i]);
    }
    
    dp.assign(n+1, oo);
    dp[1] = 0;
    int k = 2;
    
    for(int i = 1; i <= n; ++i) {
        for(int j = i+1; j <= i+k && j <= n; ++j) {
            dp[j] = min(dp[j], dp[i]+abso(h[i]-h[j]));
        }
    }

    printf("%lld\n", dp[n]);
    
    return 0;
}


