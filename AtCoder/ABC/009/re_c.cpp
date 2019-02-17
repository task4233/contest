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

// N文字のSをK文字の編集で辞書式最小にしたい
// 1 \leq N \leq 100
//
// 7 2
// atcoder
// aを先頭にできるか?
// 0回の操作で可能
// cを2文字目にできるか?
// できる
// 1回の操作で可能
// actoder
// ここで, 変化した文字が2つなので終わり

// 7 7
// atcoder
// atcoder 0
// actoder 2
// acdoter 3
// acdeotr 5
// acdeort 6

// 10 3
// helloworld
// delloworlh 2
// dehloworll 3

// 方針
// 文字列を1度全て確認し, 何の文字がいくつ出てくるのかをメモする
// 前から並べ, その文字をそこに並べた時に, 文字の差がK以下になっているか確認する
// 問題なければそれでおk
// 問題があれば, 次の文字で対応できるか考える

signed main() {
  INIT;
	VAR(int, n, k);
	VAR(string, s);

	vector< int > memo(s.size());
	
	map<char,int> mp;
	REP(si,s.size()){
		mp[s[si]]++;
	}

	string ans = "";
	
	auto is_ok = [&](char optimum_char){
		
		int now = ans.size();
		int res_diff = 0;
		REP(i, ans.size()){
			if(s[i] != ans[i]) ++res_diff;
		}
		

		if(optimum_char!=s[now]) {
			map<char,int> mmp=mp;
			++res_diff;
			//debug(ans + optimum_char);
			//debug(res_diff);
			
			mmp[optimum_char]--;
			FOR(i, now+1, s.size()){
				if(mmp[s[i]] < 1) {
					++res_diff;
					//debug(s[i]);
				}
				mmp[s[i]]--;
			}
			// debug(res_diff);
		}

		return res_diff<=k;
	};

	// 0-s.size()
	REP(si,s.size()){
		EACH(mi,mp) {
			if (mi.second <= 0) continue;
			char optimum_char = mi.first;

			// ans+cにしておk?
			if (is_ok(optimum_char)) {	
				ans.push_back(optimum_char);
				mp[optimum_char]--;
				if (mp[optimum_char]==0) mp.erase(optimum_char);
				break;
			}
		}
	}

	OUT(ans)BR;
  
  return 0;
}
