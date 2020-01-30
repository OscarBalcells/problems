#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

bool oneChar(string a, string b) {
    if(a.size() != b.size()) return false;
    bool yes = false;
    for(int i = 0; i < (int)a.size(); ++i) {
        if(a[i] != b[i]) {
            if(yes) return false;
            yes = true;
        }
    }
    if(yes) return true;
    return false;
}

int main() {
    
    int TC;
    string tmp;
    scanf("%d", &TC);
    getline(cin , tmp);
    getline(cin , tmp);
    bool first = true;
    
    while(TC--) {
     
        if(!first) cout << endl;
        first = false;
        vector<vi> adjList;
        vi dist;
        
        vector<string> words;
        map<string, int> m;
        
        string word;
        int i = 0;
        for(;; ++i) {
            getline(cin , word);
            if(word[0] == '*') break;
            m.insert(pair<string,int>(word,i));
            words.push_back(word);
        }
        
        int hm = i;
        adjList.resize(hm);
        
        for(i = 0; i < hm; ++i) {
            for(int j = 0; j < hm; ++j) {
                if(oneChar(words[i], words[j])) {
                    adjList[i].push_back(j);
                }
            }
        }
        
        while(true) {
            string a, b, line;
            getline(cin, line);
            if(line.size() < 2) break;
            
            i = 0;
            for(; i < (int)line.size(); ++i)  {
                if(line[i] == ' ') break;
                a += line[i];
            }
            i++;
            for(; i < (int)line.size(); ++i)  {
                if(line[i] >= 'a' && line[i] <= 'z') b += line[i];
                else break;
            }
            
            //cout << endl << "Words read are " << a << " and " << b << endl;
            
            vi dist(hm, -1);
            queue<int> q;
            q.push(m[a]);
            dist[m[a]] = 0;
            bool done = false;
            
            while(!q.empty() && !done)  {
                int u = q.front(); q.pop();
                
                for(int j = 0; j < (int)adjList[u].size(); ++j) {
                    int v = adjList[u][j];
                    if(dist[v] == -1) {
                        dist[v] = dist[u]+1;
                        
                        if(m[b] == v) {
                            done = true;
                        } else {
                            q.push(v);
                        }
            } } } 
        
            cout << a << " " << b << " " << dist[m[b]] << endl;
            while(!q.empty()) q.pop();
        }
    }
}
