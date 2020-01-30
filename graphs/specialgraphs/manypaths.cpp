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

vector<vi> AdjList;
vi dp;

int dfs(int u) {

    if(dp[u] != -1) return dp[u];
    
    int ans = 0;
    
    for(int i = 0; i < (int)AdjList[u].size(); ++i) {
        ans += dfs(AdjList[u][i]);
    }
    
    if(ans == 0) ans = 1;
    
    dp[u] = ans;
    return ans;

}


int main() {
    
    int e;
    bool first = true;
    
    while(scanf("%d",&e) != EOF) {
        
        if(!first) cout << endl;
        first = false;
        
        AdjList.clear();
        AdjList.resize(e);
        dp.clear();
        dp.assign(e, -1);
        
        for(int i = 0; i < e; ++i) {
            
            int n;
            scanf("%d", &n);
            
            for(int j = 0; j < n; ++j) {
                int x; scanf("%d",&x);
                AdjList[i].push_back(x);
            }
            
        }
        
        int ans = dfs(0);
        cout << ans << endl;
    }
    
    return 0;
}

