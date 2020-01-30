#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
const int nax = 1e5+7;

vector<int> AdjList[nax];
vector<int> low, in;
int timer = -1;
set<ii> edges;

void dfs(int a, int p = 0) {
    low[a] = in[a] = ++timer;
    for(int b : AdjList[a]) if(b != p) {
        if(low[b] == -1) {
            dfs(b, a);
            low[a] = min(low[a], low[b]);
            if(low[b] > in[a]) { //can't climb up
                printf("0\n");
                exit(0);
            }
            if(edges.count(ii(b,a))) continue;
            edges.insert(ii(a,b));
        } else {
            low[a] = min(low[a], in[b]);
            if(edges.count(ii(b,a))) continue;
            edges.insert(ii(a,b));
        }
    }
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }
    
    low.assign(n, -1);
    in.assign(n, -1);
    
    dfs(0);
    
    for(ii e : edges) {
        printf("%d %d\n", e.first+1, e.second+1);
    }

    return 0;
}
