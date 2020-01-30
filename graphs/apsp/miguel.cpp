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

const ll oo = 100000000;

ll migueladjMatrix[27][27];
ll shahradjMatrix[27][27];

int main() {
    
    int n;
    
    while(scanf("%d\n",&n)) {
        
        //n is n-streets
        if(n == 0) return 0;
        
        for(int i = 0; i < 27; ++i) {
            for(int j = 0; j < 27; ++j) {
                migueladjMatrix[i][j] = oo;
                shahradjMatrix[i][j] = oo;
            }
        }

        
        for(int i = 0; i < n; ++i) {
            char a, b, c, d;
            ll energy;
            scanf("%c %c %c %c %lld\n", &a,&b,&c,&d,&energy);
            if(a == 'Y') {
                if(b == 'U') {
                    shahradjMatrix[c-'A'][d-'A'] = energy;
                } else {
                    shahradjMatrix[c-'A'][d-'A'] = energy;
                    shahradjMatrix[d-'A'][c-'A'] = energy;
                }
            } else {
                if(b == 'U') {
                    migueladjMatrix[c-'A'][d-'A'] = energy;
                } else {
                    migueladjMatrix[c-'A'][d-'A'] = energy;
                    migueladjMatrix[d-'A'][c-'A'] = energy;
                }
            }
        }
        
        
        char p1, p2;
        scanf("%c %c\n", &p1, &p2);
        
        for(int k = 0; k < 27; k++) {
            for(int i = 0; i < 27; ++i) {
                for(int j = 0; j < 27; ++j) {
                    migueladjMatrix[i][j] = min(migueladjMatrix[i][j], migueladjMatrix[i][k] + migueladjMatrix[k][j]);
                    
                }
            }
        }
        
        for(int k = 0; k < 27; k++) {
            for(int i = 0; i < 27; ++i) {
                for(int j = 0; j < 27; ++j) {
                    shahradjMatrix[i][j] = min(shahradjMatrix[i][j], shahradjMatrix[i][k] + shahradjMatrix[k][j]);
                }
            }
        }
        
        for(int i = 0; i < 27; ++i) {
            migueladjMatrix[i][i] = 0;
            shahradjMatrix[i][i] = 0;
        }
        
        //debug() << imie(shahradjMatrix[p1-'A'][1]) imie(migueladjMatrix[p2-'A'][1]);
        ll best = 2*oo;
        vector<char> places;
        
        debug() << imie(migueladjMatrix[p1-'A'][p1-'A']) imie(shahradjMatrix[p2-'A'][p2-'A']);
        
        for(int i = 0; i < 27; ++i) {
            ll ans = migueladjMatrix[p2-'A'][i] + shahradjMatrix[p1-'A'][i];
            if(ans < best) {                
                places.clear();
                best = ans;
                places.push_back('A'+i);
            } else if(ans == best) {
                places.push_back('A'+i);
            }
        }
        
        if(best >= oo/4) {
            printf("You will never meet.\n");
        } else {
            printf("%lld", best);
            for(auto x : places) {
                printf(" %c", x);
            }
            printf("\n");
        }
    
    }
    
    return 0;
}
