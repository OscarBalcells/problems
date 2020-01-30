#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;

vector<vector<vector<int>>> grid;
int N, M;

bool validPos(int r, int c) {
    
    if(r <= 0 || r >= N) return false;
    if(c <= 0 || c >= M) return false;
    if(grid[r][c][0] == -1) return false;
    if(grid[r-1][c][0] == -1) return false;
    if(grid[r][c-1][0] == -1) return false;
    if(grid[r-1][c-1][0] == -1) return false;
    
    return true;
}

int main() {
    
    while(scanf("%d%d",&N,&M)) {
        if(N == 0 && M == 0) return 0;
    
        grid.resize(N);
        
        for(int r = 0; r < N; ++r) {
            grid[r].resize(M);
            for(int c = 0; c < M; ++c) {
                grid[r][c].resize(4);
                scanf("%d",&grid[r][c][0]);
                if(grid[r][c][0] == 1) {
                    grid[r][c][0] = -1;
                    grid[r][c][1] = -1;
                    grid[r][c][2] = -1;
                    grid[r][c][3] = -1;
                } else {
                    grid[r][c][0] = 999999;
                    grid[r][c][1] = 999999;
                    grid[r][c][2] = 999999;
                    grid[r][c][3] = 999999;
                }
            }
        }
        
        int s1, s2, d1, d2, ndir; string dir;
        cin >> s1 >> s2 >> d1 >> d2 >> dir;
        if(dir == "east") ndir = 0;
        else if(dir == "north") ndir = 1;
        else if(dir == "west") ndir = 2;
        else if(dir == "south") ndir = 3;
        
        queue<vector<int>> q; 
        vector<int> tmp(3);
        tmp[0] = s1; tmp[1] = s2; tmp[2] = ndir;
        //int ondir = ndir;
        q.push(tmp);
        grid[s1][s2][ndir] = 0;
        
        while(!q.empty()) {
         
            int r = q.front()[0], c = q.front()[1], ndir = q.front()[2]; q.pop();
            int rx, cx;
            
            //printf("At pos r=%d c=%d and ndir=%d there is %d\n",r,c,ndir,grid[r][c][ndir]);
            
            for(int i = 1; i <= 3; ++i) {
                if(ndir == 0) { rx = r; cx = c+i; }
                else if(ndir == 1) { rx = r-i; cx = c; }
                else if(ndir == 2) { rx = r; cx = c-i; }
                else if(ndir == 3) { rx = r+i; cx = c; }
                
                if(validPos(rx, cx)) {
                    if(grid[rx][cx][ndir] > grid[r][c][ndir]+1) {
                        grid[rx][cx][ndir] = grid[r][c][ndir]+1;
                        tmp[0] = rx; tmp[1] = cx; tmp[2] = ndir;
                        q.push(tmp);
                    }
                } else {
                    break;
                }
            }
            
            int dx = ndir-1, dy = ndir+1;
            if(ndir == 0) dx = 3;
            if(ndir == 3) dy = 0;
            
            if(grid[r][c][dx] > grid[r][c][ndir]+1) {
                grid[r][c][dx] = grid[r][c][ndir]+1;
                tmp[0] = r; tmp[1] = c; tmp[2] = dx;
                q.push(tmp);
            }
            
            if(grid[r][c][dy] > grid[r][c][ndir]+1) {
                grid[r][c][dy] = grid[r][c][ndir]+1;
                tmp[0] = r; tmp[1] = c; tmp[2] = dy;
                q.push(tmp);
            }
        }
        
        //int ans = grid[d1][d2][ondir];
        int ans = min(grid[d1][d2][0], min(grid[d1][d2][1], min(grid[d1][d2][2], grid[d1][d2][3])));
        if(ans == 999999) {
            printf("-1\n");
        } else {
            printf("%d\n",ans);
        }
        grid.clear();
    }

    return 0;
}
