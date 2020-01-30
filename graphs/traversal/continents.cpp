#include <bits/stdc++.h>

using namespace std;

char grid[21][21];
bool visited[21][21];

int dr[] = {0, 0, 1, -1}; 
int dc[] = {1, -1, 0, 0}; 
char l;

int m, n;

int floodfill(int x, int y) {
	
	int ans = 0;

	if(x < 0) return 0;
	if(x >= m) return 0; 

	if(y < 0) y = m-1;
	if(y >= n) y = 0; 

	if(grid[x][y] == l && !visited[x][y]) {
		ans = 1;	
	} else {
		return 0;	
	}		

	visited[x][y] = true;

	for(int i = 0; i < 4; ++i) {
		ans += floodfill(x+dr[i], y+dc[i]);	
	}

	return ans;
}

int main() {

	while(scanf("%d %d\n", &m, &n) != EOF) {

		memset(visited, false, sizeof visited);
		memset(grid, 'w', sizeof grid);

		for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) {
			scanf("%c", &grid[i][j]);
			if(j == n-1) scanf("\n");
		}

		int x, y;
		scanf("%d %d", &x, &y);
		
		l = grid[x][y];
		floodfill(x, y);

		int ans = 0;

		for(int r = 0; r < m; ++r) for(int c = 0; c < n; ++c) {
			if(!visited[r][c] && grid[r][c] == l) {
				ans = max(ans, floodfill(r, c));
			}	
		}

		printf("%d\n", ans);

	}

	return 0;
}
