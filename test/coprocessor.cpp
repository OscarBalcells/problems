#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<vector<int>> edges(n);
    vector<int> num(n, 0), in(n, 0), pro(n);
    int ans = 0;
    
    for(int i = 0; i < n; ++i) {
        scanf("%d", &pro[i]);
        num[i] = pro[i];
        ans = max(ans, pro[i]);
    }
    
    for(int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        in[b]++;
    }
    
    queue<int> q;
    
    for(int i = 0; i < n; ++i) {
        if(in[i] == 0) {
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int a = q.front();
        q.pop();
        
        for(int b : edges[a]) {
            in[b]--;
            if(in[b] == 0) {
                q.push(b);
            }
            num[b] = max(num[b], num[a]+((!pro[a] && pro[b]) ? 1 : 0));
            ans = max(ans, num[b]);
        
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
