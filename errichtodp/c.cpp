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

int main() {
    
    int n;
    scanf("%d",&n);
    
    ll dp1 = 0, dp2 = 0, dp3 = 0;
    
    for(int i = 0; i < n; ++i) {
        ll a, b, c;
        scanf("%lld%lld%lld",&a,&b,&c);
        
        ll one = dp1, two = dp2, three = dp3;
        
        dp1 = max(dp1, two+a);
        dp1 = max(dp1, three+a);
        
        dp2 = max(dp2, one+b);
        dp2 = max(dp2, three+b);
        
        dp3 = max(dp3, one+c);
        dp3 = max(dp3, two+c);
    }
    
    cout << max(dp1, max(dp2,dp3)) << endl;
    
    return 0;
}


