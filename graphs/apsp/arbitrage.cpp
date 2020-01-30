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

const ll oo = 100000000;

int main() {
    
    int n;
    
    while(scanf("%d", &n) == 1) {
    
        double AdjMatrix[20][20][20];
        int p[20][20][20];
        
        memset(AdjMatrix, 0, sizeof AdjMatrix);
        memset(p, -1, sizeof p);
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                (i == j ? AdjMatrix[i][j][0] = 1.0 : scanf("%lf", &AdjMatrix[i][j][0]));
                p[i][j][0] = i;
            }
        }
        
        for(int r = 1; r < n; ++r) {
            for(int k = 0; k < n; ++k) {
                for(int i = 0; i < n; ++i) {
                    for(int j = 0; j < n; ++j) {
                        double tmp = AdjMatrix[i][k][r-1] * AdjMatrix[k][j][0];
                        if(tmp > AdjMatrix[i][j][r]) {
                            AdjMatrix[i][j][r] = tmp;
                            p[i][j][r] = k;
                        }
                    }
                }
            }
        }
        
        bool done = false;
        for(int r = 1; r < n && !done; ++r) {
            for(int i = 0; i < n && !done; ++i) {
                if(AdjMatrix[i][i][r] > 1.01) {
                    vi seq(r+1);
                    seq[r] = p[i][i][r];
                    for(int j = r-1; j >= 0; --j) {
                        seq[j] = p[i][seq[j+1]][j];
                    }
                    for(int j = 0; j <= r; ++j) {
                        cout << seq[j]+1 << " ";
                    }
                    cout << seq[0]+1 << endl;
                    done = true;
                }
            }
        }
        
        if(!done) {
            cout << "no arbitrage sequence exists" << endl;
        }
        
        
    }
    
    return 0;
}
