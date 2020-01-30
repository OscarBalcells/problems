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
const int oo = 1e8 + 7;
const int nax = 1e5 + 5;

int mod;
int n;

vector<int> edges[nax];
pair<int,int> up[nax], down[nax];
vector<pair<int,int>> downs[nax];
vector<int> children[nax];
vector<pair<int,int>> pref[nax], suf[nax];

#define all_white first
#define sth_is_black second

int mult(const int a, const int b) {
    return (ll) a * b % mod;
}
int add(const int a, const int b) {
    return (a + b) % mod;
}

void merge(pair<int,int>& a, const pair<int,int> b) {
    a.all_white = mult(a.all_white, b.all_white);
    a.sth_is_black = add(
        mult(a.sth_is_black, add(b.sth_is_black, b.all_white)),
        mult(a.all_white, b.sth_is_black)
    );
}

pair<int,int> process(const pair<int,int> a) {
    return {a.all_white, add(a.all_white, a.sth_is_black)};
}

// num of ways of painting vertex a {white, black}
void dfs_one(int a, int parent) {
    pair<int,int> p = {1, 0};
    for(int& b : edges[a]) if(b != parent) {
        children[a].push_back(b);
        dfs_one(b, a);
        merge(p, down[b]);
        downs[a].push_back(down[b]);
    }
    down[a] = p; //process(p);
}

void dfs_two(int a, int parent) {
    
    for(int i = 0; i < (int)children[a].size(); ++i) {
    
        int b = children[a][i];
        pair<int,int> p = {1, 0};
        
        if(i > 0) {
            merge(p, pref[a][i-1]);
        }
        
        if(i < (int)children[a].size()-1) {
            merge(p, suf[a][i+1]);
        }
        
        if(a != 1) {
            merge(p, up[a]);
        }
        
        up[b] = process(p);
        dfs_two(b, a);
    }
}

int main() {

    scanf("%d%d",&n,&mod);
    
    for(int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d%d",&a,&b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    dfs_one(1, -1);
    
    for(int a = 1; a <= n; ++a) {
        int k = downs[a].size();
        assert(k == (int)children[a].size());
        
        //debug() << imie(k) imie(children[a]) imie(downs[a]);
        
        pair<int,int> p = {1, 0};
        for(int i = 0; i < k; ++i) {
            merge(p, downs[a][i]);
            pref[a].push_back(p);
        }
        
        p = {1, 0};
        for(int i = k-1; i >= 0; --i) {
            merge(p, downs[a][i]);
            suf[a].push_back(p);
        }
        
        reverse(suf[a].begin(), suf[a].end());
        
        debug() << imie(a) imie(pref[a]) imie(suf[a]);
    }
    
    dfs_two(1, -1);
    
    for(int a = 1; a <= n; ++a) {
        
        pair<int,int> p = {1, 0};
        
        if(!children[a].empty()) {
            debug() << imie(a) imie(pref[a].back()) imie(down[a]);
            assert(down[a] == pref[a].back());
            merge(p, pref[a].back());
        }
        
        if(a != 1) {
            merge(p, up[a]);
        }
        
        debug() << imie(p);
        p = process(p);
        printf("%d\n", p.sth_is_black);
    }

    return 0;
}


