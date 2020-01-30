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
const int MAX_SIZE = 3e3+5;

char a[MAX_SIZE], b[MAX_SIZE];

void max_self(pair<int,ii>& f, const int score, const ii pos) {
    if(f.first < score) {
        f.first = score;
        f.second = pos;
    }
}

int main() {
    
    scanf("%s",a);
    scanf("%s",b);
    
    int sa = strlen(a);
    int sb = strlen(b);
    
    vector<vector<pair<int,ii>>> dp(MAX_SIZE);
    
    for(int i = 0; i <= sa; ++i) {
        dp[i].assign(MAX_SIZE, pair<int,ii>(0, ii(-1, -1)));
    }
    
    for(int r = 0; r < sa; ++r) {
        for(int c = 0; c < sb; ++c) {
            
            if(a[r] == b[c]) {
                max_self(dp[r+1][c+1], dp[r][c].first+1, ii(r, c));
            }
            
            max_self(dp[r+1][c], dp[r][c].first, ii(r, c));
            max_self(dp[r][c+1], dp[r][c].first, ii(r, c));
        }
    }
    
    ii pos = ii(-1, -1);
    int mx = 0;
    
    for(int r = 0; r <= sa; ++r) {
        for(int c = 0; c <= sb; ++c) {
            if(dp[r][c].first > mx) {
                mx = dp[r][c].first;
                pos = ii(r, c);
            }
        }
    }
    
    // -> If you only want the size of the LCS
    
    //~ printf("%d\n", mx);
    
    // -> If you want the LCS string
    
    string s = "";
    
    while(pos != ii(-1, -1)) {
        ii newPos = dp[pos.first][pos.second].second;
        if(newPos != ii(-1, -1) && newPos == ii(pos.first-1, pos.second-1)) {
            s += a[newPos.first];
            assert(a[newPos.first] == b[newPos.second]);
        }
        pos = newPos;
    }
    
    if(s.size() > 0) reverse(s.begin(), s.end());
    
    cout << s << endl;

    
    return 0;
}


