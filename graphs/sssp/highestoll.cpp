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

vector<string> split(const string &);


int main() {
    
    int TC;
    scanf("%d",&TC);
    
    while(TC--) {
        
        int n, e, s, t, p;
        scanf("%d%d%d%d%d",&n,&e,&s,&t,&p);
        s--; t--;
        
        vector<vii> AdjList(n), invAdjList(n);
        vector<pair<int,ii>> edges(e);
        
        for(int i = 0; i < e; ++i) {
            int c1, c2, w;
            scanf("%d%d%d",&c1,&c2,&w);
            c1--; c2--;
            AdjList[c1].push_back(ii(c2,w));
            invAdjList[c2].push_back(ii(c1,w));
            edges[i] = make_pair(w, ii(c1,c2));
        }
        
        debug() << imie(edges);
        
        //we have to build to dist arrays
        //one from source s away
        //and the other one from goal t away
        
        vi dist(n, oo), invDist(n, oo);
        dist[s] = 0; invDist[t] = 0;
        
        debug() << imie(dist);
        
        priority_queue< ii, vector<ii>, greater<ii> > pq;
        
        //to build dist
        pq.push(ii(0, s));
        
        while(!pq.empty()) {
        
            ii front = pq.top(); pq.pop();
            int d = front.first, u = front.second;
            
            if(d > dist[u]) continue;
            
            for(int i = 0; i < (int)AdjList[u].size(); ++i) {
                int v = AdjList[u][i].first, w = AdjList[u][i].second;
                
                if(d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push(ii(dist[v], v));
                }
            }
        }
        
        debug() << imie(dist);
        
        //to build invDist
        pq.push(ii(0, t));
        
        while(!pq.empty()) {
        
            ii front = pq.top(); pq.pop();
            int d = front.first, u = front.second;
            
            if(d > invDist[u]) continue;
            
            for(int i = 0; i < (int)invAdjList[u].size(); ++i) {
                int v = invAdjList[u][i].first, w = invAdjList[u][i].second;
                
                if(d + w < invDist[v]) {
                    invDist[v] = d + w;
                    pq.push(ii(invDist[v], v));
                }
            }
        }
        
        int best = -1;
        
        for(int i = 0; i < e; ++i) {
            int w = edges[i].first, c1 = edges[i].second.first, c2 = edges[i].second.second;
            if(dist[c1] + w + invDist[c2] <= p) {
                best = max(best, w);
            }
        }
        
        printf("%d\n", best);
        
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

