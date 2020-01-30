#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

const int oo = 1e9+7;
using ll = long long int;
using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

vector<pair<ll,ll>> sccs;
vi visited, added, stk, l, h, cost;
vi edges[(int)1e5+7];
int timer = 0;

void dfs(int u) {
    
    h[u] = l[u] = timer++;
    visited[u] = 1;
    stk.push_back(u);
    
    for(int v : edges[u]) {
        if(l[v] == -1) {
            dfs(v);
        }
        
        if(visited[v] == 1) { //si no ha formado ya su scc
            l[u] = min(l[u], l[v]);
        }
    }
    
    if(l[u] == h[u]) {
        pair<ll,ll> scc = make_pair((ll)oo, 1ll);
        while(1) {
            int v = stk.back(); 
            stk.pop_back();
            assert(!added[v]);
            
            added[v] = 1;
            visited[v] = 0;
            
            if(scc.first > cost[v]) { scc.first = (ll)cost[v]; scc.second = 1ll; }
            else if(scc.first == cost[v]) { scc.second++; }
            
            if(v == u) break;
        }
        
        assert(scc.first != (ll)oo);
        sccs.push_back(scc);
    }
}


int main() {
    
    int n;
    scanf("%d",&n);
    
    cost.resize(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d",&cost[i]);
    }
    
    int m;
    scanf("%d",&m);
    
    for(int i = 0; i<  m; ++i) {
        int a, b;
        scanf("%d%d",&a,&b);
        a--; b--;
        edges[a].push_back(b);
    }
    
    visited.assign(n,0);
    added.assign(n,0);
    l.assign(n,-1);
    h.assign(n,-1);

    
    for(int u = 0; u < n; ++u) {
        if(l[u] == -1) dfs(u);
    }
    
    for(int i = 0; i < n; ++i) {
        assert(added[i]);
    }
    
    ll ans = 0;
    ll hm = 1;
    
    for(ii scc : sccs) {
        ans += scc.first;
        hm *= scc.second;
        hm %= oo;
        assert(scc.second > 0);
    }
    
    printf("%lld %lld\n", ans, hm);
    
    return 0;
}
