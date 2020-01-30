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

vi rooms, dist;
vector<vi> AdjList;
bool visited[105];
bool positiveCycle[105];

void dfs(int v) {
    visited[v] = true;
    for(int i = 0; i < (int)AdjList[v].size(); ++i) {
        if(!visited[AdjList[v][i]]) dfs(AdjList[v][i]);
    }
}

void markPositive(int v) {
    positiveCycle[v] = true;
    visited[v] = true;
    for(int i = 0; i < (int)AdjList[v].size(); ++i) {
        if(!visited[AdjList[v][i]] && !positiveCycle[AdjList[v][i]]) {
            markPositive(AdjList[v][i]);
        }
    }
    visited[v] = false;
}

int main() {
    
    int n;
    
    while(scanf("%d",&n)) {
        
        if(n == -1) {
            return 0;
        }
        
        memset(positiveCycle, false, sizeof positiveCycle);
        rooms.clear();
        AdjList.clear();
        rooms.clear();
        
        rooms.resize(n);
        dist.assign(n, -oo);
        AdjList.resize(n);
        
        //get input
        for(int i = 0; i < n; ++i) {
            int e, m;
            scanf("%d%d",&e,&m);
            rooms[i] = e;
            for(int j = 0; j < m; ++j) {
                int v; scanf("%d",&v);
                v--;
                AdjList[i].push_back(v);
            }
        }
        
        dist[0] = 100;
        //run bellman-ford O(VE)
        for(int i = 0; i < n-1; ++i) {
            for(int u = 0; u < n-1; ++u) { //I don't care about relaxing outgoing edges from n-1
                for(int j = 0; j < (int)AdjList[u].size(); ++j) {
                    int v = AdjList[u][j];
                    if(dist[u]+rooms[v] <= 0) continue; //can't use this edge
                    dist[v] = max(dist[v], dist[u]+rooms[v]);
                    // -> looking for max dist, not min dist
                }
            }
        }
        
        //debug() << dist;
        
        if(dist[n-1] > 0) {
            printf("winnable\n"); //cool, we can win without tricks
            continue;
        }
        
        memset(visited, false, sizeof visited);
        //see if there is any positive infinite cycle before finish room
        for(int u = 0; u < n-1; ++u) {
            for(int j = 0; j < (int)AdjList[u].size(); ++j) {
                int v = AdjList[u][j];
                if(dist[v] < dist[u] + rooms[v] && dist[u] >  0 && dist[u]+rooms[v] > 0) {
                    //still not relaxed yet, so cycle, if we can get to u
                    if(dist[u] > 0 && !positiveCycle[u]) markPositive(u);
                }
            }
        }
        
        //is it connected?
        memset(visited, false, sizeof visited);
        dfs(0);
        if(visited[n-1] == false) {
            //nope
            printf("hopeless\n");
            continue;
        }
        
        if(positiveCycle[n-1]) printf("winnable\n");
        else printf("hopeless\n");
        
    }
    
    return 0;
}



