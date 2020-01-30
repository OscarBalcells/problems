#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int n, k, m;
ll dp[3][52][52][53];

ll barcode(int last, int ngroups, int nbars, int size) {

	ll ans = 0;

	if(dp[last][ngroups][nbars][size] != -1) {
		return dp[last][ngroups][nbars][size]; 
	}

	if(nbars == n && ngroups == k) return 1;
	else if(nbars == n) return 0;

	if(last == 0) {   //next one is zero or next one is one

		if(size+1 <= m) ans += barcode(0, ngroups, nbars+1, size+1); 
		if(ngroups+1 <= k) ans += barcode(1, ngroups+1, nbars+1, 1);

	} else if(last == 1) {

		if(size+1 <= m) ans += barcode(1, ngroups, nbars+1, size+1);
		if(ngroups+1 <= k) ans += barcode(0, ngroups+1, nbars+1, 1);

	}		

	dp[last][ngroups][nbars][size] = ans;
	return ans;

}

int main() {
	
	while(scanf("%d%d%d",&n, &k, &m) != EOF) {
		
		memset(dp, -1, sizeof dp);
		ll ans = barcode(0, 1, 1, 1);
		printf("%lld\n", ans);
	
	}

}
