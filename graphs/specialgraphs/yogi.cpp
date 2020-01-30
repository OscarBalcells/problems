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
using dii = pair<int,ii>;
using lll = pair<ll,ll>;

const int mod = 20437;
const int oo = 1e7+7;

int n;
vector<vector<char>> grid;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

bool valid(int r, int c) {
    if(r < 0 || r >= n || c < 0 || c >= n) return false;
    if(grid[r][c] == '#') return false;
    return true;
}

ii path(ii a, ii b) {
    
    /** Encontrar el camino mas rapido desde a hasta b
     * y cuantos caminos de esta longitud hay 
     **/
     
     vector<vi> d(n);
     vector<vi> h(n);
     
     for(int i = 0; i < n; ++i) {
        d[i].assign(n, oo);
        h[i].assign(n, 0);
     }
     
     queue<dii> q;
     q.push(dii(0, a));
     d[a.first][a.second] = 0; h[a.first][a.second] = 1;
     
     while(!q.empty()) {
         
         dii f = q.front(); q.pop();
         int p = f.first, r = f.second.first, c = f.second.second;
         
         //cout << "At r = " << r << " and c = " << c << " with " << p << endl;
         
         if(d[r][c] < p) continue;
         
         for(int i = 0; i < 4; ++i) if(valid(r+dr[i], c+dc[i])) {
             int rx = r+dr[i], cx = c+dc[i];
             if(d[rx][cx] < p+1 || (grid[rx][cx] != '.' && !(rx == b.first && cx == b.second))) continue;
             
             if(d[rx][cx] == p+1) { h[rx][cx]++; }
             else if(d[rx][cx] > p+1) { d[rx][cx] = p+1; h[rx][cx] = 1; }
             q.push(dii(p+1, ii(rx, cx)));
         }
         
    }
    
    grid[a.first][a.second] = '.';
    //h[b.first][b.second] %= mod;
    return ii(d[b.first][b.second], h[b.first][b.second]);
    
}

int main() {
    
    int tc = 1;
    
    while(scanf("%d",&n)) {
    
        if(n == 0) break;
        string line;
        getline(cin, line);
        
        grid.resize(n);
        
        map<char,ii> position;
        
        for(int i = 0; i < n; ++i) {
            grid[i].resize(n);
            getline(cin, line);
            for(int j = 0; j < n; ++j) {
                grid[i][j] = line[j];
                if(grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
                    position[line[j]-'A'] = ii(i,j);
                }
            }
        }
        
        int nPaths = 1;
        int pathLength = 0;
        bool impos = false;
        
        for(int l = 0; l < (int)position.size()-1; ++l) {
            ii a = position[l], b = position[l+1];
            ii ans = path(a, b);
            if(ans.second == 0) { impos = true; break; }
            nPaths *= ans.second;
            nPaths %= mod;
            pathLength += ans.first;
        }
        
        if(impos) cout << "Case " << tc << ": Impossible";
        else cout << "Case " << tc << ": " << pathLength << " " << nPaths;
        /*cout << " N is " << n << " and first row is";
        for(auto x : grid[0]) {
            cout << " " << x;
        }*/
        cout << endl;
        tc++;
        
        //2
        //BA
        //#C

    }
    
    return 0;
}


