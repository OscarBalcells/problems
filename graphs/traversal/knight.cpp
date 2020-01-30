#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

int moves[4][2] = {{1,1}, {1,-1}, {-1,1}, {-1,-1}};

int main() {

    int TC;
    scanf("%d", &TC);
    
    for(int tc = 1; tc <= TC; ++tc) {
    
        int r, c, m, n;
        scanf("%d %d %d %d", &r, &c, &m, &n);
        int w;
        scanf("%d", &w);
        
        vector<vi> grid;
        grid.resize(r);
        for(int i = 0; i < r; ++i) {
            grid[i].assign(c, 0);
        }
        
        for(int i = 0; i < w; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            grid[x][y] = -1; //grid with water
        }
        
        queue<ii> q;
        if(grid[0][0] != -1) q.push(ii(0,0));
        int even = 0;
        int odd = 0;
        bool visited[r][c];
        
        while(!q.empty()) {
            ii pos = q.front(); q.pop();
            int x = pos.first, y = pos.second;
            if(grid[x][y] != 0) continue;
            memset(visited, false, sizeof visited);
            
            int a = m, b = n;
            for(int i = 0; i < 4; ++i) {
                int rx = x + moves[i][0] * a;
                int ry = y + moves[i][1] * b;
                if(rx < 0 || rx >= r || ry < 0 || ry >= c) continue;
                if(grid[rx][ry] >= 0 && !visited[rx][ry]) {
                    grid[x][y]++;
                    if(grid[rx][ry] == 0) {
                        q.push(ii(rx, ry));
                    }
                    visited[rx][ry] = true; //grid being visited
                }
            }
            
            a = n, b = m;
            for(int i = 0; i < 4; ++i) {
                int rx = x + moves[i][0] * a;
                int ry = y + moves[i][1] * b;
                if(rx < 0 || rx >= r || ry < 0 || ry >= c) continue;
                if(grid[rx][ry] >= 0 && !visited[rx][ry]) {
                    grid[x][y]++;
                    if(grid[rx][ry] == 0) {
                        q.push(ii(rx, ry));
                    }
                    visited[rx][ry] = true; //grid pos being visited
                }
            }
            
            if(grid[x][y] % 2 == 0) even++;
            else odd++;
        }
        
        printf("Case %d: %d %d\n", tc, even, odd);
    }

    return 0;
}
