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
const int oo = 1e8+7;

int n, m;
vector<vi> AdjList;
vi dp;

int dag(int u) {
 
    if(dp[u] != -1) {
        return dp[u];
    }
    
    debug() << imie(u);
    
    int ans = 0;
    
    for(int i = 0; i < (int)AdjList[u].size(); ++i) {
        int v = AdjList[u][i];
        debug() << imie(u) imie(v);
        ans = max(ans, 1+dag(v));
    }
    
    dp[u] = ans;
    return ans;
}


int main() {

    scanf("%d%d",&n,&m);
    
    dp.assign(n+1, -1);
    AdjList.resize(n+1);
    
    for(int i = 0; i < m; ++i) {
        int c1, c2;
        scanf("%d%d",&c1,&c2);
        AdjList[c1].push_back(c2);
    }
    
    for(int i = 1; i <= n; ++i) {
        AdjList[0].push_back(i);
    }
    
    int ans = dag(0);
    
    cout << ans-1 << endl;
    
    return 0;
}

