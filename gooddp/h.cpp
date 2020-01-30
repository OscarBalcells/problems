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
const int MAXN = 1e3+7;

vector<vector<int>> dp(MAXN, vector<int>(MAXN, 0));
char grid[MAXN][MAXN];

void add(int& a, int b) {
    a += b;
    if(a >= mod) {
        a -= mod;
    }
}

int main() {
    
    int h, w;
    string line;
    scanf("%d%d",&h,&w);
    getline(cin, line);
    
    for(int r = 1; r <= h; ++r) {
        getline(cin, line);
        for(int c = 1; c <= w; ++c) {
            grid[r][c] = line[c-1];
            dp[r][c] = 0;
        }
    }
    
    dp[1][1] = 1;
    
    for(int r = 1; r <= h; ++r) {
        for(int c = 1; c <= w; ++c) {
            if(grid[r][c] == '#') continue;
            add(dp[r+1][c], dp[r][c]);
            add(dp[r][c+1], dp[r][c]);
        }
    }
    
    printf("%d\n", dp[h][w]);
    
    return 0;
}


