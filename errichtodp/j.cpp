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

double ev[301][301][301];
double p[301][301][301];

int main() {
    
    int n;
    scanf("%d",&n);
    
    int x = 0, y = 0, z = 0;
    
    for(int i = 0; i < n; ++i) {
        int q; scanf("%d",&q);
        if(q == 1) x++;
        else if(q == 2) y++;
        else if(q == 3) z++;
    }
    
    p[x][y][z] = 1.0;
    
    for(int c = n; c >= 0; --c) {
        for(int b = n; b >= 0; --b) {
            for(int a = n; a >= 0; --a) {
            
                if(a == 0 && b == 0 && c == 0) continue;
                else if(a + b + c > n) continue;
            
                //arithmetic progession -> stay always here
                double p_waste = double(n-(a+b+c)) / double(n);
                //p_waste + p_waste^2 + p_waste^3 + ... = S
                // 1 + S = S / p_waste
                //S = p_waste * (1 / (1 - p_waste))
                //S / p_waste = 1 / (1 - p_waste)
                //1 + S = 1 / (1 - p_waste)
                //S = 1 / (1 - p_waste) - 1
                double ev_waste = p_waste / (1- p_waste) + 1;
                ev[a][b][c] += ev_waste * p[a][b][c];
                
                if(a > 0) {
                    double p_go = double(a) / double(a+b+c); 
                    ev[a-1][b][c] += p_go * ev[a][b][c];
                    p[a-1][b][c] += p[a][b][c] * p_go;
                }
                
                if(b > 0) {
                    double p_go = double(b) / double(a+b+c);
                    ev[a][b-1][c] += p_go * ev[a][b][c];
                    p[a][b-1][c] += p_go * p[a][b][c];
                }
                
                if(c > 0) {
                    double p_go = double(c) / double(a+b+c);
                    ev[a][b][c-1] += p_go * ev[a][b][c];
                    p[a][b][c-1] += p_go * p[a][b][c];
                }
            
            }
        }
    }
    
    printf("%.10lf\n", ev[0][0][0]);
    
    return 0;
}


