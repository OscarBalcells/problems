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
const int oo = 1e8+7;

vector<string> split(const string &);


int main() {
    
    int a, b;
    int tc = 1;
    
    while(true) {
        scanf("%d%d",&a,&b);
        if(a == 0 && b == 0) return 0;
        a--; b--;
        
        bool pages[100];
        int AdjMatrix[100][100];
        
        memset(AdjMatrix, oo, sizeof AdjMatrix);
        memset(pages, false, sizeof pages);
        
        pages[a] = true;
        pages[b] = true;
        AdjMatrix[a][b] = 1;
        //true? adjMatrix[b][a] = 1;
        
        while(scanf("%d%d",&a,&b)) {
            if(a == 0 && b == 0) break;
            a--; b--;
            AdjMatrix[a][b] = 1;
            pages[a] = true;
            pages[b] = true;
        }
        
        for(int k = 0; k < 100; k++) {
            for(int i = 0; i < 100; ++i) {
                for(int j = 0; j < 100; ++j) {
                    AdjMatrix[i][j] = min(AdjMatrix[i][j], AdjMatrix[i][k] + AdjMatrix[k][j]);
                }
            }
        }
        
        double total = 0;
        int nPaths = 0;
        
        for(int i = 0; i < 100; ++i) if(pages[i] == true) {
            for(int j = 0; j < 100; ++j) if(pages[j] == true && j != i) {
                nPaths++;
                total += (double)AdjMatrix[i][j];
            }
        }
        
        double average = total / nPaths;
        printf("Case %d: average length between pages = %.3lf clicks\n", tc, average);
    
        tc++;
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

