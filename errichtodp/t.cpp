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
const int oo = 1e8+7;
const int mod = 1e9+7;

void add_self(int& x, int y) {
    x += y;
    if(x >= mod) {
        x -= mod;
    }
}

int main() {
    
    int n;
    string s;
    scanf("%d",&n);
    getline(cin, s);
    getline(cin, s);
    
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    
    // dp[n][a] - number of valid permutations of size n
    // with ending number a
    
    for(int len = 2; len <= n; ++len) {
        vector<int> new_dp(n+1, 0);
        vector<int> run(len+1, 0);
        int r = 0;
        
        if(s[len-2] == '<') { //a has to be smaller
            for(int i = 1; i <= len-1; ++i) {
                add_self(r, dp[i]);
                run[i] = r;
            }
        } else if(s[len-2] == '>') { //a has to be equal or bigger
            for(int i = len-1; i >= 1; --i) {
                add_self(r, dp[i]);
                run[i] = r;
            }
        }
        
        debug() << imie(s[len-2]) imie(dp) imie(run);
        
        for(int b = 1; b <= len; ++b) {
            
            if(s[len-2] == '<') {
                add_self(new_dp[b], run[b-1]); //a = b-1
            } else {
                add_self(new_dp[b], run[b]); //a = b
            }
            
            /*
            for(int a = 1; a <= len-1; ++a) {
                int real_a = a;
                if(a >= b) {
                    ++real_a; //push one up
                }
                
                if((real_a < b) != (s[len-2] == '<')) {
                    continue;
                }
                
                debug() << imie(a) imie(b) imie(dp[a]) imie(len);
                
                add_self(new_dp[b], dp[a]);   
            }
            */
        }
        dp = new_dp;
    }
    
    int answer = 0;
    for(int i = 1; i <= n; ++i) {
        add_self(answer, dp[i]);
    }
    
    cout << answer << endl;
    
    return 0;
}


