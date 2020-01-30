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
const ll mod = 1e9+7;

void self_add(ll& x, ll y) {
    x += y;
    if(x >= mod) {
        x -= mod;
    }
}

int main() {
    
    string k;
    getline(cin, k);
    
    int n = (int)k.size();
    
    int d;
    scanf("%d",&d);
    
    vector<vector<ll>> dp(d, vector<ll>(2,0));
    dp[0][1] = 1;
    
    for(int where = 0; where < n; ++where) {
        vector<vector<ll>> new_dp(d, vector<ll>(2,0));
        
        for(int digit = 0; digit < 10; ++digit) {
            for(int sum = 0; sum < d; ++sum) {
                self_add(new_dp[(sum+digit)%d][0], dp[sum][0]);
            }
            if(digit > k[where] - '0') {
                continue;
            } else if(digit < k[where] - '0') {
                for(int sum = 0; sum < d; ++sum) {
                    self_add(new_dp[(sum+digit)%d][0], dp[sum][1]);
                }
            } else if(digit == k[where] - '0') {
                for(int sum = 0; sum < d; ++sum) {
                    self_add(new_dp[(sum+digit)%d][1], dp[sum][1]);
                }   
            }
        }
        
        dp = new_dp;
    }
    
    ll ans = dp[0][0] + dp[0][1];
    ans--;
    if(ans == -1) {
        ans += mod;
    }
    
    cout << ans << endl;
    
    return 0;
}


