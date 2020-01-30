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
const int mod = 1e9+7;

int n;
vector<vi> AdjList;
vector<vector<ll>> dp;

int solve(int a, int prev, int col) {

    if(dp[a][col] != -1) return dp[a][col];
    ll ans = 1;
    
    for(int b : AdjList[a]) {

        if(b == prev) continue;
        
        ll nextBlack = solve(b, a, 1);
        ll nextWhite = solve(b, a, 0);
        
        if(col == 0) {
            ans *= (nextBlack + nextWhite) % mod;
        } else {
            ans *= nextWhite % mod;
        }
        
        ans %= mod;
    }
    
    dp[a][col] = ans;
    return ans;
}

int main() {
 
    scanf("%d",&n);
    
    AdjList.resize(n+1);
    dp.resize(n+1);
    
    for(int i = 1; i <= n; ++i) {
        dp[i].assign(2, -1);
    }
    
    for(int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d%d",&a,&b);
        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }
    
    ll ans = solve(1, -1, 0);
    ans += solve(1, -1, 1);
    
    cout << ans%mod << endl;
 
    return 0;   
}

