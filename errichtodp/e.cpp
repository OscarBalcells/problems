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
    
    string a, b;
    getline(cin, a);
    getline(cin, b);

    vector<vector<pair<int,ii>>> dp(a.size()+1);
    for(int i = 0; i < (int)a.size()+1; ++i) {
        dp[i].assign((int)b.size()+1, make_pair(-oo, make_pair(0, 0)));
    }
    
    dp[0][0] = make_pair(0, make_pair(0, 0));
    
    for(int i = 0; i < (int)a.size(); ++i) {
        for(int j = 0; j < (int)b.size(); ++j) {
            if(a[i] == b[j] && dp[i+1][j+1].first < dp[i][j].first+1) {
                dp[i+1][j+1] = make_pair(dp[i][j].first+1, make_pair(i, j));
            }
            
            if(dp[i+1][j].first < dp[i][j].first) {
                dp[i+1][j] = make_pair(dp[i][j].first, make_pair(i, j));
            }
            
            if(dp[i][j+1].first < dp[i][j].first) {
                dp[i][j+1] = make_pair(dp[i][j].first, make_pair(i, j));
            }
        }
    }
    
    pair<int,ii> ans = make_pair(0, make_pair(0, 0));
    
    for(int i = 0; i < (int)a.size()+1; ++i) {
        for(int j = 0; j < (int)b.size()+1; ++j) {
            if(dp[i][j].first > ans.first) {
                ans.first = dp[i][j].first;
                ans.second = {i, j};
            }
        }
    }
    
    ii cur = ans.second;
    string s = "";
    
    while(cur.first > 0 && cur.second > 0) {
        int i = cur.first, j = cur.second;
        ii prev = dp[i][j].second;
        
        if(prev == make_pair(i-1, j-1)) {
            s += a[i-1];
        }
        cur = prev;
    }  
    
    reverse(s.begin(), s.end());
    cout << s << endl;
    
    return 0;
}


