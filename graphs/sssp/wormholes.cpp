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

vector<string> split(const string &);


int main() {
    
    int TC;
    scanf("%d",&TC);
    
    while(TC--) {
    
        int n, m;
        scanf("%d%d",&n,&m);
        
        vector<vii> AdjList(n);
        
        for(int i = 0; i < m; ++i) {
            int x, y, t;
            scanf("%d%d%d",&x,&y,&t);
            AdjList[x].push_back(ii(y,t));
        }
        
        vi dist(n, oo); dist[0] = 0;
        
        //build dist table O(VE)
        for(int i = 0; i < n-1; ++i) {
            for(int u = 0; u < n; ++u) {
                for(int j = 0; j < (int)AdjList[u].size(); ++j) {
                    ii v = AdjList[u][j];
                    dist[v.first] = min(dist[v.first], dist[u]+v.second);
                }
            }
        }
        
        //check for negative cycle O(E)
        bool hasNegativeCycle = false;
        for(int u = 0; u < n; ++u) {
            for(int j = 0; j < (int)AdjList[u].size(); ++j) {
                ii v = AdjList[u][j];
                if(dist[v.first] > dist[u] + v.second) {
                    //still not relaxed yet, so negative cycle
                    hasNegativeCycle = true;
                }
            }
        }
        
        (hasNegativeCycle ? printf("possible\n") : printf("not possible\n"));
        
    }
    
    return 0;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

