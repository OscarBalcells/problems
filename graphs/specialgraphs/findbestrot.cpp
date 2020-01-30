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

const int mod = 1e9+7;
const int oo = 1e9+7;

vector<vi> AdjList;
vector<map<int,int>> memo;

int height(int v, int prev) {

    if(memo[v].count(prev) > 0) return memo[v][prev];

    int ans = 0;
    
    for(int i = 0; i < (int)AdjList[v].size(); ++i) if(AdjList[v][i] != prev) {
        ans = max(ans, 1+height(AdjList[v][i],v));
    }
    
    return memo[v][prev] = ans;

}

int main() {
    
    int n, tc = 1;
    
    while(scanf("%d",&n) == 1) {
        
        AdjList.clear(); AdjList.resize(n);
        memo.clear(); memo.resize(n);
        
        for(int i = 0; i < n; ++i) {
            int h; scanf("%d",&h);
            AdjList[i].resize(h);
            map<int,int> m;
            memo[i] = m;
            
            for(int j = 0; j < h; ++j) {
                scanf("%d",&AdjList[i][j]);
                AdjList[i][j]--;
            }
        }
        
        int best = oo;
        int worst = -1;
        vi bestRoots;
        vi worstRoots;
        
        for(int r = 0; r < n; ++r) {
            int h = height(r, -1);
            
            if(h < best) {
                bestRoots.clear();
                bestRoots.push_back(r);
                best = h;
            } else if(h == best) {
                bestRoots.push_back(r);
            }
            
            if(h > worst) {
                worstRoots.clear();
                worstRoots.push_back(r);
                worst = h;
            } else if(h == worst) {
                worstRoots.push_back(r);
            }
        }
        
        cout << "Best Roots  :";
        for(auto x : bestRoots) cout << " " << x+1;
        cout << endl;
        cout << "Worst Roots :";
        for(auto x : worstRoots) cout << " " << x+1;
        cout << endl;
    
        tc++;
        
    }

    return 0;
}

