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
const int MAXN = 305;

double prob[MAXN][MAXN][MAXN];
double ev[MAXN][MAXN][MAXN];

int main() {
    
    int n;
    scanf("%d",&n);
    
    int a = 0, b = 0, c = 0;
    
    for(int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        if(x == 1) c++;
        else if(x == 2) b++;
        else if(x == 3) a++;
    }
    
    prob[a][b][c] = 1;
        
    for(int threes = a; threes >= 0; --threes) {
        for(int twos = n; twos >= 0; --twos) {
            for(int ones = n; ones >= 0; --ones) {
            
                if(threes + twos + ones > n) {
                    continue;
                } else if(threes + twos + ones == 0) {
                    continue;
                }
            
                //geometric progression
                //p-bility of staying here
                double p_waste = double(n-(threes+twos+ones))/double(n);
                double ev_waste = p_waste / (1 - p_waste) + 1;
                debug() << imie(ones) imie(p_waste) imie(ev_waste);
                //~ prob[threes][twos][ones] += prob[threes][twos][ones] * p_waste;
                ev[threes][twos][ones] += ev_waste * prob[threes][twos][ones];
                
                debug() << imie(threes) imie(twos) imie(ones) imie(prob[threes][twos][ones]) imie(ev[threes][twos][ones]);
                
                if(threes > 0) {
                    double p_go = double(threes) / double(twos+threes+ones);
                    debug() << imie("Transition to 2") imie(threes) imie(twos) imie(ones) imie(p_go);
                    ev[threes-1][twos+1][ones] += p_go * (ev[threes][twos][ones]);
                    prob[threes-1][twos+1][ones] += p_go * prob[threes][twos][ones];
                }
                
                if(twos > 0) {
                    double p_go = double(twos) / double(twos+threes+ones);
                    debug() << imie("Transition to 1") imie(threes) imie(twos) imie(ones) imie(p_go);
                    ev[threes][twos-1][ones+1] += p_go * (ev[threes][twos][ones]);
                    prob[threes][twos-1][ones+1] += p_go * prob[threes][twos][ones];
                }
                
                if(ones > 0) {
                    double p_go = double(ones) / double(twos+threes+ones);
                    debug() << imie("Transition to 0") imie(threes) imie(twos) imie(ones) imie(p_go);
                    ev[threes][twos][ones-1] += p_go * (ev[threes][twos][ones]);
                    prob[threes][twos][ones-1] += p_go * prob[threes][twos][ones];
                }
            
            }
        }
    }
    
    printf("%.10lf\n", ev[0][0][0]);
    
    return 0;
}


