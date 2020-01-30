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

const int oo = 1e8;

int main() {
    
    int n;
    char line[16];
    int board[16];
    ll dp[16][16];
    
    while(scanf("%s", line) == 1) {
        n = strlen(line);
        
        for(int i = 0; i < n; ++i) {
            if(line[i] == '?') board[i] = -2;
            else if(line[i] >= '0' && line[i] <= '9') board[i] = line[i]-'0'-1;
            else board[i] = 9+(line[i]-'A');
            for(int j = 0; j < n; ++j) dp[i][j] = 0;
        }
        
        board[n] = -2;
        
        for(int col = 0; col < n; ++col) {
            if(board[col] != -2) {
                int r = board[col];
                int nr = board[col+1];
                
                if(abs(r-nr) < 2) continue;
                
                if(col == 0) { dp[col][r] = 1; continue; }
                
                for(int prev = 0; prev < n; ++prev) {
                    if(abs(r-prev) > 1) {
                        dp[col][r] += dp[col-1][prev];
                    }
                }
                
            } else {
                for(int row = 0; row < n; ++row) if(abs(row-board[col+1]) > 1) {
                    if(col == 0) { dp[col][row] = 1; continue; }
                    for(int prev = 0; prev < n; ++prev) if(abs(prev - row) > 1) {
                        dp[col][row] += dp[col-1][prev];
                    }
                }
            }
        }
        
        ll ans = 0;
        
        for(int r = 0; r < n; ++r) {
            ans += dp[n-1][r];
        }
        
        cout << ans << endl;
        
    }


    return 0;
}





