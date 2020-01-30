#include <bits/stdc++.h>
using namespace std;


//increasing - decreasing

int main() {
    
    int n;
    scanf("%d",&n);
    vector<int> pillars(n);
    
    for(int& x : pillars) {
        scanf("%d",&x);
    }
    
    bool increasing = true;
    int prev = -1;
    
    for(int i = 0; i < n; ++i) {
        int now = pillars[i];
        if(now > prev) {
            if(!increasing) {
                printf("NO\n");
                exit(0);
            }
        } else if(now < prev) {
            if(increasing) {
                increasing = false;
            }
        } else if(now == prev) {
            printf("NO\n");
            exit(0);
        }
        prev = now;
    }
    
    printf("YES\n");
}
