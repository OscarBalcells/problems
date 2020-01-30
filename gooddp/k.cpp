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
    
    int n, k;
    scanf("%d%d",&n,&k);
    
    vector<int> stones(n);
    vector<bool> dp(k+1, false);
    
    // dp[i] - win = ( false ? true) if in your turn there are i stones
    
    int small = 0;
    
    for(int& i : stones) {
        scanf("%d", &i);
        small = min(small, i);
    }
    
    for(int i = 0; i < small; ++i) {
        dp[i] = false;
    }
    
    for(int left = small; left <= k; ++left) {
        for(int x : stones) {
            if(left-x >= 0) {
                if(dp[left-x] == false) {
                    dp[left] = true;
                    break;
                }
            }
        }
    }
    
    (dp[k] == true ? printf("First\n") : printf("Second\n"));
    
    return 0;
}


