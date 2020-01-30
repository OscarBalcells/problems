#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
using ll = long long int;
 
bool comp(pair<ii,ii> e1, pair<ii,ii> e2) {
    return e1.first.second < e2.first.second; //sorteamos por plata
}
 
vector<int> parent(207);
set<pair<ii,ii>> grafo;
int n;
const ll oo = 2e18+7;
 
int findSet(int i) {
    if(parent[i] == -1) return i;
    parent[i] = findSet(parent[i]);
    return parent[i];
}
 
int mst() {
    parent.assign(n, -1);
    int nc = n;
    auto it = grafo.begin();
    
    while(it != grafo.end()) {
        int a = findSet(it->second.first);
        int b = findSet(it->second.second);
        if(a != b) {
            parent[a] = b;
            if(--nc == 1) return it->first.first;
            it++;
        } else {
            grafo.erase(it++);
        }
    }
    return -1;
}
 
int main() {
    
    int m;
    ll G, S;
    scanf("%d%d",&n,&m);
    scanf("%lld %lld", &G, &S);
 
    vector<pair<ii,ii>> edges(m);
    
    for(int i = 0; i < m; ++i) {
        int a, b, g, s;
        scanf("%d %d %d %d", &a, &b, &g, &s);
        a--; b--;
        edges[i] = make_pair(make_pair(g,s), make_pair(a,b));
    }
    
    sort(edges.begin(), edges.end(), comp);
 
    ll ans = oo;
    int i = 0;
    while(i < m) {
        int j = i;
        int plata = edges[i].first.second;
        while(j < m && edges[j].first.second == plata) {
            grafo.insert(edges[j++]);
        }
        int oro = mst();
        if(oro != -1) ans = min(ans, ll(plata)*S+ll(oro)*G);
        i = j;
    }
    
    if(ans == oo) printf("-1\n");
    else printf("%lld\n", ans);
    
    return 0;
}
