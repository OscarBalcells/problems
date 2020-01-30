#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
const int nax = 1e5+7;
int n, k;
vector<int> holes(nax);
vector<ii> jumps(nax); //.first = where you'll end up after .second jumps
vector<int> blockStarts;

ii query(int start) {
    int now = start;
    int totalJumps = 0;
    
    while(now < n) {
        if(jumps[now].first >= n) {
            //manual
            while(now+holes[now] < n) {
                now += holes[now];
                totalJumps++;
            }
            return make_pair(now, totalJumps+1);
        } else {
            totalJumps += jumps[now].second;
            now = jumps[now].first;
        }
    }
    assert(false);
}

void update(int pos, int val) {
    holes[pos] = val;    
    int start = *prev(upper_bound(blockStarts.begin(),blockStarts.end(),pos));
    int end = min(n-1, start+k);
    
    for(int ind = pos; ind >= start; --ind) {
        if(ind+holes[ind] > end) {
            jumps[ind] = make_pair(ind+holes[ind], 1);
        } else {
            jumps[ind].second = jumps[ind+holes[ind]].second+1;
            jumps[ind].first = jumps[ind+holes[ind]].first;
        }
    }
}

void build() {  
    int ind = 0;
    
    while(ind < n) {
        int start = ind;
        int end = min(n-1, start+k);

        for(int i = ind; i <= end; ++i) {
            int jumpEnd = i;
            int totalJumps = 0;

            while(jumpEnd <= end) {
                jumpEnd += holes[jumpEnd];
                totalJumps++;
            }
            jumps[i] = make_pair(jumpEnd,totalJumps);
        }
        blockStarts.push_back(ind);
        ind = end+1;
    }
}

int main() {
    
    int m;
    scanf("%d %d", &n, &m);
    
    k = (int)sqrt(n)*2;
    
    for(int i = 0; i < n; ++i) {
        scanf("%d", &holes[i]);
    }
    
    build();
    
    for(int i = 0; i < m; ++i) {
        int t;
        scanf("%d", &t);
        
        if(t == 0) {
            int a, b;
            scanf("%d %d", &a, &b);
            update(a-1, b);
            continue;
        }
        
        int a;
        scanf("%d", &a);
        ii ans = query(a-1);
        printf("%d %d\n", ans.first+1, ans.second);
    }
    
    return 0;
}
