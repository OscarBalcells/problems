#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

const int MAXN = 2 * 105000;
const int MAXLOG = 20;

int n, m;
int a[MAXN];
int table[MAXLOG][MAXN];
int numlog[MAXN];

void buildTable() {
    numlog[1] = 0;
    for (int i = 2; i <= n; i++)
        numlog[i] = numlog[i / 2] + 1;

    for (int i = 0; i <= numlog[n]; i++) {
        int curlen = 1 << i;
        for (int j = 1; j <= n; j++) {
            if (i == 0) {
                table[i][j] = a[j];
                continue;
            }
            table[i][j] = min(table[i - 1][j], table[i - 1][j + curlen / 2]);
        }
    }
}

int getMin(int l, int r) {
    int curlog = numlog[r - l + 1];
    return min(table[curlog][l], table[curlog][r - (1 << curlog) + 1]); 
}

int main() {
    //assert(freopen("input.txt","r",stdin));
    //assert(freopen("output.txt","w",stdout));

    int a1;
    scanf("%d%d%d", &n, &m, &a1);

    
    a[1] = a1;
    for (int i = 2; i <= n; i++)
        a[i] =(23*a[i-1]+21563)%16714589;

    buildTable();
    
    int l, r, ans;
    scanf("%d %d", &l, &r);

    for (int i = 1; i <= m; i++) {
        ans = getMin(min(l,r), max(l,r));
        if(i == m) break;
        l = ((17*l+751+ans+2*i)%n)+1;
        r = ((13*r+593+ans+5*i)%n)+1;
    }
    
    cout << l << " " << r << " " << ans << endl;

    return 0;
}
