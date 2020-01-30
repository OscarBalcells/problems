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
const int mod = 1e9+7;

vector<vi> edges;
vector<vi> dp;

int add(const int a, const int b) {
    return (a + b) % mod;
}

int mult(const int a, const int b) {
    return (ll) a * b % mod;
}

// number of ways subtree with a as root and p as parent
// can be painted with vertex a being of color c
int dfs(int a, int p, int c) {
    
    if(dp[a][c] != -1) return dp[a][c];
    
    int ans = 1;
    
    for(int b : edges[a]) if(b != p) {
         
         if(c == 0) { //white
            ans = mult(ans, add(dfs(b, a, 0), dfs(b, a, 1)));
         } else if(c == 1) {
            ans = mult(ans, dfs(b, a, 0)); // no black vertices can touch each other
         }
    }
    
    return dp[a][c] = ans;
}

int main() {
    
    int n;
    scanf("%d",&n);
    
    edges.resize(n+1);
    dp.assign(n+1, vector<int>(2, -1));
    
    for(int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d%d",&a,&b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    int ans = dfs(1, -1, 0);
    ans = add(ans, dfs(1, -1, 1));
    
    printf("%d\n", ans);
    
    return 0;
}


