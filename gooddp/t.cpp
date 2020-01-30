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
const int MAXN = 3e3+5;

char s[MAXN];

int add(const int a, const int b) {
    return (a + b) % mod;
}

int main() {
    
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    
    // dp[i][j] - number of valid permutations of size i
    // such that j is the last value in the permutation
    
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    dp[1][1] = 1;
    
    for(int len = 2; len <= n; ++len) {
        
        vector<int> pref(n+1, 0);
        
        if(s[len-2] == '<') {
            int run = 0;
            for(int a = 1; a <= len-1; ++a) {
                run = add(run, dp[len-1][a]);
                pref[a] = run;
            }
        } else {
            int run = 0;
            for(int a = len-1; a >= 1; --a) {
                run = add(run, dp[len-1][a]);
                pref[a] = run;
            }
        }
        
        for(int b = 1; b <= len; ++b) {
            
            if(s[len-2] == '<') {
                dp[len][b] = add(dp[len][b], pref[b-1]);
            } else {
                dp[len][b] = add(dp[len][b], pref[b]);
            }
            
            //~ for(int a = 1; a <= len-1; ++a) {
                
                //~ int real_a = a;
                //~ if(real_a >= b) {
                    //~ real_a++;
                //~ }
                
                //~ if((real_a < b) != (s[len-2] == '<')) continue;
                
                //~ dp[len][b] = add(dp[len][b], dp[len-1][a]);
                
            //~ }
        }
    }
    
    int ans = 0; 
    
    for(int i = 1; i <= n; ++i) {
        ans = add(ans, dp[n][i]);
    }
    
    printf("%d\n", ans);
    
    return 0;
}


