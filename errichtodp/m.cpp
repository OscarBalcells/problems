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
const int oo = 1e8+7;
const int nax = 3005;

int main() {
    
    int n;
    scanf("%d",&n);
    vector<ll> nums(n);
    vector<ll> runsum(n);
    
    ll run = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%lld",&nums[i]);
        run += nums[i];
        runsum[i] = run;
    }
    
    // dp[s][e].first - maximum you can get if it's your turn and ends lie at s and e
    // dp[s][e].second - minimum you can get if it's your turn and ends lie at s and e
    vector<vector<ll>> dp(nax, vector<ll>(nax, -oo));

    for(int s = n-1; s >= 0; --s) {
        dp[s][s] = nums[s];
        
        for(int e = s+1; e < n; ++e) {
            //X - Y
            
            ll diff1 = ((runsum[e] - (s-1 >= 0 ? runsum[s-1] : 0)) - dp[s+1][e]) - dp[s+1][e];
            ll diff2 = ((runsum[e] - (s-1 >= 0 ? runsum[s-1] : 0)) - dp[s][e-1]) - dp[s][e-1];
            
            if(diff1 > diff2) {
                dp[s][e] = (runsum[e] - (s-1 >= 0 ? runsum[s-1] : 0)) - dp[s+1][e];
            } else {
                dp[s][e] = (runsum[e] - (s-1 >= 0 ? runsum[s-1] : 0)) - dp[s][e-1];
            }
            
            debug() << imie(s) imie(e) imie(dp[s+1][e]) imie(dp[s][e-1]) imie(dp[s][e]);
        }
    }
    
    dp[0][n-1] = dp[0][n-1] - (run - dp[0][n-1]);
    printf("%lld\n", dp[0][n-1]);
    
    return 0;
}


