#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    
    cin >> n >> m;
    
    cout << n << endl;
    
    for(int i = 2; i <= n; ++i) {
        cout << rand()%(n-1)+1 << " " << i << endl;
    }
    
    cout << m << endl;
    
    for(int i = 0; i < m; ++i) {
        cout << rand()%n+1 << " " << rand()%(n/2) << endl;
    }
}
