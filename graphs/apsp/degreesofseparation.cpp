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

const int oo = 1000000;

int AdjMatrix[55][55];

int main() {
    
    int p, r, tc = 1;
    
    while(true) {
        
        cin >> p >> r;
        
        if(p == 0 && r == 0) return 0;
        
        map<string, int> names;
        
        for(int i = 0; i < 53; ++i) {
            for(int j = 0; j < 53; ++j) {
                AdjMatrix[i][j] = oo;
                if(i == j) AdjMatrix[i][j] = 0;
            }
        }
        
        int cur = 0;
        
        for(int i = 0; i < r; ++i) {
            
            string p1, p2;
            cin >> p1 >> p2;
            
            if(names.count(p1) == 0) {names[p1] = cur; cur++; }
            if(names.count(p2) == 0) {names[p2] = cur; cur++; }
            
            int u = names[p1], v = names[p2];
            
            AdjMatrix[u][v] = 1;
            AdjMatrix[v][u] = 1;
        }

        for(int k = 0; k < p; ++k) {
            for(int i = 0; i < p; ++i) {
                for(int j = 0; j < p; ++j) {
                    AdjMatrix[i][j] = min(AdjMatrix[i][j], AdjMatrix[i][k]+AdjMatrix[k][j]);
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < p; ++i) {
            for(int j = i+1; j < p; ++j) {
                ans = max(ans, AdjMatrix[i][j]);
            }
        }
        
        if(ans >= oo/4) {
            cout << "Network " << tc++ << ": DISCONNECTED" << endl << endl;
        } else {
            cout << "Network " << tc++ << ": " << ans << endl << endl;
        }
    }
    
    return 0;
}


