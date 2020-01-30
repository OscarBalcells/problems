#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {    

    int e;
    scanf("%d",&e);
    
    vector<vi> adjList(e);
    
    for(int i = 0; i < e; ++i) {
        int hm; scanf("%d",&hm);
        adjList[i].resize(hm);
        while(hm--) scanf("%d",&adjList[i][hm]);
    }
    
    int TC;
    scanf("%d",&TC);
    
    while(TC--) {
        int s;
        scanf("%d",&s);
        
        vi visited(e, -2);
        map<int, int> booms;
        visited[s] = -1;
        
        if((int)adjList[s].size() == 0) { printf("0\n"); continue; };
        
        queue<int> q; q.push(s);
        while(!q.empty()) {
            
            int u = q.front(); q.pop();
            
            for(int i = 0; i < (int)adjList[u].size(); ++i) {
                int v = adjList[u][i];
                if(visited[v] != -2) continue;
                    
                visited[v] = visited[u]+1;
                booms[visited[v]]++;
                q.push(v);
            }
        }
        
        int biggest = 1;
        int when = 0;
        for(map<int,int>::iterator it = booms.begin(); it != booms.end(); ++it) {
            if(it->second > biggest) {
                biggest = it->second;
                when = it->first;
            }
        }
        
        printf("%d %d\n", biggest, when+1);
        booms.clear();
        while(!q.empty()) q.pop();
    }
}
