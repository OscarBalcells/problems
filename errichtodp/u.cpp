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

vector<ll> groups, dp;

//global vars for rec
vector<int> not_taken;
ll score;

//2^N Subset of addings on top of base mask
void rec(int i, int mask, int group) {
    
    if(i == (int)not_taken.size()) {
        dp[mask] = max(dp[mask], score + groups[group]);
    } else {
        rec(i+1, mask, group); // we skip not_taken[i] and don't add it
        rec(i+1, mask ^ (1 << not_taken[i]), group ^ (1 << not_taken[i])); // we add not_taken[i] to the group
    }
}

int main() {
    
    int n;
    scanf("%d",&n);
    
    vector<vector<ll>> in(n, vector<ll>(n));
    
    groups.assign(1 << n, 0);
    dp.assign(1 << n, -oo);
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%lld", &in[i][j]);
        }
    }
    
    // preprocesar el score de cualquier posible grupo
    
    for(int mask = 0; mask < (1 << n); ++mask) {
        for(int i = 0; i < n; ++i) if(mask & (1 << i)) {
            for(int j = i+1; j < n; ++j) if(mask & (1 << j)) {
                groups[mask] += in[i][j];
            }
        }
    }
    
    // bottom up dp
    
    dp[0] = 0;
    
    for(int mask = 0; mask < (1 << n); ++mask) {
        not_taken.clear();
        for(int i = 0; i < n; ++i) if(!(mask & (1 << i))) {
            not_taken.push_back(i);
        }
        score = dp[mask];
        rec(0, mask, 0);
    }
    
    printf("%lld\n", dp[(1 << n)-1]);
}

