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

vi t;
vector<vi> AdjList;
vi dp;
int n;

int dfs(int u) {

    if(dp[u] != -1) return dp[u];

    int ans = 0;
    for(int i = 0; i < (int)AdjList[u].size(); ++i) {
        ans = max(ans, dfs(AdjList[u][i]));
    }

    ans += t[u];
    dp[u] = ans;
    
    return ans;
}

int main() {

    int TC;
    cin >> TC;
    
    bool first = true;
    
    string line;
    getline(cin, line);
    getline(cin, line);
    
    while(TC--) {
        
        if(!first) cout << endl;
        first = false;
        
        n = 0;
        
        vector<pair<char,string>> i;
        map<char, int> m;
        
        t.clear();
        AdjList.clear();
        dp.clear();
        
        while(getline(cin, line)) {
            
            if(line.size() == 0 || line[0] < 'A' || line[0] > 'Z') break;
            vector<string> tmp = split(line);
            
            t.push_back(stoi(tmp[1]));
            string s; (tmp.size() == 3 ? s = tmp[2] : s = "");
            i.push_back(make_pair(tmp[0][0], s));
            m.insert(make_pair(tmp[0][0], n));
            n++;
        }
        
        for(int u = 0; u < (int)i.size(); ++u) {
            
           string s = i[u].second;
           vi tmp;
           
           for(int j = 0; j < (int)s.size(); ++j) {
                tmp.push_back(m[s[j]]);
           }
           
           AdjList.push_back(tmp);
            
        }
        
        vi tmp;
        for(int u = 0; u < n; ++u) tmp.push_back(u);
        AdjList.push_back(tmp);
        t.push_back(0);
        dp.assign(n+1, -1);
        
        //debug() << AdjList;
        
        dfs(n);
        cout << dp[n] << endl;
        
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
