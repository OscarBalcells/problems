#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

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

vector<vector<ii>> adjList;
vector<bool> vis;

int dfs(int cur, int obj, int path) {
    
        if(cur == obj) return path;
        if(vis[cur]) return 99999997;
        vis[cur] = true;
        
        int ans = 99999997;
        for(int i = 0; i < (int)adjList[cur].size(); ++i) {
            ans = min(ans, dfs(adjList[cur][i].first, obj, max(path, adjList[cur][i].second)));
        }
        
        vis[cur] = false;
        return ans;
}

int main() {

    int s, c, q, TC = 1;
    
    while(true) {
        cin >> c >> s >> q;
        if(c == 0 && s == 0 &&  q == 0) break;
        if(TC > 1) printf("\n");

        vector<pair<int, ii>> edges;
        
        int c1, c2, w;
        for(int i = 0; i < s; ++i) {
            cin >> c1 >> c2 >> w;
            c1--; c2--;
            edges.push_back(make_pair(w, ii(c1, c2)));
        }
        
        sort(edges.begin(), edges.end());
        
        adjList.clear();
        adjList.resize(c);
        vis.resize(c, false);
        UnionFind UF = UnionFind(c);
        
        for(int i = 0; i < s; ++i) {
                pair<int, ii> front = edges[i];
                int u = front.second.first, v = front.second.second, w = front.first;
                if(!UF.sameSet(u, v)) {
                        adjList[u].push_back(ii(v, w));
                        adjList[v].push_back(ii(u, w));
                        UF.UnionSet(u, v);
                }
        }
        
        printf("Case #%d\n", TC);
        for(int i = 0; i < q; ++i) {
            cin >> c1 >> c2;
            c1--; c2--;
            
            int ans = dfs(c1, c2, 0);
            if(ans == 99999997) printf("no path\n");
            else printf("%d\n", ans);
        }
        
        TC++;
    }

    return 0;
}
