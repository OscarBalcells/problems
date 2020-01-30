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

int dist[120][15][15];
int dp[120][15];
int n, m;

int dag(int k, int j) {
    
    if(k == n-1) return 0;
    if(dp[k][j] != -1) return dp[k][j];
    
    int ans = oo;
    
    for(int i = 0; i < m; ++i) {
        ans = min(ans, dist[k][j][i] + 2 + dag(k+1, i));
    }
    
    dp[k][j] = ans;
    return ans;
}

int main() {
    
    string name;
    
    while(getline(cin, name)) {
        
        if(name.size() == 0 || name[0] < 48 || name[0] > 122) {
            break;
        }
        
        for(int i = 0; i < 120; ++i) {
            for(int j = 0; j < 15; ++j) {
                dp[i][j] = -1;
            }
        }
        
        cin >> n >> m;
        
        for(int j = 0, hole = 0, k = -1; j < (n-1)*m; ++j) {
            
            hole = j % m;
            if(hole == 0) k++;
            
            for(int i = 0; i < m; ++i) {
                int d; cin >> d;
                dist[k][hole][i] = d;
            }
        }
        
        int ans = oo;
        
        for(int i = 0; i < m; ++i) {
            ans = min(ans, dag(0, i));
        }
        
        cout << name << endl << ans << endl;
        
        getline(cin, name);
        
        
    }
    
    
    return 0;
}
