#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long int ll;

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

    int TC;
    scanf("%d",&TC);
    
    for(int tc = 1; tc <= TC; ++tc)  {
    
        int n, r;
        scanf("%d%d",&n,&r);
        
        vii p(n);
        //O(n^2) adj matrix
        for(int i = 0; i < n; ++i) {
            scanf("%d%d",&p[i].first,&p[i].second);
        }

        vector<pair<double, ii>> edges;
        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                edges.push_back(pair<double,ii>(sqrt((p[i].first-p[j].first)*(p[i].first-p[j].first) + (p[i].second-p[j].second)*(p[i].second-p[j].second)), ii(i,j)));
        } }
        
        sort(edges.begin(), edges.end());
        
        UnionFind UF = UnionFind(n);
        double extension = 0;
        double railroad = 0;
        int states = 1;
        for(int i = 0; i < (int)edges.size(); ++i) {
            int u = edges[i].second.first, v = edges[i].second.second;
            if(!UF.sameSet(u, v)) {
                if(edges[i].first > r) {states++; railroad += edges[i].first;}
                else extension += edges[i].first;
                UF.UnionSet(u, v);
            }
        }
        
        printf("Case #%d: %d %d %d\n",tc,states,(int)round(extension),(int)round(railroad)); 
        
    }

    return 0;
}   
