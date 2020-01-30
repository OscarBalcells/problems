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
const int oo = 1e8+7;

int n;
vector<ll> h, beauty;
vector<ll> st, lazy;

/**
 * Build and init tree
 */
void build(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
        st[node] = 0; // Init value
		return;
	}
	
	build(node*2, a, (a+b)/2); // Init left child
	build(node*2+1, 1+(a+b)/2, b); // Init right child
	
	st[node] = max(st[node*2], st[node*2+1]); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update(int node, int a, int b, int i, int j, ll value) {
  
  	if(lazy[node] != 0) { // This node needs to be updated
   		st[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
            lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

   		lazy[node] = 0; // Reset it
  	}
  
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >= i && b <= j) { // Segment is fully within range
    		st[node] += value;

		if(a != b) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

    		return;
	}

	update(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	st[node] = max(st[node*2], st[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
ll query(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return -oo; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		st[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return st[node];

	ll q1 = query(node*2, a, (a+b)/2, i, j); // Query left child
	ll q2 = query(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	ll res = max(q1, q2); // Return final result
	
	return res;
}

int main() {
    
    scanf("%d",&n);
    
    h.resize(n);
    beauty.resize(n);
    
    for(ll& x : h) {
        scanf("%lld",&x);
        x--;
    }
    
    for(ll& x : beauty) {
        scanf("%lld", &x);
    }
    
    lazy.assign(4*n, 0);
    st.resize(4*n);
    
	build(1, 0, n-1); //(node, left, right)
    
    for(int flower = 0; flower < n; ++flower) {
        ll lis = (h[flower]-1 >= 0 ? query(1, 0, n-1, 0, h[flower]-1) : 0);
        update(1, 0, n-1, h[flower], h[flower], lis+beauty[flower]);
    }
    
    ll ans = 0;
    
    for(int i = 0; i < n; ++i) {
        ans = max(ans, query(1, 0, n-1, i, i));
    }
    
    cout << ans << endl;
    
    return 0;
}


