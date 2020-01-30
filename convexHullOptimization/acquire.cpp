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

using lf = long double;
using ll = long long int;
const ll oo = 1e18L+7;
using ii = pair<int,int>;

#define width first
#define height second

vector<ll> M;
vector<ll> B;
int pointer; //pop_front with vector is very slow

bool bad(int l1,int l2,int l3)
{
	/*
	intersection(l1,l2) has x-coordinate (b1-b2)/(m2-m1)
	intersection(l1,l3) has x-coordinate (b1-b3)/(m3-m1)
	set the former greater than the latter, and cross-multiply to
	eliminate division
	*/
    
    //~ lf inter1 = (B[l3]-B[l2])/(M[l2]-M[l3]);
    //~ lf inter2 = (B[l3]-B[l1])/(M[l1]-M[l3]);
    //~ return inter2 <= inter1;
    
	return (B[l3]-B[l1])*(M[l1]-M[l2])<(B[l2]-B[l1])*(M[l1]-M[l3]);
}

//Adds a new line (with lowest slope) to the structure
void add(long long m,long long b)
{
	//First, let's add it to the end
	M.push_back(m);
	B.push_back(b);
    
	//If the penultimate is now made irrelevant between the antepenultimate
	//and the ultimate, remove it. Repeat as many times as necessary
	while (M.size()>=3 && bad(M.size()-3,M.size()-2,M.size()-1))
	{
		M.erase(M.end()-2); // we erase the irrelevant ones
		B.erase(B.end()-2); // same
	}
}

//Returns the minimum y-coordinate of any intersection between a given vertical
//line and the lower envelope
long long query(long long x)
{
	//If we removed what was the best line for the previous query, then the
	//newly inserted line is now the best for that query
	if (pointer>=(int)M.size())
		pointer=M.size()-1;
        
	//Any better line must be to the right, since query values are
	//non-decreasing
	while (pointer<(int)M.size()-1 && M[pointer+1]*x+B[pointer+1]<M[pointer]*x+B[pointer])
		pointer++;
        
	return M[pointer]*x+B[pointer];
}

int main() {
    int m;
    scanf("%d", &m);
    
    vector<ii> in(m);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &in[i].width, &in[i].height);
    }
    
    sort(in.rbegin(), in.rend());
    
    vector<ii> rect;
    int N = 0;
    int mheight = 0;
    
    for(int i = 0; i < m; ++i) {
        if(in[i].height <= mheight) {
            continue;
        } else {
            N++;
            rect.push_back(in[i]);
            mheight = in[i].height;
        }
    }

    long long cost = 0;
    pointer = 0;

	//initially, the best line could be any of the lines in the envelope,
	//that is, any line with index 0 or greater, so set pointer=0
    
	for (int i=0; i<N; i++) {
        add(rect[i].width, cost);
		cost=query(rect[i].height);
	}
    
	printf("%lld\n",cost);
	return 0;
}
