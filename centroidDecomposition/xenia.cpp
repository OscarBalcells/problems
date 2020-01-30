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

vector<int> sub; //size of each subtree
vector<int> level;
vector<int> centroidParent; //parent of this centroid component
vector<vector<int>> edges; //original tree edges
vector<int> ans; //distance to closest red vertex
vector<int> parent;

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

int dist(int a, int b) {
    debug() << imie(a) imie(b) imie(lca.lca(a, b));
    return level[a]+level[b]-(2*level[lca.lca(a, b)]);
}

int dfs(int a, int p, int l) {
    int res = 0;
    if(parent[a] == -1) parent[a] = p;
    if(level[a] == -1) level[a] = l;
    
    for(int b : edges[a]) if(b != parent[a] && centroidParent[b] == -1) {
        res += dfs(b, a, l+1);
    }
    sub[a] = res+1;
    return res+1;
}

int centroid(int a, int p, int n) {
    for(int b : edges[a]) if(b != p && centroidParent[b] == -1) {
        if(sub[b]*2 > n) {
            return centroid(b, a, n);
        } 
    }
    return a;
}

void centroidBuild(int a, int n, int s, int p) {
    dfs(a, -1, -1);
    int c = centroid(a, -1, n);
    
    centroidParent[c] = p;
    int total = 0;
    for(int b : edges[c]) if(b != parent[b] && centroidParent[b] == -1) {
        total += sub[b];
        centroidBuild(b, sub[b], b, c);
    }
    
    if(s != c && centroidParent[s] == -1) {
        centroidBuild(s, n-total-1, s, c);
    }
}

void paint(int a, int p) {
    if(a == -2) return;
    ans[a] = min(ans[a], dist(a, p));
    debug() << imie(a) imie(p) imie(dist(a, p));
    return paint(centroidParent[a], p);
}

int query(int a, int s) {
    if(a == -2) return oo;
    int op1 = ans[a]+dist(a, s), op2 = query(centroidParent[a], s);
    return min(op1, op2);
}


int main() {
    
    int n, m;
    scanf("%d%d", &n, &m);
    
    sub.assign(n, 0);
    centroidParent.assign(n, -1);
    
    level.assign(n, -1);
    parent.assign(n, -1);
    
    edges.resize(n);
    
    for(int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d%d",&a,&b);
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    dfs(0, -1, 0); //first time set up everything
    lca.init(edges);
    centroidBuild(0, n, 0, -2);
    
    debug() << imie(level);
    
    ans.assign(n, oo); //distance from me to closest red vertex
    paint(0, 0); //first is already red
    
    debug() << imie(ans);
    
    while(m--) {
        int t, a;
        scanf("%d%d", &t, &a);
        a--;
        
        if(t == 1) {
            paint(a, a);
        } else {
            printf("%d\n", query(a, a));
        }
    }
    
    return 0;
}


