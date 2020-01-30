    #include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <assert.h>
using namespace std;

using ii = pair<int,int>;
using vi = vector<int>;
const int nax = 1e5+7;

map<ii,int> state;
vector<vector<int>> edges; //normales
vector<ii> baseEdges, batchEdges;
vector<int> parents;
vector<bool> visitedParents;

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
	
	int findSet(int i) { 
        return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
    } //with path compression
	
	bool sameSet(int i, int j) { 
        return (findSet(i) == findSet(j)); 
    }
	
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
    void reset() {
        rank.assign(n, 0);
		p.assign(n, 0); 
		for(int i = 0; i < n; ++i) p[i] = i; 
    }
};

UnionFind uf = UnionFind((int)1e5+7);

void compress(int a) {
    for(int b : edges[a]) if(uf.findSet(b) != uf.findSet(a)) {
        uf.UnionSet(a, b);
        compress(b);
    }
};

void dfs(int a) {
    visitedParents[a] = true;
    assert(a == uf.findSet(a));
    
    for(auto it = batchEdges.begin(); it != batchEdges.end(); ++it) {
        ii edge = it->first;
        int turned = it->second;
        
        if(turned == 1 || visitedParents[a]) continue;
        assert(turned != 0);
         
        int aa = uf.findSet(edge.first);
        int bb = uf.findSet(edge.second);
        
        if(a == aa && a != bb) {
            //visit bb
            dfs(bb);
        } else if(a == bb && a != aa) {
            //visit aa
            dfs(aa);
        }
    }
}

int main() {

    int n, m;
    scanf("%d %d\n", &n, &m);
  
    int k = (int)sqrt(m)+5;
    
    for(int ind = 0; ind < m;) {
        
        batchEdges.clear();
        
        vector<pair<int,ii>> queries;
        
        int indNow = ind;
        for(; ind < indNow+k && ind < m; ++ind) {
            char t;
            scanf("%c",&t);
            if(t == '?') {
                queries.push_back(make_pair(0,make_pair(0,0)));
                scanf("\n");
            } else {
                int a, b;
                scanf("%d %d\n", &a, &b);
                if(a > b) {
                    int z = a;
                    a = b;
                    b = z;
                }
                queries.push_back(make_pair((t == '+' ? 1 : 2), make_pair(a, b)));
                
                if(state[ii(a,b)] == 0) {
                    batchEdges.push_back(ii(a,b));
                    sate[ii(a,b)] = (t == '+' ? 1 : 2);
                }
            }
        }
        
        //define base edges, the existent ones
        //which aren't being queried in batch
        edges.clear();
        edges.resize(n+1);
        vector<ii> newBaseEdges;
        
        for(ii pe : baseEdges) {
            int a = pe.first, b = pe.second;
            if(state[ii(a,b)] == 0) {
                edges[a].push_back(b);
                edges[b].push_back(a);
                newBaseEdges.push_back(ii(a,b));
            }
        }
        
        baseEdges = newBaseEdges;
        
        //compress graph
        uf.reset();

        for(int i = 1; i <= n; ++i) {
            if(uf.findSet(i) == i) {
                compress(i);
            }
        }
        
        //define parents (representants of their
        //respective UF sets
        parents.clear();
        int nParents = 0;
        
        for(int i = 1; i <= n; ++i) {
            if(uf.findSet(i) == i) {
                parents.push_back(ii(i,nParents));
                nParents++;
            }
        }
        
        for(pair<int,ii> q : queries) {
            
            if(q.first == 0) { //? query
                int ans = 0;
                //reset parents, we haven't seen any parent yet
                visitedParents.assign(nParents, false);
                
                //for each parent, check if it hasn't been visited yet
                for(int i = 0; i < nParents; ++i) {
                    if(!visitedParents[i]) {
                        ans++;
                        dfs(parents[i]);
                    }
                }
                
                printf("%d\n", ans);
            } else {
                //change turned status of edge in batch
                int a = q.second.first, b = q.second.second;
                state[ii(a,b)] = (q.first == 1 ? 2 : 1);
            }
        }
        
        //add all edges to base which didn't appear in batch (as prev)
        for(ii edge : baseEdges) {
            int a = edge.first, b = edge.second;
            if(batchEdges[ii(a,b)] < 1) {
                baseEdges.push_back(ii(a,b));
            }
        }
        
        //add all edges to base which are still alive
        for(auto it = batchEdges.begin(); it != batchEdges.end(); ++it) {
            if(it->second == 2) {  
                baseEdges.push_back(it->first);
            }
        }
    }
    
    return 0;
}
