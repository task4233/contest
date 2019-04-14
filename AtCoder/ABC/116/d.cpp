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
#define RALL(a) (a).rbegin(), (a).rend()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

// n個の寿司があり, i個目の種類はt_i, 美味しさはd_iである
// この中からk個選び, 美味しさd_iの挿話とt_iの種類数の2乗の話を最大化したい
// 最大値を求めよ

// 選ぶ種類数をcとすると,
// c個選び, 残りをその種類の中でk-c個選んだ時が最適である
// cは1..(種類数の最大値)のforループ(高々O(N))
// 残りの要素は, 大きい方からk-c個選べば良い
// (大きい要素じゅんに並べるpriority_queueが有効)

signed main() {
  INIT;
	VAR(int,n,k);
	map< int,vector<int> > ds; 
	REP(i,n) {
		VAR(int,t,d);
	  ds[t].push_back(d);
	}

  // 種類ごとの最大値と, 種類ごとの残りの要素を別に保管
  vector<int> mxs, others;
	EACH(di,ds){
		vector<int> nums = di.second;
		sort(ALL(nums));
		reverse(ALL(nums));
		mxs.push_back(nums[0]);
		FOR(i,1,nums.size()) {
			others.push_back(nums[i]);
		}
	}

	sort(ALL(mxs));
	reverse(ALL(mxs));
	sort(ALL(others));
	reverse(ALL(others));
	EACH(mi,mxs){
		debug(mi);
	}
	EACH(oi, others){
		debug(oi);
	}

	vector<int> mxs_sm(n+1,0), others_sm(n+1,0);
	REP(i,mxs.size()){
		mxs_sm[i+1] = mxs_sm[i] + mxs[i];
	}
	REP(i,others.size()){
		others_sm[i+1] = others_sm[i] + others[i];
	}
	EACH(mi,mxs_sm){
		debug(mi);
	}
	EACH(oi, others_sm){
		debug(oi);
	}

	int c = min((int)ds.size(), k);
	debug(c);
	int ans = 0;
	FOR(i,1,c+1){
		int res = mxs_sm[i] + others_sm[k-i] + i*i;
		debug(mxs_sm[i]);
		debug(others_sm[k-1]);
		debug(i);
		debug(res);
		ans = max(ans,res);
	}
	OUT(ans)BR;
	
  return 0;
}
