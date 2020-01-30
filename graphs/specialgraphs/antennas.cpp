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

const int mod = 1e9+7;
const int oo = 1e9+7;

vi match, vis;
vector<vi> AdjList;
vector<vector<bool>> grid;
int nonmatched;

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

int Aug(int l) {
		
		if(vis[l]) return 0;
		vis[l] = 1;
		
		for(int j = 0; j < (int)AdjList[l].size(); ++j) {
				int r = AdjList[l][j];
				if(match[r] == -1 || Aug(match[r])) {
                    debug() << imie(l) imie(r);
                    match[r] = l; return 1;
				}
		}
		
		return 0;
}

int main() {
    
    int TC;
    scanf("%d",&TC);
    
    while(TC--) {
        
        int R, C;
        scanf("%d%d",&R,&C);
        string line; getline(cin, line);
        
        grid.clear(); grid.resize(R);
        
        for(int r = 0; r < R; ++r) {
            grid[r].resize(C);
            getline(cin, line);
            
            for(int c = 0; c < C; ++c) {
                if(line[c] == 'o') grid[r][c] = false;
                else grid[r][c] = true;
            }
        }
        
        AdjList.clear();
        int MCBM = 0;
        nonmatched = 0;
        
        for(int r = 0; r < R; ++r) {
            for(int c = 0; c < C; ++c) {
                if(!grid[r][c]) continue;
                int hm = 0;
                for(int i = 0; i < 4; ++i) {
                    int x = r+dr[i], y = c+dc[i];
                    if(x >= 0 && y >= 0 && x < R && y < C && grid[x][y] == true) {
                        hm++;
                    }
                }
                if(hm == 0) MCBM++;
                else nonmatched++;
            }
        }
        
        int l = 0;
        
        for(int r = 0; r < R; ++r) {
            for(int c = 0; c < C; ++c) {
                if(!grid[r][c]) continue;
                else if(r%2 != c%2) continue;
                
                vi tmp;
                assert(tmp.empty());
                for(int i = 0; i < 4; ++i) {
                    int x = r+dr[i], y = c+dc[i];
                    if(x >= 0 && y >= 0 && x < R && y < C && grid[x][y] == true) {
                        tmp.push_back(x*C + y);
                    }
                }
                if(tmp.size() == 0) continue;
                else { AdjList.push_back(tmp); l++; }
            }
        }
        
        debug() << AdjList;
        
        match.assign(R*C*2, -1);
        
        for(int i = 0; i < l; ++i) {
            vis.assign(l, false);
            MCBM += Aug(i);
        }
        
        for(int r = 0; r < R; ++r) {
            for(int c = 0; c < C; ++c) {
                if(match[r*C + c] != -1) {
                    nonmatched -= 2;
                }
            }
        }
        
        MCBM += nonmatched; //nonmatched have to be covered too
        
        cout << MCBM << endl;
        
    }
    
    
    return 0;
}

