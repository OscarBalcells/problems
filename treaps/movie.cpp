#include <bits/stdc++.h>
using namespace std;

mt19937 rng;
 
typedef struct Node * Treap;
 
struct Node {
  int x, prio, cnt;
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
  }
  else {
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

int computePosition(Treap t, int x, int p) {
    int thisPos = p + size(t->l);
    if(t->x == x) return thisPos;
    
    if(t->x < x) {
        return computePosition(t->r, x, thisPos+1);
    } else {
        return computePosition(t->l, x, p);
    }
}

int main() {
    
    int T;
    scanf("%d", &T);
    
    while(T--) {
        
        int n, m;
        scanf("%d %d", &n, &m);
        
        vector<int> position(n);
        
        position[0] = 0;
        Treap root = one(0);
        
        for(int i = 1; i < n; ++i) {
            root = insert(root, i);
            position[i] = i;
        }
        
        int id = -1;
        
        for(int i = 0; i < m; ++i) {
            int pos; scanf("%d", &pos); pos--;
            int x = position[pos];
            int ans = computePosition(root, x, 0);
            
            if(i > 0) printf(" ");
            printf("%d", ans);
            
            root = erase(root, x);
            x = id--;
            position[pos] = x;
            root = insert(root, x);
        }
        printf("\n");
        
        for(int i = 0; i < n; ++i) {
            root = erase(root, position[i]);
        }
    }
    
    return 0;
}
