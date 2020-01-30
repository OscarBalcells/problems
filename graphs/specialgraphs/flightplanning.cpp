#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vii = vector<ii>;

const int oo = 1e8+7;

vi visited;
vector<vi> AdjList;
int b1, b2, n;

vector<int> get_diameter(int start_node) {
    
    queue<int> q;
    visited.assign(AdjList.size(), false);
    q.push(start_node);
    visited[start_node] = true;

    int far = start_node;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        far = u;

        for (const auto &item : AdjList[u]) {
            if (max(u, item) == max(b1, b2) && min(u, item) == min(b1, b2)) {
                continue;
            }

            int v = item;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    vector<int> parent(AdjList.size());
    
    q.push(far);
    visited.assign(AdjList.size(), false);
    visited[far] = true;
    parent[far] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        far = u;

        for (const auto &item : AdjList[u]) {
            if (min(b1, b2) == min(item, u) && max(b1, b2) == max(item, u)) {
                continue;
            }

            int v = item;
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    vector<int> path;
    while (far != -1) {
        path.push_back(far);
        far = parent[far];
    }
    return path;
}


int main() {
    
    int TC, www;
    www = scanf("%d",&TC);
    www++; //no unused vars
    
    while(TC--) {
     
        www = scanf("%d",&n);
        
        AdjList.clear(); AdjList.resize(n);
        visited.clear();
        
        for(int i = 0; i < n-1; ++i) {
            int c1, c2;
            www = scanf("%d%d",&c1,&c2);
            c1--; c2--;
            AdjList[c1].push_back(c2);
            AdjList[c2].push_back(c1);
        }
        
        ii prevf, newf;
        int newd = n;
        b1 = -1; b2 = -1;
        
        vi diameter = get_diameter(0);
        
        for(int i = 0; i < (int)diameter.size()-1; ++i) {
            
            b1 = diameter[i]; b2 = diameter[i+1];
            
            vi d1 = get_diameter(b1);
            vi d2 = get_diameter(b2);
            
            int r1 = d1[d1.size()/2];
            int r2 = d2[d2.size()/2];
            
            int d = max(ceil((d1.size()-1.0)/2.0) + ceil((d2.size()-1.0)/2.0) + 1.0, max(d1.size()-1.0, d2.size()-1.0));
            
            if(d < newd && d != -1) {
                prevf = {b1, b2};
                newf = {r1,r2};
                newd = d;
            }
        }

        cout << newd << endl;
        cout << prevf.first+1 << " " << prevf.second+1 << endl;
        cout << newf.first+1 << " " << newf.second+1 << endl;
        
    }
    
    return 0;
}

