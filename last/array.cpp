#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
        
    int n, k;
    scanf("%d%d",&n,&k);
    
    vector<int> diffs;
    
    int prev;
    ll total = 0;
    
    for(int i = 0; i < n; ++i) {
        int now;
        scanf("%d",&now);
        if(i > 0) {
            diffs.push_back(now-prev);
            total += ll(now-prev);
        }
        prev = now;
    }
    
    sort(diffs.rbegin(), diffs.rend());

    for(int i = 0; i < k-1; ++i) {
        total -= ll(diffs[i]);
    }
    
    cout << total << endl;
        
    return 0;
}
