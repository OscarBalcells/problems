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

const ll mod = 1e9+7;
using matrix = vector<vector<ll>>;

void add_self(ll& a, ll b) {
    a = (a+b)%mod;
}

// computes A x B
matrix mult(matrix A, matrix B) {
    
    int rowsa = (int)A.size();
    int colsb = (int)B[1].size();
    int colsa = (int)A[1].size();
    matrix C(rowsa, vector<ll>(colsb));
    
    for(int i = 1; i < rowsa; i++) {
        for(int j = 1; j < colsb; ++j) {
            for(int l = 1; l < colsa; ++l) {
                C[i][j] = (C[i][j] + ((ll)A[i][l] * B[l][j]%mod)) % mod;
            }
        }
    }
    
    return C;
}

// compute A ^ p
matrix power(matrix A, int p) {
    
    if(p == 1) {
        return A;
    } else if(p % 2 == 1) {
        return mult(A, power(A, p-1));
    } else {
        matrix X = power(A, p/2);
        return mult(X, X);
    }
    
}

int main() {
    
    int TC;
    scanf("%d", &TC);
    
    while(TC--) {
        
        int n, k;
        scanf("%d%d", &n, &k);
        
        if(n == 1) {
            printf("%d\n", k);
            continue;
        } else if(k == 1) {
            printf("0\n");
            continue;
        } else if(n == 2) {
            ll ans = 0;
            for(int i = 1; i <= k; ++i) {
                if(i == 1 || i == k) ans += 1;
                else ans += 2;
            }
            printf("%lld\n", ans);
            continue;
        }
    
        matrix F(k+1, vector<ll>(2, 0)); // initial states 
        for(int row = 1; row <= k; ++row) {
            F[row][1] = 1;
        }
        
        matrix T(k+1, vector<ll>(k+1, 0));
        
        for(int col = 1; col <= k; ++col) {
            
            if(col-2 >= 1) T[col][col-2] = 1;
            if(col-1 >= 1) T[col][col-1] = 1;
            
            if(col > 1 && col < k) T[col][col] = 2;
            else T[col][col] = 1;
            
            if(col+1 <= k) T[col][col+1] = 1;
            if(col+2 <= k) T[col][col+2] = 1;
        }
        
        // end in odd column always
         
        int nPowers = (n%2 == 1 ? (n>>1) : (n>>1)-1);
        if(nPowers > 1) T = power(T, nPowers);

        F = mult(T, F);
        
        if(n % 2 == 0) {
            //we got the states of the pre-last row
            ll ans = 0;
            
            for(int i = 1; i <= k; ++i) {
                if(i > 1) add_self(ans, F[i][1]);
                if(i < k) add_self(ans, F[i][1]);
            }
            
            printf("%lld\n", ans);
            
        } else {
            //we got the states of the last row
            ll ans = 0;
            
            for(int i = 1; i <= k; ++i) {
                add_self(ans, F[i][1]);
            }
            
            printf("%lld\n", ans);
        }
        
    }
    
    return 0;
}
