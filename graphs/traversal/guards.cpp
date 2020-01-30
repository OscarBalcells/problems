#include <bits/stdc++.h> 

using namespace std;

typedef vector<int> vi;

vector<vi> adjList;
vi color;

int bfs(int s) {
    queue<int> q;
    q.push(s);
    int tot = 0;
    int black = 0;
    color[s] = 1;
    
    while(!q.empty()) {
        int v = q.front(); q.pop();
        tot++;
        if(color[v] == 1) black++;
    
        for(int i = 0; i < (int)adjList[v].size(); ++i) {
            int u = adjList[v][i];
            if(color[u] == 2) {
                color[u] = 1 - color[v];
                q.push(u);
            } else if(color[u] == color[v]) {
                return -1;
            }
        }
    }
    
    if(tot == 1) return 1;
    else return min(black, tot-black);
}

int main() {
    int TC;
    scanf("%d", &TC);
    
    while(TC--) {
        int v, e;
        scanf("%d %d", &v, &e);
        adjList.clear(); color.clear();
        adjList.resize(v); color.assign(v, 2);
        
        for(int i = 0; i < e; ++i) {
            int j1, j2;
            scanf("%d %d", &j1, &j2);
            adjList[j1].push_back(j2);
            adjList[j2].push_back(j1);
        }
        
        int ans = 0;
        bool impos = false;
        for(int i = 0; i < v && !impos; ++i) {
            if(color[i] == 2) {
                int x = bfs(i);
                if(x == -1) impos = true;
                else ans += x;
            }
        }
        
        if(impos) printf("-1\n");
        else printf("%d\n", ans);
    }
}
