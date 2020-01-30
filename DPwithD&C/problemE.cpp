#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vii = vector<ii>;
const int oo = 1e9 + 7;
const int nax = 4e3 + 5;

vector<vector<int>> in; //(n, vector<int>(n, 0));
vector<vector<int>> cost; //(n,vector<int>(n, 0));
vector<int> prefCost[nax];
vector<vector<int>> dp;

// how unhappy is this person going to be 
// if it's in a group from people from i to j
int getIndCost(int person, int i, int j) {
    int b = prefCost[person][j];
    int a = (i-1 >= 0 ? prefCost[person][i-1] : 0);
    return b - a;
}

void compute(int g, int i, int j, int l, int r) {
    
    if(i > j) return;
    
    int mid = ((i+j) >> 1);
    int bestk = l;
    
    for(int k = l; k <= min(r, mid); ++k) {
        int val = dp[k][g-1] + cost[k+1][mid];
        if(dp[mid][g] > val) {
            bestk = k;
            dp[mid][g] = val;
        }
    }
    
    //debug() << imie(g) imie(mid) imie(i) imie(j) imie(l) imie(bestk) imie(r);
    compute(g, mid+1, j, bestk, r);
    compute(g, i, mid-1, l, bestk);
}

int main() {
    
    int n, hm;
    scanf("%d%d",&n,&hm);
    
    in.resize(n);
    cost.resize(n);
    
    for(int i = 0; i < n; ++i) {
        in[i].resize(n);
        for(int j = 0; j < n; ++j) {
            scanf("%d", &in[i][j]);
        }
    }
    
    printf("FINISHED READING\n");
    
    // O(n^2)
    
    // cost of placing person p1 in some interval 
    for(int person1 = 0; person1 < n; ++person1) {
        prefCost[person1].assign(n, 0);
        int run = 0;
        for(int person2 = 0; person2 < n; ++person2) {
            if(person2 < person1) run += in[person1][person2]; //only add if it's less
            prefCost[person1][person2] = run;
        }
    }
    
    printf("FINISHED IND COSTS\n");
    
    // O(n^2)

    // cost of each possible interval
    for(int from = n-1; from >= 0; --from) {
        cost[from].resize(n);
        cost[from][from] = 0;
        for(int to = from+1; to < n; ++to) {
            cost[from][to] = cost[from][to-1] + getIndCost(to, from, to); 
        }
    }
    
    //~ vector<vector<int>> dp(n, vector<int>(hm+1, oo));
    dp.resize(n);

    // dp[i][j] is the minimum cost of sending first i+1 people
    // to the first j gondolas (plural)
    
    //debug() << imie(cost);
    
    printf("ALMOST FINISHED WITH LIGHT PART\n");
    
    // O (n^2)
    for(int i = 0; i < n; ++i) {
        dp[i].assign(hm+1, oo);
        dp[i][1] = cost[0][i]; 
    }
    
    printf("FINISHED LIGHT PART\n");
    
    dp[0][1] = 0;
    
    for(int i = 2; i <= hm; ++i) {
        compute(i, 0, n-1, 0, n-2);
        //~ for(int j = 0; j < n; ++j) {
            //~ for(int k = 0; k < j; ++k) {
                //~ dp[j][i] = min(dp[j][i], dp[k][i-1]+cost[k+1][j]);
            //~ }
        //~ }
    }
    
    printf("%d\n", dp[n-1][hm]);
    
    return 0;
}


