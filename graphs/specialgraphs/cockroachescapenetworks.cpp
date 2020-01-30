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

const int oo = 1e7+7;

int main() {

    int TC;
    scanf("%d", &TC);
    
    for(int tc = 1; tc <= TC; ++tc) {
    
        int n, m;
        scanf("%d%d",&n,&m);
        
        vector<vi> AdjMatrix(n+m);
        for(int i = 0; i < n+m; ++i) {
            AdjMatrix[i].assign(n+m, oo);
        }
        
        int size = n;
        
        for(int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d",&u,&v);
            AdjMatrix[u][size] = 1;
            AdjMatrix[size][u] = 1;
            AdjMatrix[size][v] = 1;
            AdjMatrix[v][size] = 1;
            size++;
        }
        
        for(int i = 0; i < n+m; ++i) {
            AdjMatrix[i][i] = 0;
        }
        
        for(int k = 0; k < n+m; ++k) {
            for(int i = 0; i < n+m; ++i) {
                for(int j = 0; j < n+m; ++j) {
                    AdjMatrix[i][j] = min(AdjMatrix[i][j], AdjMatrix[i][k]+AdjMatrix[k][j]);
                }
            }
        }
        
        int ans = oo;
        
        for(int c = 0; c < n+m; ++c) {
            int first = 0, second = 0;
            
            for(int i = 0; i < n; ++i) {
                if(AdjMatrix[c][i] >= first) {
                    second = first;
                    first = AdjMatrix[c][i];
                } else if(AdjMatrix[c][i] > second) {
                    second = AdjMatrix[c][i];
                }
                
            }
            
            ans = min(ans, (first==second ? first+second : oo));
        }
        
        cout << "Case #" << tc << ":" << endl;
        cout << ans/2 << endl << endl;

    }
    
    return 0;
}

