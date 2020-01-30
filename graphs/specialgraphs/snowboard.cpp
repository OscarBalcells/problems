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

vector<vi> dp;
vector<vi> grid;
int r, c;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};

bool valid(int i, int j) {
    if(i < 0 || j < 0 || i >= r || j >= c) return false;
    return true;
}

int dfs(int i, int j) {
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int ans = 0;
    
    for(int z = 0; z < 4; ++z) {
        if(valid(i+dr[z], j+dc[z]) && grid[i+dr[z]][j+dc[z]] < grid[i][j]) {
            ans = max(ans, dfs(i+dr[z], j+dc[z]));
        }
    }
    
    ans++;
    dp[i][j] = ans;
    return ans;
}


int main() {
    
    int TC;
    scanf("%d\n", &TC);
    
    while(TC--) {
        
        string name; 
        cin >> name >> r >> c;
        
        dp.clear(); grid.clear();
        dp.resize(r); grid.resize(r);
        for(int i = 0; i < r; ++i) { grid[i].resize(c); dp[i].assign(c, -1); }
        
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                int x; cin >> x;
                grid[i][j] = x;
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                ans = max(ans, dfs(i, j));
            }
        } 
        
        cout << name << ": " << ans << endl;
        
        
    }
    
    
    return 0;
}


