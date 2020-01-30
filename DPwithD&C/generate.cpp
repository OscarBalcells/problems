#include <bits/stdc++.h>
using namespace std;

int main() {

    int n = 4000;
    int k = n / 4;
    
    printf("%d %d\n", n, k);
    
    for(int i = 0; i < n; ++i) {
        printf("2");
        for(int j = 1; j < n; ++j) {
            printf(" 2");
        }
        printf("\n");
    }

    return 0;
}
