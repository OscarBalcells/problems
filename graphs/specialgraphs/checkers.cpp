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

const int mod = 1000007;
const int oo = 1e9+7;

vector<vi> grid;
vector<vi> dp;
int n;

bool valid(int r, int c) {
    if(r < 0 || c < 0 || r >= n || c >= n) return false;
    return true;
}

void solve(int row) {
    
    for(int c = 0; c < n; ++c) {
        
        if(grid[row][c] == -1) continue;
        
        if(valid(row+1, c-1)) dp[row][c] += dp[row+1][c-1];
        if(valid(row+1, c+1)) dp[row][c] += dp[row+1][c+1];
        
        if(valid(row+2, c-2) && grid[row+1][c-1] == -1) dp[row][c] += dp[row+2][c-2];
        if(valid(row+2, c+2) && grid[row+1][c+1] == -1) dp[row][c] += dp[row+2][c+2];
        
        dp[row][c] %= mod;
        
    }
}

int main() {
    
    int TC;
    cin >> TC;
    
    for(int tc = 1; tc <= TC; ++tc) {
        
        scanf("%d",&n);
        
        grid.clear(); dp.clear();
        grid.resize(n); dp.resize(n);
        
        for(int i = 0; i < n; ++i) {
            grid[i].assign(n, -1);
            dp[i].assign(n, 0);
        }
        
        int r, c;
        
        string line;
        getline(cin, line);
        
        for(int i = 0; i < n; ++i) {
            getline(cin, line);
            
            for(int j = 0; j < n; ++j) {
                char ch = line[j];
                if(ch == '.') {
                    grid[i][j] = 0;
                } else if(ch == 'W') {
                    grid[i][j] = 0;
                    r = i; c = j;
                }
            }
        }
        
        dp[r][c] = 1;
        
        for(int row = r-1; row >= 0; --row) {
            solve(row);
        }
        
        ll ans = 0;
        for(int col = 0; col < n; ++col) {
            ans += dp[0][col];
            ans %= mod;
        }
        
        cout << "Case " << tc << ": " << ans << endl;
    }
    
    return 0;
}

