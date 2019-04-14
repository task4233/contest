#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int64, int64>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 3e5 + 1;

// init/input
#define int int64
#define INIT ios::sync_with_stdio(false);cin.tie(0);
#define VAR(type, ...) type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T &t) {cin>>t;}
template<typename First, typename...Rest> void MACRO_VAR_Scan(First &first, Rest&...rest) {cin>>first;MACRO_VAR_Scan(rest...);}
#define VEC(type, c, n) vector<type> c(n);for(auto &&i:c)cin>>i;

// out
#define OUT(dist) cout<<(dist);
#define FOUT(n, dist) cout<<fixed<<setprecision(n)<<(dist);
#define SP cout<<" ";
#define BR cout<<endl;
#define zero(n) cout<<setfill('0')<<right<<setw(n)
#define debug(x) cerr<<#x<<":"<< (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

signed main() {
  INIT;
	VAR(int,n);
	VEC(int, smp, 3);
	sort(ALL(smp));
	VEC(int,l,n);

	int ans = INF;
	FOR(i,1,n-1){
		FOR(j,1,n-i){
			FOR(k,1,n-i-j+1){
				vector<int> par;
				REP(ii,i) par.push_back(0);
				REP(jj,j) par.push_back(1);
				REP(kk,k) par.push_back(2);
				REP(ll,n-i-j-k) par.push_back(3);

				do {
					int tmp=0;
					vector<int>a(3,0);
					REP(i,par.size()){
						if(par[i] == 0) {
							if(a[0]>0) tmp+=10;
							a[0]+=l[i];
						}
						if(par[i] == 1) {
							if(a[1]>0) tmp+=10;
							a[1]+=l[i];
						}
						if(par[i] == 2) {
							if(a[2]>0) tmp+=10;
							a[2]+=l[i];
						}
					}
					
					sort(ALL(a));
					REP(i,3){
						tmp += abs(a[i]-smp[i]);
						//debug(a[i]);
						//debug(tmp);
					}
					ans = min(ans,tmp);
					
				}while(next_permutation(ALL(par)));
			}
		}
	}
	OUT(ans)BR;
	
  return 0;
}
