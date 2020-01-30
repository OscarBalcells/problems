#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

class UnionFind {
private: vi p, rank;
public:
	UnionFind(int N) { 
		rank.assign(N, 0);
		p.assign(N, 0); 
		for(int i = 0; i < N; ++i) p[i] = i; 
	}
	
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); } //with path compression
	
	bool sameSet(int i, int j) { return (findSet(i) == findSet(j)); }
	
	void UnionSet(int i, int j) {
			if(!sameSet(i, j)) {
					int x = findSet(i), y = findSet(j);
					if(rank[x] > rank[y]) p[y] = x;
					else {
						p[x] = y;
						if(rank[x] == rank[y]) { rank[y]++; }
					}
			}
	}
};

int main() {
 
    int n, m;
    vector<pair<int,ii>> edges;
    
    while(scanf("%d%d",&n,&m)) {
        if(n == 0 && m == 0) return 0;
    
        for(int i = 0; i < m; ++i) {
            int u, v, w;
            scanf("%d%d%d",&u,&v,&w);
            edges.push_back(pair<int,ii>(w,ii(u,v)));
        }
        
        sort(edges.begin(), edges.end());
        
        UnionFind UF = UnionFind(n);
        vector<bool> taken(m, false);
        
        for(int i = 0; i < m; ++i) {
            int u = edges[i].second.first, v = edges[i].second.second;
            if(!UF.sameSet(u,v)) {
                UF.UnionSet(u,v);
                taken[i] = true;
            }
        }
        
        bool yep = false;
        for(int i = 0; i < m; ++i) {
            if(!taken[i]) {
                if(!yep) printf("%d",edges[i].first);
                else printf(" %d",edges[i].first);
                yep = true;
            }
        }
        
        if(!yep) {
            printf("forest\n");
        } else {
            printf("\n");
        }
        
        edges.clear();
    }
 
    return 0;
}
