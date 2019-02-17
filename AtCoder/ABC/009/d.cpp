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

// 計算するだけでは?
// M項目が知りたいならば, M-1項目が知れれば良いのでメモ化再帰で行けないですか？
// ダメでした(\because 1 \leq M \leq 10^9)
// 規則性を見つけるしかないね
// いや, これよく考えたらk項しか使われてないから, 保持する必要があるのはk項のみじゃん
// (余裕を持たせて200項くらいでもおk)
// 再帰でやると後ろからなのでメモリが足りない.
// したがって, 前から埋める必要がある.
// それでも高々1e9回呼び出されるのでNG
// やはり規則性を見つけるしかない
//
// 解説見ました
// 行列累乗を使う
// 以下の行列を左からかけると, 漸化式が1進む
// c1 c2 c3 ...ck-1 ck
//  1  0  0 ...  0  0
//  0  1  0 ...  0  0
//  .................
//  0  0  0 ...  1  0
// さらに, これを左からM回かけることと遷移をM回進めるのは同義
// したがって,先ほどの行列をPとすると,
// P^M * Aを求めれば良い
// しかし, 単にM乗するだけだと高速化できない(M回かけることになるので)
// そこで, 繰り返し2乗法の様なものを使う
// すると, O(logM)に落ちる.
// 行列の計算1回には, 計算結果の要素1つにつきO(K)かかるので, 1度の演算でO(K^3)かかる
// したがって, M回の遷移を計算するには, O(K^3logM)で解ける
// 行列つおい......

int k,m;
vector< int > a(200);
vector< vector< int > > p(100, vector< int >(100));

void power_2(){
	vector< vector< int > > res(100, vector< int >(100));
	REP(ki,k){
		REP(kj,k){
			REP(kk,k){
				res[ki][kj] ^= p[ki][kk] & p[kk][kj];
			}
		}
	}
	p = res;
}

void calc(){
	// int res[100];
	vector< int > res(100);
	REP(ki,k){
		REP(kj,k){
			res[ki] ^= p[ki][kj] & a[kj];
		}
	}
	a = res;
}

void power(int t){
	while(t>0){
		if (t & 1) calc();
		power_2();
		t >>= 1;
	}
}

int solve(int t){
	// まず, 左からかける行列Pを作る
	FOR(hi,1,k){
		REP(wi,k-1){
			if (wi+1==hi) 
				p[hi][wi] = -1;
		}
	}
	// 次に, 左からM回かける
	power(t);

	int ans = a[k-1];
	return ans;
}

signed main() {
  INIT;
	cin>>k>>m;
	RREP(i,k) cin>>a[i];
	REP(i,k) cin>>p[0][i];
	
	if (m<=k){
		OUT(a[k-m])BR;
		return 0;
	}
	
	int ans = solve(m-1);
	OUT(ans)BR;

	REP(i,k){
		debug(a[i]);
	}
	
  return 0;
}
