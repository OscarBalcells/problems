#include <bits/stdc++.h>
using namespace std;

mt19937 rng;
 
typedef struct Node * Treap;
 
struct Node {
  int prio, cnt, pos, lazy;
  Treap l, r;
};
 
Treap one(int x, int pos) {
  return new Node { x, int(rng()), 1, 0, 0, pos, 0 } ;
}
 
int size(Treap t) {
    return (t ? t->cnt : 0);
}
 
void update(Treap t) {
    t->cnt = 1 + size(t->l) + size(t->r);
}
 
Treap merge(Treap l, Treap r) {
  if (l == 0) return r;
  if (r == 0) return l;
  if (l->prio < r->prio) {
    l->r = merge(l->r, r);
    update(l);
    return l;
  }
  r->l = merge(l, r->l);
  update(r);
  return r;
}

void split(Treap t, int x, Treap &l, Treap &r) {
    l = r = 0;
    if (t == 0) return;
    if (t->x < x) {
        split(t->r, x, t->r, r);
        l = t;
    } else {
        split(t->l, x, l, t->l);
        r = t;
    }
    update(t);
}

Treap insert(Treap t, int x) {
  Treap l, r;
  split(t, x, l, r);
  return merge(merge(l, one(x)), r);
}
 
Treap erase(Treap t, int x) {
  Treap l, m, r;
  split(t, x, l, m);
  split(m, x + 1, m, r);
  delete m;
  return merge(l, r);
}

void insertAtPosition(Treap t, int x, int p, int position) {
    int thisPos = p + size(t->left);
    if(thisPos == position) {
        t = insert(t, x);
    } else if(thisPos < position) {
        t = insert(t->left, );
    }
}

int main() {
    
}
