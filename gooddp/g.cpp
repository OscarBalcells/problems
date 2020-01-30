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

vector<vi> edges;
vector<int> dp;

int dfs(int a) {
    
    if(dp[a] != -1) return dp[a];
    
    int ans = 0;
    
    for(int b : edges[a]) {
        ans = max(ans, 1 + dfs(b));
    }
    
    dp[a] = ans;
    return ans;
}

int main() {
    
    int n, m;
    scanf("%d%d",&n,&m);
    
    dp.assign(n+1, -1);
    edges.resize(n+1);
    
    for(int i = 1; i <= m; ++i) {
        int a, b;
        scanf("%d%d",&a,&b);
        edges[a].push_back(b);
    }
    

    for(int i = 1; i <= n; ++i) {
        edges[0].push_back(i);
    }
    
    int ans = dfs(0);
    
    cout << ans-1 << endl;
    
    return 0;
}


