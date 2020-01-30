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

vector<vector<vi>> dp;
vector<vector<vi>> fakedp;
vector<vi> grid;
int n, k;

void solve(int row) {
    
    for(int col = 0; col < n; ++col) {
        for(int left = 0; left < k; ++left) {
            fakedp[row][col][left] = dp[row][col][left];
        }
    }
    for(int col = 0; col < n; ++col) {
        for(int left = 0; left < k; ++left) {
            if(fakedp[row][col][left] == -oo) continue;
            
            int running = fakedp[row][col][left];
            int stepped = left;
            
            //down now!
            if(row+1 < n && stepped + (grid[row+1][col] < 0 ? 1 : 0) < k) dp[row+1][col][stepped+(grid[row+1][col] < 0 ? 1 : 0)] = max(dp[row+1][col][stepped + (grid[row+1][col] < 0 ? 1 : 0)], running+grid[row+1][col]);
            
            //right
            for(int cx = col+1; cx < n && stepped < k; ++cx) {
                running += grid[row][cx];
                if(grid[row][cx] < 0) stepped++;
                
                if(stepped < k) {
                    dp[row][cx][stepped] = max(dp[row][cx][stepped], running);
                }
                
                if(stepped < k && row+1 < n && stepped + (grid[row+1][cx] < 0 ? 1 : 0) < k) {
                    dp[row+1][cx][stepped + (grid[row+1][cx] < 0 ? 1 : 0)] = max(dp[row+1][cx][stepped + (grid[row+1][cx] < 0 ? 1 : 0)], running+grid[row+1][cx]);
                }
            }
            
            running = fakedp[row][col][left];
            stepped = left;
            
            //left 
            for(int cx = col-1; cx >= 0 && stepped < k; --cx) {
                running += grid[row][cx];
                if(grid[row][cx] < 0) stepped++;
                
                if(stepped < k) {
                    dp[row][cx][stepped] = max(dp[row][cx][stepped], running);
                }
                
                if(stepped < k && row+1 < n && stepped + (grid[row+1][cx] < 0 ? 1 : 0) < k) {
                    dp[row+1][cx][stepped + (grid[row+1][cx] < 0 ? 1 : 0)] = max(dp[row+1][cx][stepped + (grid[row+1][cx] < 0 ? 1 : 0)], running+grid[row+1][cx]);
                }
            }
            
        }
    }
    
}


int main() {
    int tc = 1;
    while(scanf("%d%d",&n,&k)) {
        
        if(n == 0 && k == 0) return 0;
        k++;
        grid.resize(n); dp.resize(n); fakedp.resize(n);
        
        for(int i = 0; i < n; ++i) {
            grid[i].resize(n);
            dp[i].resize(n);
            fakedp[i].resize(n);
            
            for(int j = 0; j < n; ++j) {
                int x; scanf("%d",&x);
                grid[i][j] = x;
                dp[i][j].assign(k, -oo);
                fakedp[i][j].assign(k, -oo);
            }
        }
        
        dp[0][0][(grid[0][0] < 0 ? 1 : 0)] = grid[0][0]; 
        
        for(int i = 0; i < n; ++i) {
            solve(i);
        }
        
        int ans = -oo;
        for(int i = 0; i < k; ++i) {
            ans = max(ans, dp[n-1][n-1][i]);
        }

        if(ans == -oo) cout << "Case " << tc << ": impossible" << endl;
        else cout << "Case " << tc << ": " << ans << endl;
        tc++;
    }
    
    return 0;
}


