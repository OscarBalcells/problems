#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	vector<vector<int>> adjList;
	while(scanf("%d", &n)) {
		
		if(n == 0) return 0;	
		adjList.clear();
		adjList.resize(n);

		int l;
		scanf("%d", &l);
		
		while(l--) {
			
			int i, j;
			scanf("%d %d", &i, &j);
			adjList[i].push_back(j);
			adjList[j].push_back(i);
			
		}
		
		queue<int> q;
		vector<int> colors; colors.resize(n, -1);
		vector<bool> visited; visited.resize(n, false);

		q.push(0); colors[0] = 0;	
		bool isBipartite = true;
		
		while(!q.empty() && isBipartite) {
			
			int v = q.front(); q.pop();
				
			if(visited[v]) continue;

			for(int i = 0; i < (int)adjList[v].size(); ++i) {

				int u = adjList[v][i];

				if(colors[v] == colors[u]) {
					isBipartite = false;		
				} else {
					colors[u] = 1 - colors[v];
					if(!visited[u]) q.push(u);
				}	
			}	

			visited[v] = true;
		}
		if(isBipartite) cout << "BICOLORABLE." << endl;
		else cout << "NOT BICOLORABLE." << endl;
	}	

}
