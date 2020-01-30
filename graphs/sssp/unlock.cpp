#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10e8 + 5;
typedef long long int ll;

int main() {

    int L, U, N, TC = 1;
    while(scanf("%d%d%d",&L,&U,&N)) {
        
        if(L == 0 && U == 0 && N == 0) return 0;
        
        vector<int> buttons(N);
        for(int i = 0; i < N; ++i) scanf("%d",&buttons[i]);
        
        queue<int> q;
        q.push(L);
        vector<ll> visited(10000, -1);
        visited[L] = 0;
        
        while(!q.empty()) {
            
            int n = q.front(); q.pop();
            
            for(int i = 0; i < N; ++i) if(visited[(n+buttons[i])%10000] == -1) {
                q.push((n+buttons[i])%10000);
                visited[(n+buttons[i])%10000] = visited[n]+1;
            }
        }
        
        if(visited[U] == -1) printf("Case %d: Permanently Locked\n", TC);
        else printf("Case %d: %lld\n", TC, visited[U]);
        
        TC++;
    }

    return 0;
}
