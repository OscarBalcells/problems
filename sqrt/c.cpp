#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
const int oo = 1e9+7;
const int nax = 1e5+7;

vector<int> edges[nax];
set<pair<int,int>> addedEdges;

int main() {
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<pair<int,ii>> queries;
    
    int ind = 0;
    while(ind < m) {
        //get block
        int indNow = ind;
        for(; ind < indNow+k && ind < m; ++ind) {
            
        }
        
        rebuild();
    }
    
    return 0;
}
