#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9+5;
typedef pair<int,int> ii;

int main() {

    int N;
    scanf("%d",&N);
    
    for(int tc = 1; tc <= N; ++tc) {
    
        int n, m, s, t;
        scanf("%d%d%d%d", &n, &m, &s, &t);
        
        vector<vector<ii>> AdjList(n);
        
        for(int i = 0; i < m; ++i) {
            int a, b, w;
            scanf("%d%d%d",&a,&b,&w);
            
            AdjList[a].push_back(ii(b,w));
            AdjList[b].push_back(ii(a,w));
        }
        
        vector<int> dist(n, oo); dist[s] = 0;
        priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
        
        while(!pq.empty()) {
            
            ii front = pq.top(); pq.pop();
            int d = front.first, u = front.second;
            
            if(d > dist[u]) continue;
            
            for(int i = 0; i < (int)AdjList[u].size(); ++i) {
                ii v = AdjList[u][i]; // (vertex, weight)
                
                if(dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push(ii(dist[v.first], v.first));
                }
            }
        }
    
        if(dist[t] == oo) printf("Case #%d: unreachable\n", tc);
        else printf("Case #%d: %d\n", tc, dist[t]);
    }

    return 0;
}
