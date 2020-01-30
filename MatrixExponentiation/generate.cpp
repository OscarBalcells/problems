#include <bits/stdc++.h>

using namespace std;

int main() {

    int tc = 1000;
    printf("%d\n", tc);
    srand(time(NULL));
    
    for(int i = 0; i < tc/2; ++i) {
        int n = rand() % 100000;
        int m = rand() % 30 + 1;
        printf("%d %d\n", n, m);
    }
    
    for(int i = 0; i < tc/2; ++i) {
        int n = rand() % 5 + 1;
        int m = rand() % 5 + 1;
        printf("%d %d\n", n, m);
    }

}
