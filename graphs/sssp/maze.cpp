#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

const int oo = 2000000000;
int N, M;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {1, 0, -1, 0};

bool valid(int r, int c) {
    if(r < 0 || c < 0 || r >= N || c >= M) return false;
    return true;
}

int main() {

    int TC;
    scanf("%d",&TC);
    
    while(TC--) {
        
        scanf("%d%d",&N,&M); 
        
        vector<vector<int>> maze(N);
        
        for(int i = 0; i < N; ++i) {
            maze[i].resize(M);
            for(int j = 0; j < M; ++j) {
                scanf("%d",&maze[i][j]);
            }
        }
        
        vector<vector<int>> dist(N); 
        for(int i = 0; i < N; ++i) dist[i].assign(M, oo);
        dist[0][0] = maze[0][0];
        priority_queue< pair<int,ii>, vector<pair<int,ii>>, greater<pair<int,ii>> > pq; 
        pq.push(pair<int,ii>(maze[0][0],ii(0,0)));
    
        while(!pq.empty()) {
            
            pair<int,ii> front = pq.top(); pq.pop();
            int d = front.first, r = front.second.first, c = front.second.second;
            
            if(d > dist[r][c]) continue;
            
            for(int i = 0; i < 4; ++i) {
                int rx = r+dc[i], cx = c+dr[i];
                
                if(valid(rx, cx) && dist[r][c] + maze[rx][cx] < dist[rx][cx]) {
                    dist[rx][cx] = dist[r][c] + maze[rx][cx];
                    pq.push(pair<int,ii>(dist[rx][cx], ii(rx, cx)));
                }
            }
        }
        
        printf("%d\n", dist[N-1][M-1]);
        
    }
    
    return 0;
}
