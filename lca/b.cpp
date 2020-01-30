#include <bits/stdc++.h>
using namespace std;
const int nax = 1e5+7;

map<int,int> nodeToId, idToNode, nodeToDepth;
vector<int> edges[nax];
vector<int> depths[nax];
int c = 0;

void debug(vector<int> a) {
    for(int el : a) {
        cerr << el << " ";
    }
    cerr << endl;
}

void process(int a, int p, int d) {
    
    c++;
    nodeToId[a] = c;
    idToNode[c] = a;
    nodeToDepth[a] = d;
    depths[d].push_back(c);
    
    for(int b : edges[a]) if(b != p) {
        process(b, a, d+1);
    }
}

int la(int a, int d) {
    //int thisId = nodeToId[a];
    //vector<int> hisDepth = depths[d];
    //cout << "This id: " << thisId << ", Depths: "; debug(hisDepth);
    int ans = *prev(lower_bound(depths[d].begin(), depths[d].end(), nodeToId[a]));
    return idToNode[ans];
}

int main() {
    
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n-1; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    
    process(1, 0, 0);
    
    int m;
    scanf("%d",&m);
    
    for(int i = 0; i < m; ++i) {
        int a, d;
        scanf("%d %d", &a, &d);
        if(a == 1) { cout << 1 << endl; continue; }
        int nodeDepth = nodeToDepth[a];
        cout << la(a, max(0,nodeDepth-d)) << endl;
    }
    
    return 0;
}    
