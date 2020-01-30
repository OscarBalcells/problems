#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long int ll;
typedef vector<ll> vl;

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

    int m, n;
    while(scanf("%d%d",&m,&n)) {
        
        if(m == 0 && n == 0) return 0;
        
        vector<pair<ll, ii>> edges;
        ll total = 0;
        
        for(int i = 0; i < n; ++i) {
            int c1, c2; ll l;
            scanf("%d%d%lld",&c1,&c2,&l);
            edges.push_back(pair<ll,ii>(l,ii(c1,c2)));
            total += l;
        }
        
        sort(edges.begin(), edges.end());
        
        ll saving = 0;
        UnionFind UF = UnionFind(m);
        
        for(int i = 0; i < n; ++i) {
            int c1 = edges[i].second.first, c2 = edges[i].second.second; ll l = edges[i].first;
            if(!UF.sameSet(c1,c2)) {
                saving += l;
                UF.UnionSet(c1,c2);
            }
        }
        
        printf("%lld\n",total-saving);
    }

    return 0;
}
