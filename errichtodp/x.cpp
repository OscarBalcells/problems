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
const int nax = 1e3 + 5;

struct S {
    int w, s, v;
    void read() {
        scanf("%d%d%d", &w,&s,&v);
    }
    bool operator <(const S& b) const {
        return s - b.w > b.s - w;
    }
};

int n;
vector<S> in;
vector<ll> dp[nax];

ll knap(int ind, int left) {

    if(ind == n) return 0;
    else if(dp[ind][left] != -1) return dp[ind][left];
    
    ll ans = knap(ind+1, left);
    
    if(left - in[ind].w >= 0) {
        int next = min(left - in[ind].w, in[ind].s);
        ans = max(ans, in[ind].v + knap(ind+1, next));
    }
    
    dp[ind][left] = ans;
    return ans;
}

int main() {
    
    scanf("%d", &n);
    
    in.resize(n);
    
    for(int i = 0; i < n; ++i) {
        in[i].read();
        dp[i].assign(2e4+5, -1);
    }
    
    sort(in.begin(), in.end());
    
    ll ans = knap(0, 2e4);
    
    printf("%lld\n", ans);
    
    return 0;
}


