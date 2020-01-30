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
const int nax = 1005;
const ll oo = 1e12L+7;

int pos[nax];
ll dp[nax][nax];
int mid[nax][nax];

int main() {

    int n, m;
    
    while(scanf("%d%d", &n, &m) != EOF) {
        
        for(int i = 1; i <= m; ++i) {
            scanf("%d", &pos[i]);
        }
        
        pos[0] = 0;
        pos[m+1] = n;
        
        memset(dp, 0, sizeof dp);
        
        for(int j = 0; j <= m+1; ++j) {
            dp[j][j] = 0ll;
            mid[j][j] = j;
            dp[j][j+1] = 0ll; //no cuts in the middle
            mid[j][j+1] = j;
        }
        
        for(int i = 2; i <= m+1; ++i) {
            for(int j = 0; j+i <= m+1; ++j) {
                dp[j][j+i] = oo;

                //~ debug() << imie("MID") imie(j) imie(i) imie(mid[j][j+i-1]) imie(mid[j+1][j+i]);
                
                for(int k = mid[j][j+i-1]; k <= mid[j+1][j+i]; ++k) {
                    ll val = dp[j][k] + dp[k][j+i] + ll(pos[j+i]-pos[j]);
                    //~ debug() << imie("VAL") imie(val) imie(j) imie(i) imie(k) imie(dp[j][k]) imie(dp[k][j+i]) imie(pos[j+i]) imie(pos[j]);
                    //~ cout << "VAL " << val << " "<<  pos[j+1] << " " << pos[j]<< " " << i << " " << j <<  endl;
                    if(dp[j][j+i] > val) {
                        dp[j][j+i] = val;
                        mid[j][j+i] = k;
                    }
                }
            }
        }
        
        printf("%lld\n", dp[0][m+1]);
        
    }


    
    return 0;
}
