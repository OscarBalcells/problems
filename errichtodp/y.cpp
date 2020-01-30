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
const int oo = 1e8 + 7;
const ll mod = 1e9L + 7;
const int nax = 2e5 + 5;

ll fact[nax], rfact[nax];

ll power(ll x, ll y) {
    if(y == 0) {
        return 1;
    } else if(y % 2 == 1) {
        return power(x, y-1) * x % mod;
    } else {
        ll tmp = power(x, y / 2);
        return tmp * tmp % mod;
    }
}

ll mult(ll a, ll b) {
    return a * b % mod;
}

ll numPaths(int a, int b) {
    a += b;
    return mult(fact[a], mult(rfact[b], rfact[a-b]));
}

ll sub(ll a, ll b) {
    return (a - b + mod) % mod;
}


int main() {
    
    int h, w, n;
    scanf("%d%d%d",&h,&w,&n);
    
    vector<pair<int,pair<int,int>>> walls(n);
    
    for(int i = 0; i < n; ++i) {
        scanf("%d%d",&walls[i].second.first,&walls[i].second.second);
        walls[i].first = walls[i].second.first + walls[i].second.second;
    }
    
    // compute factorials
    fact[0] = rfact[0] = 1;
    for(int i = 1; i < nax; ++i) {
        fact[i] = fact[i-1] * i % mod;
        rfact[i] = power(fact[i], mod-2);
    }
    
    sort(walls.begin(), walls.end());
    
    walls.push_back(make_pair(-1, ii(h, w)));
    
    vector<ll> dp(n+1);
    
    for(int i = 0; i <= n; ++i) {
        int r1 = walls[i].second.first, c1 = walls[i].second.second;
        ll ans = numPaths(r1-1, c1-1);
        
        for(int j = 0; j < i; ++j) {
            int r2 = walls[j].second.first, c2 = walls[j].second.second;
            if(r2 > r1 || c2 > c1) continue;
            ans = sub(ans, mult(dp[j], numPaths(r1-r2, c1-c2)));
        }
        
        dp[i] = ans;
    }
    
    printf("%lld\n", dp[n]);
    
    return 0;
}


