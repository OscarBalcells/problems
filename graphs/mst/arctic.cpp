#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

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
};

double dist(ii pos1, ii pos2) {
    return sqrt((pos1.first-pos2.first)*(pos1.first-pos2.first) + (pos1.second-pos2.second)*(pos1.second-pos2.second));
}

int main() {
    
    int TC;
    scanf("%d",&TC);
    
    while(TC--) {
        
        int s, p;
        scanf("%d%d",&s,&p);
        vector<ii> cords;
        
        for(int i = 0; i < p; ++i) {
            int c1, c2; scanf("%d%d",&c1,&c2);
            cords.push_back(ii(c1,c2));
        }
        
        vector<pair<double, ii>> edges;
        for(int i = 0; i < p; ++i) {
            for(int j = i+1; j < p; ++j) {
                edges.push_back(pair<double,ii>(dist(cords[i],cords[j]), ii(i,j)));
            }
        }
        
        sort(edges.begin(), edges.end());
        
        double d = 0.0;
        UnionFind UF = UnionFind(p);
        
        int total = 0;
        for(int i = 0; i < (int)edges.size() && total < p-s; ++i) {
            int c1 = edges[i].second.first, c2 = edges[i].second.second;
            if(!UF.sameSet(c1,c2)) {
                d = edges[i].first;
                UF.UnionSet(c1,c2);
                total++;
            }
        }
        
        printf("%.2lf\n", d);
        
    }
    
    return 0;
}
