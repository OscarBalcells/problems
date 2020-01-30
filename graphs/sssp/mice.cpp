 #include <bits/stdc++.h>
 
 using namespace std;
 
 typedef vector<int> vi;
 typedef pair<int,int> ii;
 
 const int oo = 10e8+7;
 
 int main() {
 
    int TC;
    scanf("%d",&TC);
    bool first = true;
    
    while(TC--) {
    
        if(!first) printf("\n");
        first = false;
        
        int n, e, t, m;
        scanf("%d%d%d%d",&n,&e,&t,&m);
        e--;
        
        vector<vector<ii>> AdjList(n);
        
        for(int i = 0; i < m; ++i) {
            int a, b, w;
            scanf("%d%d%d",&a,&b,&w); 
            a--; b--;
            AdjList[b].push_back(ii(a,w)); //inv -> calling from destination
        }
        
        vector<int> dist(n, oo); dist[e] = 0;
        priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, e));
        
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

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(dist[i] <= t) ans++;
        }
        
        printf("%d\n", ans);
    
    }
 
    return 0;
    
}
