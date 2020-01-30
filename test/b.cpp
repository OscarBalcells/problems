#include <bits/stdc++.h>
using namespace std;

vector<int> edges[26];
int indegree[26];
bool visited[26];
vector<int> ans;

void visit(int a) {
    
    if(visited[a]) {
        cout << "Impossible" << endl;
        exit(0);
    }

    ans.push_back(a);
    visited[a] = true;
    
    for(int b : edges[a]) {
        indegree[b]--;
        if(indegree[b] == 0) {
            visit(b);
            indegree[b] = -1;
        }
    }
    
    visited[a] = false;
}

void connect(string a, string b) {
    for(int i = 0; i < (int)min(a.size(),b.size()); ++i) {
        if(a[i] != b[i]) {
            edges[a[i]-'a'].push_back(b[i]-'a');
            indegree[b[i]-'a']++;
            return;
        }
    }
    if(a.size() > b.size()) {
        cout << "Impossible" << endl;
        exit(0);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    
    string pname;
    getline(cin,pname);
    getline(cin,pname);
    
    for(int i = 0; i < 26; ++i) {
        visited[i] = false;
        indegree[i] = 0;
    }
    
    for(int i = 0; i < n-1; ++i) {
        string name;
        getline(cin,name);
        connect(pname,name);
        pname=name;
    }
    
    for(int i = 0; i < 26; ++i) {
        if(indegree[i] == 0) {
            visit(i);
        }
    }
    
    if(ans.size() < 26) {
        cout << "Impossible" << endl;
        exit(0);
    }
    
    for(int i = 0; i < (int)ans.size(); ++i) {
        cout << char(ans[i]+'a');
    }
    cout << endl;
}
