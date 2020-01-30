#include <bits/stdc++.h>
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

typedef long long int ll;
const ll oo = 1e18L;

int main() {    

    int n;
    scanf("%d", &n);
    
    vector<int> a(n);
    
    for(int& x : a) {
        scanf("%d", &x);
    }
    
    vector<vector<ll>> dp(n, vector<ll>(n, -oo));
    vector<vector<ll>> mid(n, vector<ll>(n, -1));
    vector<ll> pref(n, 0);
    
    pref[0] = a[0];
    for(int i = 1; i < n; ++i) {
        pref[i] = pref[i-1] + a[i];
    }
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j+i < n; ++j) {
            
            if(i == 0) {
                dp[j][j] = 0;
                mid[j][j] = 0;
                continue;
            } else if(i == 1) {
                dp[j][j+1] = pref[j+1]-(j-1 >= 0 ? pref[j-1]:0);
                mid[j][j+1] = j;
                continue;
            }
            
            dp[j][j+i] = oo;
            
            for(int k = mid[j][j+i-1]; k <= mid[j+1][j+i]; ++k) {
                ll val = dp[j][k] + dp[k+1][j+i] + (pref[j+i]-(j-1 >= 0 ? pref[j-1] : 0));
                if(val < dp[j][j+i]) {
                    mid[j][j+i] = k;
                    dp[j][j+i] = val;
                }
            }
        }
    }
    
    debug() << imie(dp);

    printf("%lld\n", dp[0][n-1]);

    return 0;
}
