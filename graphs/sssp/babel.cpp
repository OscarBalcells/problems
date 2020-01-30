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
const int oo = 1e9+999;

vector<string> split(const string &);


int main() {
    
    int M;
    
    while(true) {
        
        scanf("%d",&M);
        string line;
        getline(cin, line);
        
        if(M == 0) return 0;
        
        getline(cin, line);
        vector<string> tmp1 = split(line);
        string a = tmp1[0], b = tmp1[1];

        vector<pair<string,pair<string,string>>> inp;
        
        map<string,int> langs;
        langs[a] = 0; langs[b] = 1;
        int smallest = 2;
        
        for(int i = 0; i < M; ++i) {
            getline(cin, line);
            vector<string> tmp = split(line);
            string l1 = tmp[0], l2 = tmp[1], w = tmp[2];
            
            if(langs.count(l1) == 0) {
                langs[l1] = smallest;
                smallest++;
            }
            
            if(langs.count(l2) == 0) {
                langs[l2] = smallest;
                smallest++;
            }
            
            inp.push_back(make_pair(w, make_pair(l1,l2)));
        }
        
        vector<vector<pair<int,string>>> AdjList((int)langs.size());
        
        for(int i = 0; i < M; ++i) {
            
            int l1 = langs[inp[i].second.second], l2 = langs[inp[i].second.first];
            string w = inp[i].first;
            AdjList[l1].push_back(make_pair(l2, w));
            AdjList[l2].push_back(make_pair(l1, w));
        
        }
        
        vector<vector<int>> dist(smallest, vector<int>(27, oo));
        dist[0][26] = 0; 
        priority_queue< pair<int,ii>, vector<pair<int,ii>>, greater<pair<int,ii>> > pq; 
        pq.push(make_pair(0, make_pair(0, 26))); // (nsteps, (lastInitial, language))
        
        while(!pq.empty()) {
            
            pair<int,ii> front = pq.top(); pq.pop();
            int d = front.first, u = front.second.first, c = front.second.second;
            
            if(d > dist[u][c]) continue;

            //debug() << dist[u][c];
            
            for(int i = 0; i < (int)AdjList[u].size(); ++i) if(AdjList[u][i].second[0]-'a' != c) {
                pair<int,string> v = AdjList[u][i]; // (vertex, word)
                
                if(dist[u][c] + (int)v.second.size() < dist[v.first][v.second[0]-'a']) {
                    dist[v.first][v.second[0]-'a'] = dist[u][c] + (int)v.second.size();
                    pq.push(make_pair(dist[v.first][v.second[0]-'a'], make_pair(v.first, v.second[0]-'a')));
                }
            }
        }
        
        int best = oo;
        for(int i = 0; i < 27; ++i) {
            if(dist[1][i] != oo) best = min(best, dist[1][i]);
        }
        
        if(best == oo ? printf("impossivel\n") : printf("%d\n", best));
    
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

