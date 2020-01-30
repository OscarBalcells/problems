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

int main() {
    
    int TC;
    scanf("%d",&TC);
    string tmp;
    
    for(int tc = 1; tc <= TC; ++tc) {
        int n;
        scanf("%d",&n);
        getline(cin, tmp);
        vector<string> w;
        
        for(int i = 0; i < n; ++i) {
            getline(cin, tmp);
            w.push_back(tmp);
        }
        
        map<string,int> rhymes;
        vector<vector<string>> AdjList(n, vector<string>(n,""));
        
        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                if(w[i][(int)w[i].size()-1] == w[j][(int)w[j].size()-1]) {
                    string s = "";
                    for(int r1 = (int)w[i].size()-1, r2 = (int)w[j].size()-1; r1 >= 0 && r2 >= 0; --r1, --r2) {
                        if(w[i][r1] == w[j][r2]) {
                            s += w[i][r1];
                            string ss = s;
                            reverse(ss.begin(), ss.end());
                            rhymes[ss] = 0;
                        }
                    }
                    reverse(s.begin(), s.end());
                    rhymes[s] = 0;
                    debug() << imie(i) imie(j) imie(AdjList);
                    AdjList[i][j] = s;
                    AdjList[j][i] = s;
                } else {
                    AdjList[i][j] = "";
                    AdjList[j][i] = "";
                }
            }
        }
        
        if(n > 6) {
            cout << -1 << endl;
            continue;
        }
        
        int p[] = {0, 1, 2, 3, 4, 5};
        int best = 0;
        
        debug() << imie(AdjList);
        
        do {
            int ans = 0;
            
            for(int i = 0; i < n-1; i+=2) {
                
                int a = p[i], b = p[i+1];
                if(a >= n || b >= n) continue;
                
                if(AdjList[a][b].size() > 0) {
                    string s = AdjList[a][b];
                    string ss = "";
                    
                    bool pos = false;
                    //can we use at least one part of this rhyme?
                    for(int k = (int)s.size(); k >= 1; --k) {
                        ss = "";
                        //debug() << imie(a) imie(b) imie(s.size()) imie(k) imie(s);
                        for(int j = 0; j < k; ++j) {
                            ss += s[j];
                        }
                        if(rhymes[ss] == 0) {
                            pos = true;
                            break;
                        }

                    }
                    
                    if(!pos) continue;
                    
                    ans += 2;
                    rhymes[ss]++;
                }
            }
            
            best = max(best, ans);
            
            for(map<string,int>::iterator it = rhymes.begin(); it != rhymes.end(); ++it) {
                it->second = 0;
            }
            
        } while(next_permutation(p, p+6));

        cout << "Case #" << tc << ": " << best << endl;
    }
    
    return 0;
}


