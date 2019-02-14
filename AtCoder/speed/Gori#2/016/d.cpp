#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>
#include <cfloat>
#include <set>
#include <map>

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

// 0を起点に幅優先?
// 幅優先しながら, 0(2)なら2倍, 1(b)ならそのままで伝播

int d[MAX_N], d2[MAX_N];
vector<int> e[MAX_N];

signed main() {
  INIT;
	VAR(int,n);
	REP(i,n-1) {VAR(int,f,t); e[f-1].push_back(t-1);e[t-1].push_back(f-1);}

	int ans1=0,ans2=0;
	
	queue<PAIR> q;
	q.push({0,0});
	d[0] = 1;
	while(!q.empty()){
		int fr,clr;
		tie(fr,clr)= q.front();q.pop();

		
		
		EACH(ei, e[fr]){
			if (clr==0) {
				(d[ei] *= d[fr] * 2) %= MOD;
				q.push({ei,0LL});
				q.push({ei,1LL});
			} else {
				(d[ei] *= d[fr]) %= MOD;
				q.push({ei,0LL});
			}
			ans1 = max(ans1,d[ei]);
		}
	}

	queue<PAIR> q2;
	q2.push({0,1});
	d2[0] = 1;
	while(!q2.empty()){
		int fr,clr;
		tie(fr,clr)= q2.front();q2.pop();
		if (d2[fr] > 0) continue;
		
		EACH(ei, e[fr]){
			if (clr==0) {
				(d2[ei] *= d2[fr] * 2) %= MOD;
				q2.push({ei,0LL});
				q2.push({ei,1LL});
			} else {
				(d2[ei] *= d2[fr]) %= MOD;
				q2.push({ei,0LL});
			}
			ans2 = max(ans2,d2[ei]);
		}
	}

	debug(ans1);
	debug(ans2);
	cout << (ans1 + ans2)%MOD << endl;
	
	
  return 0;
}
