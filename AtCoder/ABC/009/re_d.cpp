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

// 方針としては, 漸化式の遷移は行列の演算で定義できることを利用して, 行列の累乗で高速化するというもの.
// 具体的には,
// Ak       Ak+1
// Ak-1     Ak
// Ak-2  -> Ak-1
// ...      ...
// A1       A2
// A0       A1
// という様な変換がしたい
// ここで, 本問では演算がANDとXORで定義されるので, AND(\times)とXOR(+)で半環をなす.
// この半環に置いて, ゼロ元は0, 単位元は-1である.
// (\because ゼロ元の定義より, 0^a = a^0 = a, また単位元は, (~0)&a = a&(~0) = aである)
// この様な演算を定義すると, 以下の様な行列を左からかければ良いことがわかる.
// c1 c2 c3 ... ck-1 ck
// ~0  0  0        0  0
//  0 ~0  0        0  0
//  ...................
//  0  0  0       ~0  0
// これは漸化式の定義から求められる.

// したがって, 上の行列をpとした時に, 行列pを左から(m-1)回かければ良い(\because m項目はm-1回かければよい(植木算の要領)
// ここで, 単純に(m-1)乗すると遅いので,
// 繰り返し二乗法を用いる
// すると, 行列の演算がO(K^3)
// 繰り返し二乗法でO(logM)なので,
// 全体でO(K^3logM)になる

int k,m;
vector< int > a(100);
vector< vector< int > > p(100,vector< int >(100));

int solve(int t){
	while(t>0){
		if(t & 1) {
			vector< int > tmp_a(100);
			REP(ki,k){
				REP(kj,k){
					tmp_a[ki] ^= p[ki][kj] & a[kj];
				}
			}
			a = tmp_a;
		}

		vector< vector< int > > tmp_p(100,vector< int >(100));
		REP(ki,k){
			REP(kj,k){
				REP(kk,k){
					tmp_p[ki][kj] ^= p[ki][kk] & p[kk][kj];
				}
			}
		}
		p = tmp_p;
		t >>= 1;
	}

	/*
	REP(i,k){
		debug(a[i]);
	}
	*/
	int res_ans = a[k-1];
	return res_ans;
}

signed main() {
  INIT;
	cin>>k>>m;
	RREP(i,k) cin>>a[i];
	REP(i,k)  cin>>p[0][i];
	// 単位元が~0(全ビットが1)であることに注意!
	REP(i,k-1) {
		p[i+1][i] = ~0;
	}
	/*
	REP(i,k){
		REP(j,k){
			cerr << p[i][j] << " ";
		}
		cerr << endl;
	}
	*/

	int ans = solve(m-1);
	OUT(ans)BR;
	
  return 0;
}
