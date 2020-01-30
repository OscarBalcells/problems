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
const ll mod = 1e9+7;
vector<ll> nums;

void add(ll& a, const ll b) {
    a = (a + b) % mod;
}

void sub(ll& a, const ll b) {
    a = (a - b + mod) % mod;
}

//~ int mult(int a, int b) {
    //~ return (ll) a * b % mod;
//~ }

int main() {
    
    int n, k;
    scanf("%d%d",&n,&k);
    
    nums.resize(n);
    for(ll& i : nums) {
        scanf("%lld", &i);
    }
    
    // slow version O(N * (K+K))
    
    vector<ll> dp(k+1, 0);
    dp[k] = 1;
    
    // dp[ind][k] - for child with index ind there are dp[ind][k] ways 
    // of having k candies available to take
    
    for(int ind = 0; ind < n-1; ++ind) {
        vector<ll> new_dp(k+1, 0);
        vector<ll> pre(k+1, 0);
        
        for(int avail = k; avail >= 0; --avail) {
            add(pre[avail], dp[avail]);
            if(avail-nums[ind] > 0) sub(pre[avail-nums[ind]-1], dp[avail]);
        }
        
        ll run = 0;
        for(int left = k; left >= 0; --left) {
            add(run, pre[left]);
            add(new_dp[left], run);
        }
        
        dp = new_dp;
    }
    
    ll ans = 0;
    for(int i = 0; i <= nums[n-1]; ++i) {
        add(ans, dp[i]);
    }
    
    printf("%lld\n", ans%mod);
    
    return 0;
}


