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
    
    int r, c;
    scanf("%d%d",&r,&c);
    string line;
    getline(cin, line);
    
    vector<vector<char>> grid(r);
    vector<vector<int>> dp(r);
    
    for(int i = 0; i < r; ++i) {
        grid[i].resize(c);
        dp[i].assign(c, 0);
        
        getline(cin, line);
        
        for(int j = 0; j < c; ++j) {
            grid[i][j] = line[j];
        }
    }
    
    dp[0][0] = 1;
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(grid[i][j] == '#') continue;
            
            if(i+1 < r) {
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= mod;
            } 
            
            if(j+1 < c) {
                dp[i][j+1] += dp[i][j];
                dp[i][j+1] %= mod;
            }
        }
    }
    
    cout << dp[r-1][c-1] << endl;
    
    return 0;
}


