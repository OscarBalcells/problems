#include <bits/stdc++.h>
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

// Keeps upper hull for maximums. 
// add lines with -m and -b and return -ans to 
// make this code working for minimums. 

typedef long long int ll;
typedef long double ld;
const ld inf = 1e18;

struct chtDynamic {  
	struct line {
		ll m, b, val; 
        ld x; 
        bool isQuery; 
		line(ll _m = 0, ll _b = 0) : 
			m(_m), b(_b), val(0), x(-inf), isQuery(false) {} 
		
		ll eval(ll _x) const { return m * _x + b;	}
		bool parallel(const line &l) const { return m == l.m; }
		ld intersect(const line &l) const {
			return parallel(l) ? inf : 1.0 * (l.b - b) / (m - l.m);
		}
		bool operator < (const line &l) const {
			if(l.isQuery) return x < l.val;
			else return m < l.m; 
		}
	};

	set<line> hull; 
	typedef set<line> :: iterator iter; 

	bool cPrev(iter it) { return it != hull.begin(); }
	bool cNext(iter it) { return it != hull.end() && next(it) != hull.end(); }

	bool bad(const line &l1, const line &l2, const line &l3) {
		return l1.intersect(l3) <= l1.intersect(l2); 
	}
	bool bad(iter it) {
		return cPrev(it) && cNext(it) && bad(*prev(it), *it, *next(it));
	}

	iter update(iter it) {
		if(!cPrev(it)) return it; 
		ld x = it -> intersect(*prev(it));
		line tmp(*it); tmp.x = x;
		it = hull.erase(it); 
		return hull.insert(it, tmp);
	}

	void addLine(ll m, ll b) { 
		line l(m, b); 
		iter it = hull.lower_bound(l); 
		if(it != hull.end() && l.parallel(*it)) {
			if(it -> b < b) it = hull.erase(it); 
			else return;
		}

		it = hull.insert(it, l); 
		if(bad(it)) return (void) hull.erase(it);

		while(cPrev(it) && bad(prev(it))) hull.erase(prev(it));
		while(cNext(it) && bad(next(it))) hull.erase(next(it));

		it = update(it);
		if(cPrev(it)) update(prev(it));
		if(cNext(it)) update(next(it));
	}

	ll query(ll x) const { 
		if(hull.empty()) return -inf;
		line q; q.val = x, q.isQuery = 1;
		iter it = --hull.lower_bound(q);
		return it -> eval(x);
	}
} ds;

int main() {
    
    int n;
    scanf("%d", &n);
    
    ll c;
    scanf("%lld", &c);
    
    vector<ll> heights(n);
    for(ll& x: heights) {
        scanf("%lld", &x);
    }
    
    vector<ll> dp(n, -1);
    dp[0] = 0;
    
    ds.addLine(-(-2ll*heights[0]), -(c+(heights[0]*heights[0])));
    
    for(int i = 1; i < n; ++i) {
        dp[i] = -ds.query(heights[i]) + (heights[i]*heights[i]);
        if(i < n-1) ds.addLine(-(-2ll*heights[i]), -(dp[i]+c+(heights[i]*heights[i])));
    }
    
    debug() << imie(dp);
    
    printf("%lld\n", dp[n-1]);
    
    return 0;
}
