#include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[105][105];

int hm(int number, int used) {
	
	int z = 0;
	int ans = 0;

	if(dp[number][used] != -1) return dp[number][used];

	if(used == k-1) return 1;

	while(z <= number) {
		ans += hm(number-z, used+1);
		ans %= 1000000;
		z++;
	}

	dp[number][used] = ans;
	return ans;
}

int main() {


	while(scanf("%d%d", &n, &k)) {

		if(n == 0 && k == 0) break;

		memset(dp, -1, sizeof dp);
		int ans = hm(n, 0);	
		printf("%d\n", ans);

	}

	return 0;
}
