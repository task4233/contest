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
	VAR(int,a,b,q);
	VEC(int,s,a);
	VEC(int,t,b);
	sort(ALL(s));
	sort(ALL(t));
	
	while(q--){
		VAR(int,x);

		int si = (lower_bound(ALL(s), x) - s.begin());
		int ti = (lower_bound(ALL(t), x) - t.begin());

		int ans=LINF;
		FOR(sj,-1,2){
			FOR(tj,-1,2){
				int sk = INF, tk=INF;
				if(0<=si+sj && si+sj<s.size()) sk=(s[si+sj]-x);
				if(0<=ti+tj && ti+tj<t.size()) tk=(t[ti+tj]-x);
				if(sk==INF || tk==INF) continue;
				if((0<= sk && 0<= tk) ||  (0 >= sk && 0 >= tk)) ans = min(ans,max(abs(sk),abs(tk)));
				if((sk<0 && tk<0) || (sk>=0 && tk>=0)) ans = min(ans,abs(sk)+abs(tk));
				else ans=min(ans,abs(sk)+abs(tk)+min(abs(sk),abs(tk)));
				// debug(sk);
				// debug(tk);
				// debug(ans);
			}
		}
		OUT(ans)BR;
	}
  
  return 0;
}
