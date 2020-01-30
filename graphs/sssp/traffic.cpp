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
const ll oo = 1e9+7;

bool visited[205];
vector<vector<pair<int,ll>>> AdjList(205);
vector<bool> negativeCycle(205);
vector<ll> dist(205);

void markNegative(int v) {
    visited[v] = true;
    negativeCycle[v] = true;
    
    for(int i = 0; i < (int)AdjList[v].size(); ++i) {
        if(!visited[AdjList[v][i].first] && !negativeCycle[AdjList[v][i].first]) {
            markNegative(AdjList[v][i].first);
        }
    }
    visited[v] = false;
}


int main() {
    
    int n, tc = 1;
    memset(visited, false, sizeof visited);
    
    while(scanf("%d",&n) == 1) {
        
        int m;
        int q;
        
        vi junctions;
        
        for(int i = 0; i < n; ++i) {
            int x; 
            scanf("%d",&x); 
            junctions.push_back(x); 
            
            dist[i] = oo;
            AdjList[i].clear();
            negativeCycle[i] = false;
        }

        scanf("%d",&m);
        
        for(int i = 0; i < m; ++i) {
            int c1, c2;
            scanf("%d%d",&c1,&c2);
            c1--; c2--;
            ll w = (junctions[c2]-junctions[c1])*(junctions[c2]-junctions[c1])*(junctions[c2]-junctions[c1]);
            AdjList[c1].push_back(ii(c2, w));
        }
        
        
        //build dist table O(VE)
        dist[0] = 0;
        
        for(int i = 0; i < n-1; ++i) {
            for(int u = 0; u < n; ++u) {
                for(int j = 0; j < (int)AdjList[u].size(); ++j) {
                    ii v = AdjList[u][j];
                    dist[v.first] = min(dist[v.first], dist[u]+v.second);
                }
            }
        }
        
        //debug() << imie(dist);
        
        //check for negative cycle O(E)
        
        for(int u = 0; u < n; ++u) {
            for(int j = 0; j < (int)AdjList[u].size(); ++j) {
                ii v = AdjList[u][j];
                if(dist[v.first] > dist[u] + v.second) {
                    //still not relaxed yet, so negative cycle
                    if(!negativeCycle[u]) markNegative(u);
                }
            }
        }
        //debug() << imie(negativeCycle);
        
        scanf("%d",&q);
        
        printf("Set #%d\n", tc);
        for(int i = 0; i < q; ++i) {
            int c; 
            scanf("%d",&c);
            c--;
            if(negativeCycle[c] || dist[c] < 3 || dist[c] > 999000000) {
                printf("?\n");
            } else {
                printf("%lld\n",dist[c]);
            }
        }
        tc++;
    }
    
    return 0;
}


