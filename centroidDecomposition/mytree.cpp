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
const int oo = 1e9+7;


struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    void init(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

LCA lca;

const int nax = 1e5+7;

vector<vector<int>> edges;
int level[nax], subtree[nax], parent[nax];
vector<int> decomposed;

int dfs1(int a, int p, int l) {
    level[a] = l;
    parent[a] = p;
    subtree[a] = 1;
    for(int b : edges[a]) if(b != p) {
        subtree[a] += dfs1(b, a, l+1);
    }
    return subtree[a];
}

int dfs2(int a) {
    subtree[a] = 1;
    debug() << imie(a) imie(parent[a]);
    for(int b : edges[a]) if(b != parent[a] && decomposed[b] == -2) {
        subtree[a] += dfs2(b);
    }
    return subtree[a];
}

int centroid(int a, int n) {
    bool isCentroid = true;
    int heaviest = -1;
    
    for(int b : edges[a]) if(b != parent[a] && decomposed[b] == -2) {
        if(subtree[b] > n/2) {
            isCentroid = false;
        }
        
        if(heaviest == -1 || subtree[b] > subtree[heaviest]) {
            heaviest = b;
        }
    }
    
    if(isCentroid && n-subtree[a] <= n/2) {
        return a;
    }
    return centroid(heaviest, n);
}

void decompose(int a, int n, int p) {
    dfs2(a);
    int c = centroid(a, n);
    
    decomposed[c] = p;
    
    int total = 0;
    for(int b : edges[c]) if(b != parent[c] && decomposed[b] == -2) {
        total += subtree[b];
        decompose(b, subtree[b], c);
    }
    
    if(decomposed[a] == -2) decompose(a, n-total-1, c);
}

set<ii> ans[nax];
bool color[nax];

int dist(int a, int b) {
    return level[a]+level[b]-(2*level[lca.lca(a, b)]);
}

void paint(int a) {
    color[a] = !color[a];
    
    int up = a;
    while(up != -1) {
        
        if(color[a]) {
            ans[up].insert({dist(a, up), a});
        } else {
            ans[up].erase({dist(a, up), a});
        }
        
        up = decomposed[up];
    }
}

int query(int a) {
    
    int up = a;
    int best = oo;
    
    while(up != -1) {
        if(ans[up].size() > 0) {
            auto it = ans[up].begin();
            best = min(best, dist(a, up)+(it->first));
        }
        up = decomposed[up];
    }
    
    return best;
}

int main() {
    
    int n;
    scanf("%d", &n);
    
    edges.resize(n);
    
    for(int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    lca.init(edges);
    dfs1(0, -1, 0);
    decomposed.assign(n, -2);
    decompose(0, n, -1);
    
    memset(color, false, sizeof color);
    
    int q;
    scanf("%d", &q);
    while(q--) {
        
        int t, v;
        scanf("%d%d", &t,&v);
        v--;
        
        if(t == 0) {
            paint(v);
        } else if(t == 1) {
            int best = query(v);
            if(best > oo/2) {
                printf("-1\n");
            } else {
                printf("%d\n", best);
            }
        }
        
    }
    
    return 0;
}
