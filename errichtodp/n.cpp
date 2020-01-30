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
const ll oo = 1e18L+5;

// dp[i][j] - minimum cost to convert all vertices in interval [i,j)
//            into one vertex

int main() {
    
    int n;
    scanf("%d",&n);
    
    vi a(n);
    for(int& x : a) {
        scanf("%d",&x);
    }
    
    vector<vector<ll>> dp(n, vector<ll>(n,oo));
    
    //O(n^3)
    for(int L = n-1; L >= 0; --L) {
        for(int R = L; R < n; ++R) {
            if(L == R) {
                dp[L][R] = 0;
            } else {
                
                ll sum = 0;
                for(int i = L; i <= R; ++i) {
                    sum += (ll)a[i];
                }
                
                for(int k = L; k < R; ++k) {
                    dp[L][R] = min(dp[L][R], dp[L][k]+dp[k+1][R]+sum);
                }
            }
        }
    }
    
    printf("%lld\n", dp[0][n-1]);
    
    return 0;
}


