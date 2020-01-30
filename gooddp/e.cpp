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
    
    int n, w;
    scanf("%d%d",&n,&w);
    
    int maxValue = 1e3 * n;
    
    vector<ll> dp(maxValue+7, oo);
    dp[0] = 0;
    
    for(int i = 1; i <= n; ++i) {
        
        int weight, value;
        scanf("%d%d", &weight, &value);
        
        for(int prevValue = maxValue-value; prevValue >= 0; --prevValue) {
            dp[prevValue+value] = min(dp[prevValue+value], dp[prevValue]+(ll)weight);
        }
        
    }
    
    for(int value = maxValue; value >= 0; --value) {
        if(dp[value] <= w) {
            printf("%d\n", value);
            break;
        }
    }
    
    return 0;
}


