#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

class UnionFind {
private: 
    vi p, rank;
    int n;
public:
	UnionFind(int N) { 
		rank.assign(N, 0);
		p.assign(N, 0); 
		for(int i = 0; i < N; ++i) p[i] = i; 
        n = N;
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
    
    int countSets() {
        set<int> sets;
        for(int i = 0; i < n; ++i) {
            sets.insert(p[i]);
        }
        return (int)sets.size();
    }
    
    void reset() {
		for(int i = 0; i < n; ++i) { p[i] = i; rank[i] = 0; }
    }
};


int main() {

    int TC;
    scanf("%d",&TC);
    
    while(TC--) {
        
        int n, m;
        scanf("%d%d",&n,&m);
        
        vector<pair<int,ii>> edges;
        
        for(int i = 0; i < m; ++i) {
            int s1, s2, w;
            scanf("%d%d%d",&s1,&s2,&w);
            s1--; s2--;
            edges.push_back(pair<int,ii>(w,ii(s1,s2)));
        }
        
        sort(edges.begin(), edges.end());
        vector<ii> bestTree;
        int best = 0, second = 9999999, reached = 0;
        
        UnionFind UF = UnionFind(n);
        for(int i = 0; i < (int)edges.size() && reached < n-1; ++i) {
            int s1 = edges[i].second.first, s2 = edges[i].second.second;
            if(!UF.sameSet(s1,s2)) {
                UF.UnionSet(s1,s2);
                best += edges[i].first;
                bestTree.push_back(ii(s1,s2));
            }
        }
        
        for(int j = 0; j < (int)bestTree.size(); ++j) {
            UF.reset();
            int n1 = bestTree[j].first, n2 = bestTree[j].second;
            int tree = 0;
            reached = 0;
            
            for(int i = 0; i < (int)edges.size() && reached < n-1; ++i) {
                int s1 = edges[i].second.first, s2 = edges[i].second.second;
                if(max(s1, s2) == max(n1, n2) && min(s1, s2) == min(n1, n2)) continue;
                if(!UF.sameSet(s1,s2)) {
                    UF.UnionSet(s1,s2);
                    tree += edges[i].first;
                    reached++;
                }
            }
            
            if(reached == n-1) {
                second = min(second, tree);
            }
        }
        
        printf("%d %d\n", best, second);
        
    }

    return 0;
}
