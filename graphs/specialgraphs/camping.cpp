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

const int mod = 1e9+7;
const int oo = 1e9+7;

int n, k;
vi dist;
vector<vi> dp;

int dag(int s, int left) {
    
    if(s == n+1) return 0;
    if(dp[s][left] != -1) return dp[s][left];
    
    int way = 0;
    
    if(left == 0) {
        for(int ind = s; ind <= n; ++ind) {
            way += dist[ind];
        }
        dp[s][left] = way;
        return way;
    }
    
    int ans = oo;
    
    for(int ind = s; ind <= n; ++ind) {
        way += dist[ind];
        ans = min(ans, max(way, dag(ind+1, left-1)));
    }
    
    dp[s][left] = ans;
    return ans;
}

int main() {
    
    while(scanf("%d%d",&n,&k) == 2) {
    
        dist.clear(); dp.clear();
        dist.resize(n+1);
        dp.resize(n+1);
        
        
        for(int i = 0; i <= n; ++i) {
            scanf("%d", &dist[i]);
            dp[i].assign(k+1, -1);
        }
        
        int ans = dag(0, k);
        
        cout << ans << endl;
    
    }
    
    return 0;
}


