#include <bits/stdc++.h>
using namespace std;

mt19937 rng;
 
typedef struct Node * Treap;
 
struct Node {
  int x, prio, cnt;
  vector<int> nums(5);
  Treap l, r;
};
 
Treap one(int x) {
  return new Node { x, int(rng()), 1, 0, 0 } ;
}
 
int size(Treap t) {
  return (t ? t->cnt : 0);
}
 
void update(Treap t) {
  t->cnt = 1 + size(t->l) + size(t->r);
}

int main() {
    
    return 0;
}
