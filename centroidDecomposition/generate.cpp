
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n = 100;
    int q = 100;
    
    vector<pair<int,int>> edges(n-1);
    
    for(int i = 0; i < n-1; ++i) {
        edges[i].first = rand() % 100;
        edges[i].second = rand() % 20 + 40;
    }
    
    sort(edges.begin(), edges.end());
    
    printf("%d\n", n);
    for(int i = 0; i < n-1; ++i) {
        printf("%d %d\n", edges[i].second, 50);
    }
    
    printf("%d\n", q);
    for(int i = 0; i < n-1; ++i) {
        int t, v;
        t = rand() % 2;
        v = rand() % 100;
        printf("%d %d\n", t, v);
    }
    
    return 0;

}
