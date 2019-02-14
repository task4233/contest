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

// n種類の料理
// (i番目の料理の個数, コスト) = (a_i, c_i)
// m人の顧客
// t_j番目の種類料理をd_j個を食す
// i+1番目の顧客はi番目の顧客がサービスを受けた後に来る
// i番目の種類の料理がr_i個が余っている(r_i = a_i)
// 顧客がi番目の料理を注文すると, 次の原則が処理
//
// ri > 0
// i番目の種類を1つ頼み, c_iのコストを支払う
// その後, --riとする
// otherwise
// 顧客は提供可能で, 最も安い品を1つ提供される
// 最も安い品が複数ある場合は, 最小のindexを持つものが採用
// その後, その種類の個数を-1する
// 完全に品がなくなると, 顧客は帰る
// この場合, コストは0
// d_j個の料理がだされた後に顧客が立ち去らない場合, コストはその合計になる

// n(料理の種類),m(顧客の数) < 1e5
// a_i(i種類目の料理の数) < 10^7
// c_i(上のコスト) < 10^6
// t_j(j番目の人が頼む料理の種類) < n
// d_j(j番目の人が頼む料理の数) < 10^7

// j行目にj番目の顧客のコストをprint

struct Data {
	int id, cost, num;
};

signed main() {
  INIT;
	VAR(int, n, m);
	VEC(int, a, n);  // num
	VEC(int, c, n);  // cost
	vector< Data > d(n);
	// f: num, s: cost
	REP(i, n) {
		d[i] = (Data){i, c[i], a[i]};
	}
	sort(ALL(d), [](const Data &d1, const Data &d2){
			if (d1.cost == d2.cost) return d1.id < d2.id;
			return d1.cost < d2.cost;
	});

	vector< int > rship(n);
	REP(i, n) {
		rship[d[i].id] = i;
	}

	int last = 0;
	while(m--) {
		VAR(int, t, dj);
		int id = rship[t-1];
		int cost = 0;
		if (d[id].num >= dj) {
			cost = d[id].cost * dj;
			d[id].num -= dj;
			//cout << "ok" << endl;
			OUT(cost)BR;
			continue;
		}
		
		// d[id].num < dj
		cost += d[id].cost * min(dj, d[id].num);
		dj -= d[id].num;
		d[id].num = 0;
		/*
		debug(dj);
		REP(i, n) {
			OUT(d[i].cost)SP;
		}
		BR;
		REP(i, n) {
			OUT(d[i].num)SP;
		}
		BR;
		*/
		while (dj > 0){
			FOR(i, last, n){
				/*
				debug(i);
				debug(dj);
				debug(d[i].cost);
				debug(d[i].num);
				*/
				if (dj == 0) break;
				last = max(last, i);
				if (d[i].num == 0) continue;
				//d[last].num > 0
				cost += d[i].cost * min(dj, d[i].num);
				if (dj >= d[i].num) {
					dj -= d[i].num;
					d[i].num = 0;
				} else {
					d[i].num -= dj;
					dj = 0;
				}
			}
			if (dj > 0) {
				cost = 0;
				break;
			}
		}
		OUT(cost)BR;
	}
  
  return 0;
}
