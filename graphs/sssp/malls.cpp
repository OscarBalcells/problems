#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int maxr, maxc;

bool valid(int r, int c) {
    if(r < 0 || c < 0 || r > maxr || c > maxc) return false;
    return true;
}

int main() {

    int p1, p2;
    
    while(true) {
        
        scanf("%d",&p1);
        if(p1 == 0) return 0;
        
        maxr = 0;
        maxc = 0;
        
        vii pos1;
        for(int i = 0; i < p1; ++i) {
            int r, c; scanf("%d%d",&r,&c);
            maxr = max(r,maxr);
            maxc = max(c,maxc); 
            pos1.push_back(ii(r,c));
        }
        
        scanf("%d",&p2);
        
        vii pos2;
        for(int i = 0; i < p2; ++i) {
            int r, c; scanf("%d%d",&r,&c);
            maxr = max(r,maxr);
            maxc = max(c,maxc); 
            pos2.push_back(ii(r,c));
        } 
        
        vector<vi> malls, grid;
        
        malls.resize(maxr+1); 
        for(int i = 0; i <= maxr; ++i) {
            malls[i].assign(maxc+1, 0);
        }
        
        grid.resize(maxr+1);
        for(int i = 0; i <= maxr; ++i) {
            grid[i].assign(maxc+1, 999999);
        }

        queue<ii> q;
        
        for(int j = 0; j < (int)pos1.size(); ++j) {
            malls[pos1[j].first][pos1[j].second] = -1; 
            grid[pos1[j].first][pos1[j].second] = 0;
            q.push(pos1[j]); //enqueue all the sources at t0
        }
        
        for(int j = 0; j < (int)pos2.size(); ++j) {
            malls[pos2[j].first][pos2[j].second] = 1;
        }
    
        int best = 999999;
        int rx, cx, r, c;
        ii f;
        
        while(!q.empty()) {
            
            f = q.front(); q.pop();
            r = f.first, c = f.second;
            
            for(int i = 0; i < 4; ++i) {
                rx = r+dr[i], cx = c+dc[i];
                if(!valid(rx, cx) || grid[rx][cx] != 999999) continue;
                
                grid[rx][cx] = grid[r][c]+1;
                if(malls[rx][cx] == 1) best = min(best, grid[rx][cx]);
                
                q.push(ii(rx,cx));
            }
        }
        
        printf("%d\n",best);
        
    }

    return 0;
}
