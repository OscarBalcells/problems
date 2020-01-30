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
const int oo = 1e9+7;
const int mod = 1e9+7;
const int MAXK = 10005;

char k[MAXK];

int add(const int& a, const int& b) {
    return (a + b) % mod;
}

int sub(const int& a, const int b) {    
    return (a - b + mod) % mod;
}

int main() {
    
    int d;
    int n;
    
    scanf("%s", k);
    scanf("%d", &d);
    
    n = strlen(k);
    
    vector<int> smaller(d, 0); // all possible sums of the digits up to ind index
    int equalsum = 0;
    
    for(int ind = 0; ind < n; ++ind) {
        vector<int> new_smaller(d, 0);
        
        for(int sum = 0; sum < d; ++sum) {
            for(int digit = 0; digit < 10; ++digit) {
                new_smaller[(sum+digit)%d] = add(new_smaller[(sum+digit)%d], smaller[sum]);
            }
        }
        
        for(int digit = 0; digit < k[ind]-'0'; ++digit) {
            new_smaller[(equalsum+digit)%d] = add(new_smaller[(equalsum+digit)%d], 1);
        }
        
        equalsum += k[ind]-'0';
        equalsum %= d;
        smaller = new_smaller;
    }
    
    if(equalsum != 0) smaller[0] = sub(smaller[0], 1);
    printf("%d\n", smaller[0]);
    
    return 0;
}


