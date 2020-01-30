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

int n;
vector<ll> groups;
vector<ll> dp; 
ll score;
vi not_taken;

void solve(int i, int mask, int group) {
    
    if(i == (int)not_taken.size()) {
        dp[mask] = max(dp[mask], score + groups[group]);
        return;
    }
    
    solve(i+1, mask, group);
    solve(i+1, mask ^ (1 << not_taken[i]), group ^ (1 << not_taken[i]));
}

int main() {
    
    scanf("%d", &n);
    
    groups.assign(1 << n, 0);
    dp.assign(1 << n, -oo);
    
    vector<vector<ll>> compa(n, vector<ll>(n, 0));
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%lld", &compa[i][j]);
        }
    }
    
    for(int mask = 0; mask < (1 << n); ++mask) {
        for(int i = 0; i < n; ++i) {
            if(!(mask & (1 << i))) continue;
            for(int j = i+1; j < n; ++j) {
                if(mask & (1 << j)) {
                    groups[mask] += compa[i][j];
                }
            }
        }
    }
    
    dp[0] = 0;
    
    for(int mask = 0; mask < (1 << n); ++mask) {
        not_taken.clear();
        for(int i = 0; i < n; ++i) {
            if(!(mask & (1 << i))) {
                not_taken.push_back(i);
            }
        }
        score = dp[mask];
        solve(0, mask, 0); //not_taken, mask, 0, dp[mask]);
    }
    
    printf("%lld\n", dp[(1 << n)-1]);
    
    return 0;
}


