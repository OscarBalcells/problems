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

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int nax = 2e5 + 5;
const ll oo = 1e18L + 7;

vector<ll> arr, st, lazy;
vector<ii> intervals[nax];

/**
 * Build and init tree
 */
void build(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
        st[node] = arr[a]; // Init value
		return;
	}
	
	build(node*2, a, (a+b)/2); // Init left child
	build(node*2+1, 1+(a+b)/2, b); // Init right child
	
	st[node] = min(st[node*2], st[node*2+1]); // Init root value
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

	st[node] = min(st[node*2], st[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
ll query(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) {
        //debug() << imie(a) imie(b) imie(i) imie(j);
        return oo; // Out of range
    }
    
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

	ll res = min(q1, q2); // Return final result
	
	return res;
}

int main() {
    
    int n, m;
    scanf("%d%d",&n,&m);
    
    n++;
    ll total = 0;
    
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        intervals[b].push_back(ii(a, c));
        total += c;
    }
    
    lazy.assign(4*n, 0);
    st.resize(4*n, 0);
    arr.assign(n, 0);
    
    build(1, 0, n-1);
    
    ll answer = 0;
    
    for(int i = 1; i <= n+1; ++i) {
        for(ii interval : intervals[i-1]) {
            update(1, 0, n-1, 0, interval.first-1, (ll)interval.second);
        }
        ll best = query(1, 0, n-1, 0, n-1);
        if(i == n+1) {
            answer = best;
            break;
        }
        update(1, 0, n-1, i, i, best);
    }
    
    printf("%lld\n", total-answer);
}
