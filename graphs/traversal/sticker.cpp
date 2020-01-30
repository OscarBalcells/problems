#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;

int main() {

	char grid[105][105];	
	ii pos;
	char orientation; //UP, RIGHT, DOWN, LEFT	

	int r, c, nmoves;

	while(scanf("%d %d %d\n", &r, &c, &nmoves)) {

		if(r == 0 && c == 0) return 0;
		
		for(int row = 0; row < r; ++row) { 
			for(int col = 0; col < c; ++col) {

			scanf("%c", &grid[row][col]);
	
			if(grid[row][col] == 'N') pos.first = row, pos.second = col, orientation = 'N';
			if(grid[row][col] == 'S') pos.first = row, pos.second = col, orientation = 'S';
			if(grid[row][col] == 'L') pos.first = row, pos.second = col, orientation = 'L';
			if(grid[row][col] == 'O') pos.first = row, pos.second = col, orientation = 'O';
			}	
			scanf("\n");
		}

		int stickers = 0;

		for(int i = 0; i < nmoves; ++i) {
			char action;
			scanf("%c", &action);	

			if(action == 'F') {

				if(orientation == 'N' && pos.first > 0 && grid[pos.first-1][pos.second] != '#') pos.first--;	
				if(orientation == 'S' && pos.first < r-1 && grid[pos.first+1][pos.second] != '#') pos.first++;	
				if(orientation == 'O' && pos.second > 0 && grid[pos.first][pos.second-1] != '#') pos.second--;	
				if(orientation == 'L' && pos.second < c-1 && grid[pos.first][pos.second+1] != '#') pos.second++;	

				if(grid[pos.first][pos.second] == '*') {
					stickers++;
					grid[pos.first][pos.second] = '.';	
				}

			} else if(action == 'D') {

				if(orientation == 'N') orientation = 'L';
				else if(orientation == 'L') orientation = 'S';
				else if(orientation == 'S') orientation = 'O'; 
				else if(orientation == 'O') orientation = 'N';

			} else if(action == 'E') {

				if(orientation == 'S') orientation = 'L';
				else if(orientation == 'O') orientation = 'S';
				else if(orientation == 'N') orientation = 'O'; 
				else if(orientation == 'L') orientation = 'N';

			}
		}

		printf("%d\n", stickers);
		
	}


	return 0;
}
