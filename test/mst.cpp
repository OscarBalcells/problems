#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
using ii = pair<int,int>;

const int nax = 1e5+7;
vector<int> parent, start, end;
vector<int> adj[nax];
set<ii> bridges;
int timer = -1;

int findSet(int a) {
    if(parent[a] == -1) return a;
    else return parent[a] = findSet(parent[i]);
}

void unite(int a, int b) {
    parent[a] = b;
}

void findBridges(int a, int p) {
    start[a] = end[a] = ++timer;
    
    for(int b : adj[a]) if(b != p) {
        if(start[b] == -1) { //my son in rooted tree
            findBridges(b, a);
            if(end[b] > start[a]) {
                //bridge
                bridges.insert(ii(min(a,b),max(a,b)));
            } else {
                end[a] = min(end[a], end[b]);
            }
        } else { //back edge
            end[a] = min(end[a], start[b]);
        }
    }
}

bool isBridge(int a, int b) {
    return (bridges.count(a,b) == 1) || (bridges.count(b,a) == 1);
}

int main() {
    
    //first find bridges,
    //then see same-weighted
    
    int n, m;
    scanf("%d%d",&n,&m);
    
    parent.assign(n, -1);
    start.assign(n,-1);
    end.assign(n,-1);
    
    map<ii,ii> pruneEdges;
    
    for(int i = 0; i < m; ++i) {
        int a, b, w;
        scanf("%d%d%d",&a,&b,&w);
        a--; b--;
        if(pruneEdges[ii(min(a,b),max(a,b))].first == 0 || pruneEdges[ii(min(a,b),max(a,b))].first > w) {
            pruneEdges[ii(min(a,b),max(a,b))].first = w;
            pruneEdges[ii(min(a,b),max(a,b))].second = i;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    
    vector<int> status(m, 0); //0 is none, 1 is some, 2 is all
    
    findBridges(0, 0);
    
    set<ii,ii> edges;
    
    for(auto it = pruneEdges.begin(); it != pruneEEdges.end(); ++it) {
        if(it->second.first == 0) continue;
        int a = it->first.first, b = it->first.second, i = it->second.second, w = it->second.first;
        if(isBridge(a,b)) {
            status[i] = 2;
        } else {
            edges.insert(make_pair(ii(w,i),ii(a,b)));
        }
    }
    
    auto it = edges.begin();
    
    while(auto it != edges.end()) {
        int w = it->first.first, i = it->first.second, a = it->second.first, b = it->second.second;
        
    }
    
    return 0;
}
