#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vii = vector<ii>;
const ll oo = 1e18L+7;

vector<vector<ll>> dp;
vector<vector<ll>> cost;

void compute(int g, int i, int j, int l, int r) {
    
    if(i > j || l > r) return;
    
    int mid = (i+j) >> 1;
    int bestk = l;
    
    for(int k = l; k <= min(mid, r); ++k) {
        if(dp[mid][g] > dp[k][g-1]+cost[k+1][mid]) {
            dp[mid][g] = dp[k][g-1]+cost[k+1][mid];
            bestk = k;
        }
    }
    
    compute(g, mid+1, j, bestk, r);
    compute(g, i, mid-1, l, bestk);
}

int main() {
    
    int l, g;
    assert(scanf("%d %d",&l,&g) == 2);
    
    vector<ll> crazy(l);
    for(ll& x : crazy) {
        assert(scanf("%lld", &x) == 1);
    }
    
    dp.assign(l+1, vector<ll>(g+1, oo));
    cost.resize(l+1);
    vector<ll> pref(l+1, (ll)0);
    
    pref[1] = crazy[0];
    for(int to = 2; to <= l; ++to) {
        pref[to] = pref[to-1]+crazy[to-1];
    }
    
    cost[0].assign(l+1, (ll)0);
    for(int from = 1; from <= l; ++from) {
        cost[from].assign(l+1, (ll)0);
        for(int to = from; to <= l; ++to) {
            cost[from][to] = (pref[to] - pref[from-1]) * (to-from+1);
        }
    }
    
    for(int j = 1; j <= l; ++j) {
        dp[j][1] = cost[1][j];
    }
    
    for(int i = 2; i <= g; ++i) {
        compute(i, 1, l, 1, l-1); 
    }
    
    vi digits;
    while(dp[l][g] > 0) {
        digits.push_back(int((ll)dp[l][g] % 10));
        dp[l][g] /= 10;
    }
    
    reverse(digits.begin(), digits.end());
    
    for(int& d : digits) {
        printf("%d", d);
    }
    printf("\n");
    
    //~ printf("%lld\n", dp[l][g]);
    
    return 0;
}


