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
const int mod = 1e9+7;

int main() {
    
    int n, k;
    scanf("%d%d",&n,&k);
    
    vector<int> a(n);
    
    for(int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    
    vector<ll> dp(k+1, 0);
    
    for(int i = 0; i <= a[n-1]; ++i) {
        dp[i] = 1;
    }
    
    for(int child = n-2; child >= 0; --child) {
        ll run = 0;
        vector<ll> new_dp(k+1, 0);
        
        debug() << imie(dp);
        
        for(int used = k; used >= k-a[child]; --used) {
            run += dp[used];
            if(run >= mod) run -= mod;
        }
        
        for(int used = k; used >= 0; --used) {
            new_dp[used] = run;
            run -= dp[used];
            if(run <= 0) run += mod;
            if(used-a[child]-1 >= 0) run += dp[used-a[child]-1];
            if(run >= mod) run -= mod;
        }
        
        dp = new_dp;
    }
    
    cout << dp[k] << endl;
    
    return 0;
}


