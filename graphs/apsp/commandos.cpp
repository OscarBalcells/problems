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
    
    int TC, tc = 1;
    scanf("%d",&TC);
    
    while(TC--) {
        
        int n;
        scanf("%d",&n);
        
        int r;
        scanf("%d",&r);
        
        int AdjMatrix[105][105];
        
        for(int i = 0; i < 105; ++i) {
            for(int j = 0; j < 105; ++j) {
                AdjMatrix[i][j] = oo;
            }
        }
        
        for(int i = 0; i < r; ++i) {
            int c1, c2;
            scanf("%d%d",&c1,&c2);
            AdjMatrix[c1][c2] = 1;
            AdjMatrix[c2][c1] = 1;
        }
        
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    AdjMatrix[i][j] = min(AdjMatrix[i][j], AdjMatrix[i][k] + AdjMatrix[k][j]);
                }
            }
        }
        
        for(int i = 0; i < 105; ++i) {
            AdjMatrix[i][i] = 0;
        }
        
        int s, d;
        scanf("%d%d",&s,&d);
        
        int time = 0;
        for(int i = 0; i < n; ++i) {
            time = max(time, AdjMatrix[s][i] + AdjMatrix[i][d]);
        }
        
        printf("Case %d: %d\n", tc, time);
        tc++;
        
    }
    
    
    
    return 0;
}
