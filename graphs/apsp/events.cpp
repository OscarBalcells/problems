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

vector<bool> up, down;

vector<ii> answers;
vector<vi> AdjList;
vector<vi> invAdjList;

void dfsu(int u) {
    
    up[u] = true;
    
    for(int i = 0; i < (int)invAdjList[u].size(); ++i) {
        if(!up[invAdjList[u][i]]) dfsu(invAdjList[u][i]);
    }
    
}

void dfsd(int u) {

    down[u] = true;
    
    for(int i = 0; i < (int)AdjList[u].size(); ++i) {
        if(!down[AdjList[u][i]]) dfsd(AdjList[u][i]);
    }

}

int main() {
    
    int nc;
    int tc = 1;
    
    while(true) {
        
        cin >> nc;
        
        if(nc == 0) return 0;
        
        int cur = 0;
        
        map<int, string> tos;
        map<string, int> toi;
        
        AdjList.clear();
        invAdjList.clear();
        
        for(int i = 0; i < nc; ++i) {
            int ne; cin >> ne;
            
            for(int j = 0; j < ne; ++j) {
                string e; cin >> e;
                
                vi tmp1, tmp2;
                if(j < ne-1) tmp1.push_back(cur+1);
                if(j > 0) tmp2.push_back(cur-1);
                
                AdjList.push_back(tmp1);
                invAdjList.push_back(tmp2);
                
                tos[cur] = e;
                toi[e] = cur;
                cur++;
            }
        }
        
        int messages;
        cin >> messages;
        
        for(int i = 0; i < messages; ++i) {
            string e1, e2;
            cin >> e1 >> e2;
            AdjList[toi[e1]].push_back(toi[e2]);
            invAdjList[toi[e2]].push_back(toi[e1]);
        }
        
        up.clear(); up.assign(cur, false);
        down.clear(); down.assign(cur, false);
        
        int printed = 0;
        int ans = 0;
        
        for(int i = 0; i < cur; ++i) {
            
            dfsu(i);
            dfsd(i);
            
            for(int j = 0; j < cur; ++j) {
                if(!up[j] && !down[j] && i < j) {
                    ans++;
                    if(printed < 2) {
                        answers.push_back(ii(i,j));
                        printed++;
                    }
                } else {
                    up[j] = false;
                    down[j] = false;
                }
            }
        }
        
        if(ans == 0) {
            printf("Case %d, no concurrent events.\n", tc);
        } else {
            printf("Case %d, %d concurrent events:\n", tc, ans);
            cout << "(" << tos[answers[0].first] << "," << tos[answers[0].second] << ") ";
            if(ans > 1) {
                cout << "(" << tos[answers[1].first] << "," << tos[answers[1].second] << ") ";
            }
            cout << endl;
            answers.clear();
        }
        
        tc++;
    }

}

