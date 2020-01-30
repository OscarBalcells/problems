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

void max_self(ll& a, ll b) {
    if(a < b) {
        a = b;
    }
}

int main() {
    
    int n, w;
    scanf("%d%d",&n,&w);
    
    vector<ll> dp(w+1, 0);
    
    for(int i = 0; i < n; ++i) {
        ll weight, value;
        scanf("%lld%lld", &weight, &value);
        
        for(int prevWeight = w-weight; prevWeight >= 0; --prevWeight) {
            max_self(dp[prevWeight+weight], dp[prevWeight]+value);
        }
    }
    
    debug() << imie(dp);
    
    ll ans = 0;
    for(int weight = w; weight >= 0; --weight) {
        ans = max(ans, dp[weight]);
    }
    
    printf("%lld\n", ans);
    
    return 0;
}


