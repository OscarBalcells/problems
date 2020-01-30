#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> before;
vector<bool> done;

bool doable(int task) {

	for(int i = 0; i < (int)before[task].size(); ++i) {
		if(!done[before[task][i]]) return false;
	}
	return true;
}


int main() {

	int n, m;

	while(scanf("%d %d", &n, &m)) {
		
		if(n == 0 && m == 0) return 0;

		before.resize(n);
		done.resize(n, false);
	
		for(int i = 0; i < m; ++i) {
	
			int k, j;
			scanf("%d %d", &k, &j);
			k--; j--;
			before[j].push_back(k);

		}

		int completed = 0;
		vector<int> tasks;

		while(completed < n) {
			for(int i = 0; i < n; ++i) { 
				if(!done[i] && doable(i)) {
					tasks.push_back(i);
					done[i] = true;	
					i = n;
					completed++;
				}
			}	
		}

		for(int i = 0; i < n; ++i) {
			cout << tasks[i]+1;
			if(i < n-1) cout << " ";
			else cout << endl;
		}

		before.clear();
		done.clear();

	}
	
	return 0;
}
