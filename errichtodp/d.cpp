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
using vii = vector<ii>;

const int mod = 1e9+7;
const int oo = 1e9+7;


int main() {
    
    int n, w;
    scanf("%d%d",&n,&w);
    
    vector<ll> dp(1e5+5, oo);
    dp[0] = 0;
    
    for(int i = 0; i < n; ++i) {
        ll wi, vi;
        scanf("%lld%lld",&wi,&vi);
        
        for(int v = 1e5+4; v >= 0; --v) {
            if(v + vi < 1e5+5) {
                dp[v+vi] = min(dp[v+vi], dp[v]+wi);
            }
        }
    }
    
    for(int i = 1e5+4; i >= 0; --i) {
        if(dp[i] <= w) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}


