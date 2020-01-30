#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

using ll = long long;
const int oo = 1e9+7;
const int nax = 5007;

int cost[nax][nax];
int dp[nax][nax];

void compute(int g, int leftj, int rightj, int leftk, int rightk) {
    
    if(leftj > rightj) return;
    
    int mid = (leftj+rightj) >> 1;
    int bestk = leftk;
    
    for(int k = leftk; k <= min(mid, rightk); ++k) {
        int val = dp[k][g-1] + cost[k+1][mid];
        if(val < dp[mid][g]) {
            bestk = k;
            dp[mid][g] = val;
        }
    }
    
    compute(g, leftj, mid-1, leftk, bestk);
    compute(g, mid+1, rightj, bestk, rightk);
}

int main() {
    
    int n = 8, k = 3;
    //scanf("%d%d", &n,&k);
    
    int heights[nax];
    memset(heights, 0, sizeof heights);
    
    for(int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        heights[i] = x;
    }

    int pref[nax][nax];
    //memset(pref, 0, sizeof pref);

    // N^2
    for(int right = 1; right <= n; ++right) {
        for(int left = 1; left <= right; ++left) {
            if(heights[left] > heights[right]) pref[right][left]++;
            pref[right][left] += pref[right][left-1];
        }
    }
    
    //memset(cost, 0, sizeof 0);
    
    // N^2
    for(int start = 1; start <= n; ++start) {
        for(int end = start; end <= n; ++end) {
            cost[start][end] = cost[start][end-1]+(pref[end][end]-pref[end][start-1]);
        }
    }
    
    //memset(dp, oo, sizeof dp);

    for(int i = 0; i <= n; ++i) {
        dp[i][1] = cost[1][i];
    }
    
    // N*K log N
    for(int g = 2; g <= k; ++g) {
        compute(g, g, n, 1, n-1);
    }
    
    printf("%d\n", dp[n][k]);
    
    return 0;
}


