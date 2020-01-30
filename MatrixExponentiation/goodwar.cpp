#include<bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ve vector
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define for1(i,n) for(int i=1;i<=(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define pb push_back
#define emp emplace_back
#define input(v) for(int i=0;i<n;i++) cin>>v[i];
#define sz(a) (int)(a.size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int inf=(int)2e9;
const long long md=1000000007;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

ll modM=md;

vvi mul(vvi a,vvi b){
	int m1=a.size(),n1=a[0].size(),n2=b[0].size();
	vvi ans(m1,vi(n2));
	forn(i,m1){
		forn(j,n2){
			ll cur=0;
			forn(k,n1) cur=(cur+(a[i][k]*1ll*b[k][j])%modM)%modM;
			ans[i][j]=cur;
		}
	}
	return ans;
}


vvi power(vvi a,ll p){
	vvi cur=a;int n=sz(a);
	vvi ans(n,vi(n,0));
	forn(i,n) ans[i][i]=1;
	while(p){
		if(p%2) ans=mul(ans,cur);
		p/=2;
		cur=mul(cur,cur);
	}
	return ans;
}


int main(){
	IOS
	int t,n,m;cin>>t;
	while(t--){
		cin>>n>>m;
		vvi To(m,vi(m,0));
		forn(i,m){
				if(i+1<m) To[i][i+1]=1;
				if(i-1>=0) To[i][i-1]=1;
		}
		vvi Te(To);
		forn(i,m) Te[i][i]=1;
		vvi T=mul(Te,To);
		vvi st(m,vi(1,1));
		vvi fin=mul(power(T,(n-1)/2),st);
		if(n%2==0){
			fin=mul(To,fin);
		}
		ll ans=0;
		forn(i,m) ans=(ans+fin[i][0])%md;
		cout<<n<<" "<<m<<" "<<ans<<"\n";
	}
}
