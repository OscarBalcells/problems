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
const int oo = 1e8+7;


int main() {
    
    int n, k;
    scanf("%d%d",&n,&k);
    
    vector<bool> winIfIs(k+1, false);
    vi s(n);
    
    int minStone = oo;
    
    for(int i = 0; i< n; ++i) {
        scanf("%d",&s[i]);
        minStone = min(minStone, s[i]);
    }
    
    for(int i = minStone; i <= k; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i-s[j] >= 0 && winIfIs[i-s[j]] == false) {
                winIfIs[i] = true;
                break;
            }
        }
    }
    
    if(winIfIs[k] == true) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    
    return 0;
}


