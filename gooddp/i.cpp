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


int main() {

    int n;
    scanf("%d", &n);
    
    vector<double> p(n+1);
    vector<double> dp(n+1, 0);
    
    // dp[i] - p-bility of having i heads after a specific amount
    // of tosses defined by iteration
    
    for(int i = 1; i <= n; ++i) {
        scanf("%lf", &p[i]);
    }
    
    dp[0] = 1;
    for(int ntosses = 1; ntosses <= n; ++ntosses) {
        vector<double> new_dp(n+1, 0);
        
        for(int heads = 0; heads <= ntosses; ++heads) {
            new_dp[heads] = (heads-1 >= 0 ? dp[heads-1] : 0) * p[ntosses] + dp[heads] * (1 - p[ntosses]);
        }
        
        dp = new_dp;
    }
    
    double ans = 0;
    
    for(int heads = 0; heads <= n; ++heads) {
        int tails = n - heads;
        if(heads > tails) {
            ans += dp[heads];
        }
    }
    
    printf("%.10lf\n", ans);
    
    return 0;
}


