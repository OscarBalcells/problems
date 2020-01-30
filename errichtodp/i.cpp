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
    
    int n;
    scanf("%d",&n);
    
    vector<double> p;
    p.push_back(1.0);
    
    for(int i = 0; i < n; ++i) {
        
        double pp;
        scanf("%lf",&pp);
        
        p.push_back(0.0);
        
        for(int j = i; j >= 0; --j) {
            
            p[j+1] += p[j] * pp;
            p[j] *= (1.0 - pp);
        }
    }

    double ans = 0.0;
    
    for(int i = 0; i <= n; ++i) {
        int heads = i;
        int tails = n-heads;
        
        if(heads > tails) {
            ans += p[heads];
        }
    }
    
    printf("%.10lf\n", ans);
    
    return 0;
}


