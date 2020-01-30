
#include <bits/stdc++.h>
using namespace std;
 
 
#define X first
#define Y second
 
 
using ll = long long;
using P = pair<int, int>;
using PP = pair<P, P>;
using VI = vector<int>;
 
 
const ll INF = 2e18 + 1;
 
 
int n;
ll g, s;
set<PP> S;
VI parent;
 
 
bool comp(PP a, PP b) {
  return a.X.Y < b.X.Y;
}
 
 
int repre(int x) {
  if (parent[x] == -1) return x;
  return parent[x] = repre(parent[x]);
}
 
 
int mst() {
  parent = VI(n, -1);
  int q = n;
  auto it = S.begin();
  
  while (it != S.end()) {
    int rx = repre(it->Y.X);
    int ry = repre(it->Y.Y);
    if (rx == ry) {
        S.erase(it++);
    } else {
      parent[ry] = rx;
      if (--q == 1) {
        int res = it->X.X;
        return res;
      }
      ++it;
    }
  }
  return -1;
}
 
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  int m;
  cin >> n >> m >> g >> s;
  vector<PP> V(m);
  for (PP& e : V) {
    cin >> e.Y.X >> e.Y.Y >> e.X.X >> e.X.Y;
    --e.Y.X; --e.Y.Y;
  }
  sort(V.begin(), V.end(), comp);
 
  ll ans = INF;
  int i = 0;
  while (i < m) {
    int j = i;
    while (j < m and V[j].X.Y == V[i].X.Y) S.insert(V[j++]);
    int gold = mst();
    if (gold != -1) ans = min(ans, gold*g + V[i].X.Y*s);
    i = j;
  }
  cout << (ans == INF ? -1 : ans) << endl;
}
