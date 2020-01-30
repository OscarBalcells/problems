#include <bits/stdc++.h>

using namespace std;
int n;
char grid[105][105];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

void floodfill(int r, int c) {

	if(r == n) return;
	if(r == -1) return;
	if(c == n) return;
	if(c == -1) return;
	
	if(grid[r][c] != '.') {

		grid[r][c] = '.';

		for(int i = 0; i < 4; ++i) {
			floodfill(r+dr[i], c+dc[i]);
		}

	} else {
		return;
	} 

}

int main() {

	int TC;
	scanf("%d", &TC);
	
	for(int tc = 1; tc <= TC; ++tc) {
		
		scanf("%d", &n);

		for(int r = 0; r < n; ++r) for(int c = 0; c < n; ++c) {
			scanf("%c", &grid[r][c]);
			if(grid[r][c] != '@' && grid[r][c] != '.' && grid[r][c] != 'x') scanf("%c", &grid[r][c]);
		}	

		int ships = 0;

		for(int r = 0; r < n; ++r) for(int c = 0; c < n; ++c) {
			if(grid[r][c] == 'x') {
				ships++;
				floodfill(r, c);
			}
		}	

		printf("Case %d: %d\n", tc, ships);

	}

	return 0;
} 
