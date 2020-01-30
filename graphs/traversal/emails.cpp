#include <bits/stdc++.h>

using namespace std;

int son[50005];
int dp[50005];
bool visited[50005];
bool cyclic[50005];

int isCyclic(int now) {

	if(visited[now] == true) {
		return now;
	}

	visited[now] = true;
	int ans = isCyclic(son[now]);
	visited[now] = false;
	return ans; 

}

int countCycle(int now, int start, int size) {

	if(now == start && size > 0) return size;
	return countCycle(son[now], start, size+1);

}

void setSize(int now, int size) {
	
	if(cyclic[now] == true) {
		return;	
	}	

	cyclic[now] = true;
	dp[now] = size;

	setSize(son[now], size);
}

int dfs(int now) {
	
	if(cyclic[now] == true) return dp[now];	
	if(dp[now] != -1) return dp[now];

	int ans = 1 + dfs(son[now]);
	dp[now] = ans;
	return dp[now]; 
}

int main() {

	int TC;
	scanf("%d", &TC);
	
	for(int tc = 1; tc <= TC; ++tc) { 

		int n;
		scanf("%d", &n);

		memset(visited, false, sizeof visited);
		memset(dp, -1, sizeof dp);
		memset(cyclic, false, sizeof cyclic);

		for(int i = 0; i < n; ++i) {
			int from, to;
			scanf("%d %d", &from, &to);
			son[from] = to;				
		}	

		for(int parent = 1; parent <= n; ++parent) {
			if(!cyclic[parent]) {
				int ans = isCyclic(parent);	
				if(!cyclic[ans]) {
					int size = countCycle(ans, ans, 0 );			
			 		setSize(ans, size);
				}
			}
		} 

		
		int ans = 0;
		int winner = -1;

		for(int parent = 1; parent <= n; ++parent) {
			
			if(cyclic[parent] == true) {
				if(dp[parent] > ans) {
					winner = parent;
					ans = dp[parent];
				}	
			} else {
				int opt = dfs(parent);		
				if(opt > ans) {
					winner = parent;
					ans = opt;	
				}
			}	
			
		} 	

		printf("Case %d: %d\n", tc, winner);	
	}	

}
