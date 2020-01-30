#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vector<vi> adjList;
vi color;
int v;

bool bipartite(int s) {

    vector<bool> visited(v, false);
    vi color(v, 2);
    queue<int> q; q.push(s);
    color[s] = 1; visited[s] = true;
    
    while(!q.empty()) {
        
        int u = q.front(); q.pop();
        
        for(int i = 0; i < (int)adjList[u].size(); ++i) {
            int v = adjList[u][i];
            if(color[u] == color[v]) {
                return false;
            } else {
                color[v] = 1 - color[u];
                if(!visited[v]) {
                    q.push(v);
                    visited[v] = true;
    } } } }
    
    return true;
    
}

int main() {
    
    while(true) {
        scanf("%d", &v);
        if(v == 0) return 0;
        adjList.clear();
        adjList.resize(v);
        
        int c1, c2;
        while(scanf("%d %d", &c1, &c2)) {
            if(c1 == c2 && c1 == 0) break;
            c1--; c2--;
            adjList[c1].push_back(c2);
            adjList[c2].push_back(c1);
        }
    
        if(bipartite(0)) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
    
    
    return 0;
}
