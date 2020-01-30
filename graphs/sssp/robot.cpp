#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

int dr[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {

    int R, C;
    
    while(scanf("%d%d",&R,&C)) {
    
        if(R == 0) return 0;
        
        vector<vector<int>> grid;
        grid.resize(R);
        for(int i = 0; i < R; ++i) grid[i].assign(C, 0);
        
        int rows; 
        scanf("%d",&rows);
    
        while(rows--) {
            int row, hm;
            scanf("%d%d",&row,&hm);
            
            while(hm--) {
                int col; scanf("%d",&col);
                grid[row][col] = -1;
            }
        }
        
        ii s; scanf("%d%d",&s.first,&s.second);
        ii d; scanf("%d%d",&d.first,&d.second);
        
        queue<ii> q; q.push(s);
        
        while(!q.empty())  {
            ii u = q.front(); q.pop();
            int row = u.first, col = u.second;
            
            for(int i = 0; i < 4; ++i) {
                
                if(row+dr[i][0] >= 0 && row+dr[i][0] < R &&
                col+dr[i][1] >= 0 && col+dr[i][1] < C &&
                grid[row+dr[i][0]][col+dr[i][1]] == 0) {
                    
                    q.push(ii(row+dr[i][0],col+dr[i][1]));
                    grid[row+dr[i][0]][col+dr[i][1]] = grid[row][col]+1;
                    if(row+dr[i][0] == d.first && col+dr[i][1] == d.second) { //we have it
                        while(!q.empty()) q.pop();
                    }
                }
            }
        }
        
        printf("%d\n", grid[d.first][d.second]);
        
    }
    
    return 0;
}
