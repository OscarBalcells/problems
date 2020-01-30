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


typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int mod = 1e9+7;
const int oo = 1e9+7;

vector<string> split(const string &);

int main() {
    
    int n, k;
    while(scanf("%d%d",&n,&k) != EOF) {
      
        vi sp(n);
        vector<vi> el(n);
        for(int i = 0; i < n; ++i) scanf("%d",&sp[i]);

        string line;
        getline(cin,line);
        for(int i = 0; i < n; ++i) {
            getline(cin, line);
            vector<string> tmp = split(line);
            
            for(int j = 0; j < (int)tmp.size(); ++j) {
                el[i].push_back(stoi(tmp[j]));
            }
        }
        
        vi dist(100, oo); dist[0] = 0;
        priority_queue< ii, vector<ii>, greater<ii> > pq; 
        pq.push(ii(0, 0));
        bool start = true;
        
        while(!pq.empty()) {
            
            ii front = pq.top(); pq.pop();
            int d = front.first, u = front.second;
            
            if(d > dist[u]) continue;
            
            //estamos en el floor u, al cual hemos llegado en d
            for(int i = 0; i < n; ++i) {
                if(lower_bound(el[i].begin(), el[i].end(), u) != el[i].end() && *(lower_bound(el[i].begin(), el[i].end(), u)) == u) {
                    //el ascensor i para en la planta u
                    for(int j = 0; j < (int)el[i].size(); ++j) {
                        int v = el[i][j], w = (start ? abs(u-v)*sp[i] : abs(u-v)*sp[i]+60);
                        if(d + w < dist[v]) {
                            //cout << "Time it will take to move from " << u << " to " << v << " is " << w << endl;
                            dist[v] = d + w;
                            pq.push(ii(dist[v], v));
                        }
                    }
                }
            }
            start = false;
        }
        
        if(dist[k] != oo ? printf("%d\n",dist[k]) : printf("IMPOSSIBLE\n"));
        
    }
    
    return 0;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
