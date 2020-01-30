#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll mod = 1e9 + 7;
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
matrix power(matrix A, ll p) {
    
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
    
    int n; ll k;
    scanf("%d %lld", &n, &k);
    
    matrix G(n+1, vector<ll>(n+1, 0));
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            scanf("%lld", &G[i][j]);
        }
    }
    
    G = power(G, k);
    
    ll ans = 0;
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            add_self(ans, G[i][j]);
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
